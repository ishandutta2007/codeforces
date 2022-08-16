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

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};


int main() {
  int N, M;
  cin >> N >> M;
  auto v = make_v< string >(N);
  cin >> v;

  UnionFind uf(N * M);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(v[i][j] == '.') {
        if(i && v[i - 1][j] == '.') uf.unite(i * M + j - M, i * M + j);
        if(j && v[i][j - 1] == '.') uf.unite(i * M + j - 1, i * M + j);
      }
    }
  }

  const int vy[] = {1, 0, -1, 0};
  const int vx[] = {0, 1, 0, -1};

  for(int i = 0; i < N; i++) {
    string ans;
    for(int j = 0; j < M; j++) {
      if(v[i][j] == '.') {
        ans += ".";
      } else {
        map< int, int > mp;
        for(int k = 0; k < 4; k++) {
          int ny = vy[k] + i, nx = vx[k] + j;
          if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
          if(v[ny][nx] == '.') mp[uf.find(ny * M + nx)] = uf.size(ny * M + nx);
        }
        int add = 1;
        for(auto& p : mp) add += p.second;
        add %= 10;
        ans += (char)(add + '0');
      }
    }
    cout << ans << endl;
  }
}