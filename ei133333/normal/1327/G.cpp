#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

template< int char_size >
struct TrieNode {
  int nxt[char_size];

  int exist;
  vector< int > accept;

  TrieNode() : exist(0) {
    memset(nxt, -1, sizeof(nxt));
  }
};

template< int char_size, int margin >
struct Trie {
  using Node = TrieNode< char_size >;

  vector< Node > nodes;
  int root;

  Trie() : root(0) {
    nodes.push_back(Node());
  }

  void update_direct(int node, int id) {
    nodes[node].accept.push_back(id);
  }

  void update_child(int node, int child, int id) {
    ++nodes[node].exist;
  }

  void add(const string &str, int str_index, int node_index, int id) {
    if(str_index == str.size()) {
      update_direct(node_index, id);
    } else {
      const int c = str[str_index] - margin;
      if(nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int) nodes.size();
        nodes.push_back(Node());
      }
      add(str, str_index + 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(const string &str, int id) {
    add(str, 0, 0, id);
  }

  void add(const string &str) {
    add(str, nodes[0].exist);
  }

  void query(const string &str, const function< void(int) > &f, int str_index, int node_index) {
    for(auto &idx : nodes[node_index].accept) f(idx);
    if(str_index == str.size()) {
      return;
    } else {
      const int c = str[str_index] - margin;
      if(nodes[node_index].nxt[c] == -1) return;
      query(str, f, str_index + 1, nodes[node_index].nxt[c]);
    }
  }

  void query(const string &str, const function< void(int) > &f) {
    query(str, f, 0, 0);
  }

  int count() const {
    return (nodes[0].exist);
  }

  int size() const {
    return ((int) nodes.size());
  }
};

template< int char_size, int margin >
struct AhoCorasick : Trie< char_size + 1, margin > {
  using Trie< char_size + 1, margin >::Trie;

  const int FAIL = char_size;
  vector< int > correct;

  void build(bool heavy = true) {
    correct.resize(this->size());
    for(int i = 0; i < this->size(); i++) {
      correct[i] = (int) this->nodes[i].accept.size();
    }
    queue< int > que;
    for(int i = 0; i <= char_size; i++) {
      if(~this->nodes[0].nxt[i]) {
        this->nodes[this->nodes[0].nxt[i]].nxt[FAIL] = 0;
        que.emplace(this->nodes[0].nxt[i]);
      } else {
        this->nodes[0].nxt[i] = 0;
      }
    }
    while(!que.empty()) {
      auto &now = this->nodes[que.front()];
      int fail = now.nxt[FAIL];
      correct[que.front()] += correct[fail];
      que.pop();
      for(int i = 0; i < char_size; i++) {
        if(~now.nxt[i]) {
          this->nodes[now.nxt[i]].nxt[FAIL] = this->nodes[fail].nxt[i];
          if(heavy) {
            auto &u = this->nodes[now.nxt[i]].accept;
            auto &v = this->nodes[this->nodes[fail].nxt[i]].accept;
            vector< int > accept;
            set_union(begin(u), end(u), begin(v), end(v), back_inserter(accept));
            u = accept;
          }
          que.emplace(now.nxt[i]);
        } else {
          now.nxt[i] = this->nodes[fail].nxt[i];
        }
      }
    }
  }

  map< int, int > match(const string &str, int now = 0) {
    map< int, int > result;
    for(auto &c : str) {
      now = this->nodes[now].nxt[c - margin];
      for(auto &v : this->nodes[now].accept) result[v] += 1;
    }
    return result;
  }

  pair< int64_t, int > move(const char &c, int now = 0) {
    now = this->nodes[now].nxt[c - margin];
    return {correct[now], now};
  }

  pair< int64_t, int > move(const string &str, int now = 0) {
    int64_t sum = 0;
    for(auto &c : str) {
      auto nxt = move(c, now);
      sum += nxt.first;
      now = nxt.second;
    }
    return {sum, now};
  }
};


int main() {
  int K;
  cin >> K;
  vector< string > T(K);
  vector< int > C(K);
  AhoCorasick< 14, 'a' > aho;
  for(int i = 0; i < K; i++) {
    cin >> T[i] >> C[i];
    aho.add(T[i]);
  }
  aho.build();
  vector< int64 > weight(aho.size() + 3);
  for(int i = 0; i < aho.size(); i++) {
    for(auto &p : aho.nodes[i].accept) weight[i] += C[p];
  }
  string S;
  cin >> S;

  vector< string > strs;
  int qs = 0;
  for(auto &c : S) {
    qs += c == '?';
    if(strs.empty() || (c == '?' && !strs.back().empty())) strs.emplace_back();
    strs.back() += c;
    if(c == '?') strs.emplace_back();
  }
  auto dp = make_v< int64 >(1 << 14, aho.size());
  fill_v(dp, -infll);
  dp[0][0] = 0;
  for(int i = 0; i < strs.size(); i++) { // 
    if(strs[i][0] == '?') {
      auto dp2 = make_v< int64 >(1 << 14, aho.size());
      fill_v(dp2, -infll);
      for(int j = 0; j < 1 << 14; j++) {
        for(int k = 0; k < aho.size(); k++) {
          if(dp[j][k] == -infll) continue;
          for(int n = 'a'; n <= 'n'; n++) {
            if((j >> (n - 'a')) & 1) continue;
            auto nt = aho.move(n, k).second;
            chmax(dp2[j | (1 << (n - 'a'))][nt], dp[j][k] + weight[nt]);
          }
        }
      }
      dp.swap(dp2);
    } else {
      auto to = make_v< int >(aho.size());
      auto add = make_v< int64 >(aho.size());
      for(int j = 0; j < aho.size(); j++) {
        int cur = j;
        for(auto &k : strs[i]) {
          cur = aho.move(k, cur).second;
          add[j] += weight[cur];
        }
        to[j] = cur;
      }
      auto dp2 = make_v< int64 >(1 << 14, aho.size());
      fill_v(dp2, -infll);
      for(int j = 0; j < 1 << 14; j++) {
        for(int k = 0; k < aho.size(); k++) {
          if(dp[j][k] == -infll) continue;
          chmax(dp2[j][to[k]], dp[j][k] + add[k]);
        }
      }
      dp.swap(dp2);
    }
  }
  int64 ret = -infll;
  for(int i = 0; i < 1 << 14; i++) {
    for(auto& x : dp[i]) chmax(ret, x);
  }
  cout << ret << "\n";
}