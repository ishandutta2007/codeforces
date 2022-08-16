#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

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

template< int char_size >
struct TrieNode {
  int nxt[char_size + 1];

  int exist;
  int accept;

  TrieNode() : exist(0), accept(0) {
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
    nodes[node].accept |= id;
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

  int size() const {
    return (nodes[0].exist);
  }

  int nodesize() const {
    return ((int) nodes.size());
  }
};

template< int char_size, int margin >
struct AhoCorasick : Trie< char_size, margin > {
  using TRIE = Trie< char_size, margin >;
  static const int FAIL = char_size;

  AhoCorasick() : TRIE() {}

  void build(bool heavy = true) {

    queue< int > que;
    for(int i = 0; i <= char_size; i++) {
      if(~TRIE::nodes[0].nxt[i]) {
        TRIE::nodes[TRIE::nodes[0].nxt[i]].nxt[FAIL] = 0;
        que.emplace(TRIE::nodes[0].nxt[i]);
      } else {
        TRIE::nodes[0].nxt[i] = 0;
      }
    }
    while(!que.empty()) {
      TrieNode< char_size > &now = TRIE::nodes[que.front()];
       que.pop();
      for(int i = 0; i < char_size; i++) {
        if(now.nxt[i] == -1) continue;
        int fail = now.nxt[FAIL];
        while(TRIE::nodes[fail].nxt[i] == -1) fail = TRIE::nodes[fail].nxt[FAIL];
        TRIE::nodes[now.nxt[i]].nxt[FAIL] = TRIE::nodes[fail].nxt[i];
        if(heavy) {
          auto &u = TRIE::nodes[now.nxt[i]].accept;
          auto &v = TRIE::nodes[TRIE::nodes[fail].nxt[i]].accept;
          // vector< int > accept;
          u |= v;
          //set_union(begin(u), end(u), begin(v), end(v), back_inserter(accept));
          //u = accept;
        }
        que.emplace(now.nxt[i]);
      }

    }
  }


  int move(const char &c, int &now) {
    while(TRIE::nodes[now].nxt[c - margin] == -1) now = TRIE::nodes[now].nxt[FAIL];
    now = TRIE::nodes[now].nxt[c - margin];
    return TRIE::nodes[now].accept;
  }
};

int main() {
  string S, A, B;
  cin >> S >> A >> B;
  AhoCorasick< 26, 'a' > aho;
  aho.add(A, 1);
  aho.add(B, 2);
  aho.build();
  auto dp = make_v< int >(1001, 105);
  fill_v(dp, inf);
  dp[0][0] = 0;
  for(auto &c : S) {
    auto dp2 = make_v< int >(1001, 105);
    fill_v(dp2, inf);
    for(int i = 0; i < 1001; i++) {
      for(int j = 0; j < 105; j++) {
        if(dp[i][j] == inf) continue;
        for(char k = 'a'; k <= 'z'; k++) {
          if(c == '*' || c == k) {
            int cur = j;
            int val = aho.move(k, cur);
            int x = i;
            if(val & 1) ++x;
            int y = dp[i][j];
            if(val & 2) ++y;
            chmin(dp2[x][cur], y);
          }
        }
      }
    }
    dp.swap(dp2);
  }

  int64 ret = -infll;
  for(int i = 0; i < 1001; i++) {
    for(int j = 0; j < 105; j++) {
      chmax(ret, (int64) i - dp[i][j]);
    }
  }
  cout << ret << endl;
}