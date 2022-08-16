#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
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

constexpr int vy[] = {-1, 1, 0, 0};
constexpr int vx[] = {0, 0, -1, 1};

void beet() {
  int h, w;
  cin >> h >> w;
  vector< string > s(h);
  cin >> s;
  auto is_in = [&](int y, int x) {
    return 0 <= y and y < h and 0 <= x and x < w;
  };
  queue< pair< int, int > > que;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(s[i][j] == 'L') {
        for(int k = 0; k < 4; k++) {
          int ni = i + vy[k];
          int nj = j + vx[k];
          if(not is_in(ni, nj)) continue;
          if(s[ni][nj] != '.') continue;
          int candidate = 0;
          for(int l = 0; l < 4; l++) {
            int nni = ni + vy[l];
            int nnj = nj + vx[l];
            if(not is_in(nni, nnj)) continue;
            candidate += s[nni][nnj] == '.';
          }
          if(candidate <= 1) {
            s[ni][nj] = '+';
            que.emplace(ni, nj);
          }
        }
      }
    }
  }
  while(not que.empty()) {
    auto[i, j]=que.front();
    que.pop();
    for(int k = 0; k < 4; k++) {
      int ni = i + vy[k];
      int nj = j + vx[k];
      if(not is_in(ni, nj)) continue;
      if(s[ni][nj] != '.') continue;
      int candidate = 0;
      for(int l = 0; l < 4; l++) {
        int nni = ni + vy[l];
        int nnj = nj + vx[l];
        if(not is_in(nni, nnj)) continue;
        candidate += s[nni][nnj] == '.';
      }
      if(candidate <= 1) {
        s[ni][nj] = '+';
        que.emplace(ni, nj);
      }
    }
  }
  for(auto& t : s) cout << t << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) beet();
}