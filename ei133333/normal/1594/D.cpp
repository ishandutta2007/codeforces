#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = (int) (1e9 + 7);
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
  for(T &in: v) is >> in;
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
  for(auto &e: t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  explicit FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

void beet() {
  int N, M;
  cin >> N >> M;
  vector< vector< pair< int, int > > > g(N), rg(N);
  for(int i = 0; i < M; i++) {
    int s, t;
    string op;
    cin >> s >> t >> op;
    --s, --t;
    bool is_imposter = op[0] == 'i';
    g[s].emplace_back(t, is_imposter);
    g[t].emplace_back(s, is_imposter);
  }
  vector< int > used1(N, -1), used2(N, -1);
  int ret = 0;
  for(int i = 0; i < N; i++) {
    if(~used1[i]) {
      continue;
    }
    // i
    int cp = -1;
    queue< pair< int, int > > que;
    {
      que.emplace(i, true);
      used1[i] = true;
      bool check = true;
      int cnt = 0;
      while(not que.empty()) {
        auto[p, t] = que.front();
        que.pop();
        cnt += t;
        for(auto &e: g[p]) {
          bool nxt = e.second ^ t;
          if(used1[e.first] == -1) {
            used1[e.first] = nxt;
            que.emplace(e.first, nxt);
          }
          if(used1[e.first] != nxt) {
            check = false;
          }
        }
      }
      if(check) {
        chmax(cp, cnt);
      }
    }
    // i
    {
      que.emplace(i, false);
      used2[i] = false;
      bool check = true;
      int cnt = 0;
      while(not que.empty()) {
        auto[p, t] = que.front();
        que.pop();
        cnt += t;
        for(auto &e: g[p]) {
          bool nxt = e.second ^ t;
          if(used2[e.first] == -1) {
            used2[e.first] = nxt;
            que.emplace(e.first, nxt);
          }
          if(used2[e.first] != nxt) {
            check = false;
          }
        }
      }
      if(check) {
        chmax(cp, cnt);
      }
    }
    if(cp == -1) {
      cout << -1 << "\n";
      return;
    }
    ret += cp;
  }
  cout << ret << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    beet();
  }
}