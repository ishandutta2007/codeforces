#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;


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

const int vx[] = {1, 0, -1, 0};
const int vy[] = {0, 1, 0, -1};

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  set< int > dameYoko[100000];
  set< int > dameTate[100000];
  for(int i = 0; i < K; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    dameYoko[a].emplace(b);
    dameTate[b].emplace(a);
  }
  for(int i = 0; i < 100000; i++) {
    dameYoko[i].emplace(-inf);
    dameYoko[i].emplace(inf);
    dameTate[i].emplace(-inf);
    dameTate[i].emplace(inf);
  }

  int d = 0;
  int A = 0, B = 0, C = W - 1, D = H - 1;

  auto fill_check = [&](int q, int w, int e, int r) {
    if(q > w || e > r) return;
    for(int i = q; i <= w; i++) {
      for(int j = e; j <= r; j++) {
        if(dameYoko[i].find(j) == dameYoko[i].end()) {
          cout << "No\n";
          exit(0);
        }
      }
    }
  };

  while(A <= C && B <= D) {
    if(d == 0) {
      auto it = *dameYoko[B].lower_bound(A);
      fill_check(B, D, it, C);
      B++;
      chmin(C, it - 1);
    } else if(d == 1) {
      auto it = *dameTate[C].lower_bound(B);
      fill_check(it, D, A, C);
      C--;
      chmin(D, it - 1);
    } else if(d == 2) {
      auto it = *--dameYoko[D].upper_bound(C);
      fill_check(B, D, A, it);
      D--;
      chmax(A, it + 1);
    } else {
      auto it = *--dameTate[A].upper_bound(D);
      fill_check(B, it, A, C);
      A++;
      chmax(B, it + 1);
    }
    (d += 1) %= 4;
  }
  cout << "Yes\n";
}