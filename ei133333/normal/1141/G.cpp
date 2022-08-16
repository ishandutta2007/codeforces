#include<bits/stdc++.h>

using namespace std;


using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

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

int N, K;
vector< pair< int, int > > g[200000];
bool ok[200000];
int ans[200000];

void dfs(int idx, int par = -1, int color = -1) {
  if(ok[idx]) {
    color = 0;
    for(auto &e : g[idx]) {
      if(e.first == par) continue;
      ans[e.second] = color;
      dfs(e.first, idx, color);
    }
  } else {
    int used = 0;
    for(auto &e : g[idx]) {
      if(e.first == par) continue;
      if(used == color) ++used;
      ans[e.second] = used;
      dfs(e.first, idx, used);
      ++used;
    }
  }
}


int main() {

  cin >> N >> K;
  K = N - K;
  for(int i = 1; i < N; i++) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    g[l].emplace_back(r, i);
    g[r].emplace_back(l, i);
  }
  vector< pair< int, int > > sz;
  for(int i = 0; i < N; i++) {
    sz.emplace_back(g[i].size(), i);
  }
  sort(sz.begin(), sz.end());
  cout << sz[K - 1].first << endl;
  for(int i = K; i < N; i++) ok[sz[i].second] = true;
  dfs(0, -1);
  for(int i = 1; i < N; i++) cout << ans[i] + 1 << " ";
  cout << endl;
}