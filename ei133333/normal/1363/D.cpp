#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
//const int mod = 1e9 + 7;
const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

/*
struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;
*/

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
  int T;
  cin >> T;
  while(T--) {
    int N, K;
    cin >> N >> K;
    vector< vector< int > > tap;
    vector< int > used(N);
    for(int i = 0; i < K; i++) {
      int c;
      cin >> c;
      vector< int > d(c);
      cin >> d;
      for(auto &p : d) {
        --p;
        used[p] = true;
      }
      tap.emplace_back(d);
    }
    tap.emplace_back();
    for(int i = 0; i < N; i++) {
      if(!used[i]) tap.back().emplace_back(i);
    }

    auto check = [&](int line) {
      vector< int > u;
      for(int i = 0; i <= line; i++) {
        for(auto &p : tap[i]) u.emplace_back(p + 1);
      }
      sort(begin(u), end(u));
      cout << "? " << u.size() << " " << u << endl;
      int x;
      cin >> x;
      return x;
    };

    int mx = check(K);
    int ok = K, ng = -1;
    while(ok - ng > 1) {
      int mid = (ok + ng) / 2;
      if(check(mid) == mx) ok = mid;
      else ng = mid;
    }
    vector< int > u;
    for(int i = 0; i <= K; i++) {
      if(i != ok) for(auto& p : tap[i]) u.emplace_back(p + 1);
    }
    sort(begin(u), end(u));
    cout << "? " << u.size() << " " << u << endl;
    int x;
    cin >> x;

    vector< int > ans;
    for(int i = 0; i < K; i++) {
      if(i == ok) ans.emplace_back(x);
      else ans.emplace_back(mx);
    }
    cout << "! " << ans << endl;
    string s;
    cin >> s;
  }
}