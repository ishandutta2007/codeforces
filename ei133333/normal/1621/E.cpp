#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

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

void beet() {
  int N, M;
  cin >> N >> M;
  vector< int64 > A(N);
  cin >> A;
  A.emplace_back(0);
  A.emplace_back(0);
  A.emplace_back(0);
  sort(A.rbegin(), A.rend());
  vector< int64 > K(M);
  vector< vector< int64 > > B(M);
  vector< int64 > C(M);
  for(int i = 0; i < M; i++) {
    cin >> K[i];
    B[i].resize(K[i]);
    cin >> B[i];
    C[i] = accumulate(begin(B[i]), end(B[i]), 0LL);
  }
  vector< pair< int64, int64 > > ord(M);
  for(int i = 0; i < M; i++) {
    ord[i] = {(C[i] + K[i] - 1) / K[i], i};
  }
  sort(ord.rbegin(), ord.rend());
  auto f = make_v< int >(3, M);
  for(int s = -1; s <= 1; s++) {
    for(int i = 0; i < M; i++) {
      if(0 <= i + s and i + s < M) {
        f[s + 1][i] = ord[i + s].first <= A[i];
      } else {
        f[s + 1][i] = 1;
      }
    }
  }
  auto g = make_v< int >(3, M + 1);
  for(int s = 0; s <= 2; s++) {
    for(int i = 0; i < M; i++) {
      g[s][i + 1] = g[s][i] + f[s][i];
    }
  }
  auto uku = [&](int s, int l, int r) {
    return g[s][r] - g[s][l] == r - l;
  };
  string ans;
  for(int i = 0; i < M; i++) {
    pair< int64, int64 > pre_v{(C[i] + K[i] - 1) / K[i], i};
    int pre_pos = lower_bound(begin(ord), end(ord), pre_v, greater<>()) - begin(ord);
    --K[i];
    for(auto &b: B[i]) {
      int64 vv = (C[i] - b + K[i] - 1) / K[i];
      pair< int64, int64 > nxt_v{vv, i};
      int nxt_pos = lower_bound(begin(ord), end(ord), nxt_v, greater<>()) - begin(ord);

      bool flag = true;
      if(nxt_pos <= pre_pos) {
        /*
        for(int k = 0; k < nxt_pos; k++) {
          flag &= f[1][k];
        }
        flag &= vv <= A[nxt_pos];
        for(int k = nxt_pos + 1; k <= pre_pos; k++) {
          flag &= f[0][k];
        }
        for(int k = pre_pos + 1; k < M; k++) {
          flag &= f[1][k];
        }
         */
        flag &= uku(1, 0, nxt_pos);
        flag &= vv <= A[nxt_pos];
        flag &= uku(0, nxt_pos + 1, pre_pos + 1);
        flag &= uku(1, pre_pos + 1, M);
      } else {
        nxt_pos--;
        /*
        for(int k = 0; k < pre_pos; k++) {
          flag &= f[1][k];
        }
        for(int k = pre_pos; k < nxt_pos; k++) {
          flag &= f[2][k];
        }
        flag &= vv <= A[nxt_pos];
        for(int k = pre_pos + 1; k < M; k++) {
          flag &= f[1][k];
        }
         */
        flag &= uku(1, 0, pre_pos);
        flag &= uku(2, pre_pos, nxt_pos);
        flag &= vv <= A[nxt_pos];
        flag &= uku(1, nxt_pos + 1, M);
      }
      if(flag) ans += "1";
      else ans += "0";
    }
  }
  cout << ans << "\n";
}


int main() {
  int T;
  cin >> T;
  while(T--) beet();
}