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


int main() {
  auto mat = make_v< int >(10, 10);
  cin >> mat;

  auto dp = make_v< double >(100);
  auto rev = make_v< int >(10, 10);
  vector< pair< int, int > > ord;
  for(int i = 9; i >= 0; i--) {
    if(i % 2 == 1) {
      for(int j = 0; j < 10; j++) {
        ord.emplace_back(i, j);
      }
    } else {
      for(int j = 9; j >= 0; j--) {
        ord.emplace_back(i, j);
      }
    }
  }
  for(int i = 0; i < 100; i++) {
    rev[ord[i].first][ord[i].second] = i;
  }


  auto memo = make_v< bool >(100);
  auto rec = MFP([&](auto rec, int idx) -> double {
    if(idx == 99) return 0.0;
    if(memo[idx]) return dp[idx];
    memo[idx] = true;

    int fail = 0;
    // F[idx] = (F[nxt] + F[idx]*fail)/6 + 1
    // 6*F[idx] = F[nxt] + F[idx]*fail + 6
    // (6-fail)*F[idx] = F[nxt]+6

    double ret = 0.0;
    for(int i = 1; i <= 6; i++) {
      if(idx + i >= 100) {
        ++fail;
      } else {
        auto p = ord[idx + i];
        double uku = rec(idx + i);
        p.first -= mat[p.first][p.second];
        chmin(uku, rec(rev[p.first][p.second]));
        ret += uku;
      }
    }
    return dp[idx] = (ret + 6.0) / (6.0 - fail);
  });


  cout << rec(0) << endl;
}