#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

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

  vector< int > accept;

  TrieNode() {
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
    if(nodes[node].accept.empty()) {
      nodes[node].accept.emplace_back(node);
    }
    //nodes[node].accept.push_back(id);
  }

  void update_child(int node, int child, int id) {
    //++nodes[node].exist;
  }

  int add(const string &str, int str_index, int node_index, int id) {
    if(str_index == str.size()) {
      update_direct(node_index, id);
      return node_index;
    } else {
      const int c = str[str_index] - margin;
      if(nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int) nodes.size();
        nodes.push_back(Node());
      }
      int idx = add(str, str_index + 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
      return idx;
    }
  }

  int add(const string &str, int id) {
    return add(str, 0, 0, id);
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
      correct[que.front()] += correct[now.nxt[FAIL]];
      que.pop();
      for(int i = 0; i < char_size; i++) {
        if(now.nxt[i] == -1) continue;
        int fail = now.nxt[FAIL];
        while(this->nodes[fail].nxt[i] == -1) fail = this->nodes[fail].nxt[FAIL];
        this->nodes[now.nxt[i]].nxt[FAIL] = this->nodes[fail].nxt[i];
        if(heavy) {
          auto &u = this->nodes[now.nxt[i]].accept;
          auto &v = this->nodes[this->nodes[fail].nxt[i]].accept;
          vector< int > accept;
          set_union(begin(u), end(u), begin(v), end(v), back_inserter(accept));
          u = accept;
        }
        que.emplace(now.nxt[i]);
      }

    }
  }

  map< int, int > match(const string &str, int now = 0) {
    map< int, int > result;
    for(auto &c : str) {
      while(this->nodes[now].nxt[c - margin] == -1) now = this->nodes[now].nxt[FAIL];
      now = this->nodes[now].nxt[c - margin];
      for(auto &v : this->nodes[now].accept) result[v] += 1;
    }
    return result;
  }

  pair< int, int > move(const char &c, int now) {
    int sum = 0;
    while(this->nodes[now].nxt[c - margin] == -1) now = this->nodes[now].nxt[FAIL];
    now = this->nodes[now].nxt[c - margin];
    sum += correct[now];
    return {sum, now};
  }
};

int main() {
  int N;
  cin >> N;
  Trie< 26, 'a' > trie;
  vector< int > idx(N);
  for(int i = 0; i < N; i++) {
    int t;
    cin >> t;
    if(t == 1) {
      string c;
      cin >> c;
      idx[i] = trie.add(c, i);
    } else {
      int j;
      cin >> j;
      --j;
      string c;
      cin >> c;
      idx[i] = trie.add(c, 0, idx[j], i);
    }
  }


  vector< vector< int > > be(trie.nodes.size());

  int M;
  cin >> M;
  AhoCorasick< 26, 'a' > aho;
  vector< int > qs(M);
  for(int i = 0; i < M; i++) {
    int k;
    string t;
    cin >> k >> t;
    --k;
    be[idx[k]].emplace_back(i);
    qs[i] = aho.add(t, i);
  }

  aho.build(true);
  vector< int > ans(M);
  vector< int > matched(404040);
  auto dfs = MFP([&](auto dfs, int node_index, int aho_index) -> void {
    auto &node = trie.nodes[node_index];
    for(auto &query : be[node_index]) ans[query] = matched[qs[query]];
    for(int i = 0; i < 26; i++) {
      if(node.nxt[i] == -1) continue;
      int nxt = aho.move(i + 'a', aho_index).second;
      for(auto &v : aho.nodes[nxt].accept) matched[v] += 1;
      dfs(node.nxt[i], nxt);
      for(auto &v : aho.nodes[nxt].accept) matched[v] -= 1;
    }
  });
  dfs(0, 0);
  for(auto &p : ans) cout << p << "\n";
}