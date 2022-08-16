#include<bits/stdc++.h>

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


  int T;
  cin >> T;
  while(T--) {
    int64 K;
    cin >> K;

    auto check = [&](int64 v) {
      int64 ret = 0;
      int64 sum = 0;
      for(int64 i = 1, limit = 9; i <= 18; i++, sum += limit, limit *= 10) {
        int64 req = v - sum;
        if(req <= 0) break;
        int64 latte = min(limit, req);
        req -= latte;
        ret += 1LL * latte * (latte + 1) / 2 * i;
        if(ret >= K) return ret;
        ret += 1LL * req * limit * i;
        if(ret >= K) return ret;
      }
      return ret;
    };

    int64 ok = 0, ng = inf;
    while(ng - ok > 1) { // K 
      int64 md = (ok + ng) / 2;
      if(check(md) < K) ok = md;
      else ng = md;
    }
    K -= check(ok);


    bool output = false;
    auto check2 = [&](int64 v) {
      int64 ret = 0;
      int64 sum = 0;
      for(int64 i = 1, limit = 9; i <= 18; i++, sum += limit, limit *= 10) {
        int64 req = min(limit, v - sum);
        if(req <= 0) break;
        ret += 1LL * req * i;
        if(ret >= K) return ret;
      }
      return ret;
    };

    int64 ok2 = 0, ng2 = inf;
    while(ng2 - ok2 > 1) {
      int64 md2 = (ok2 + ng2) / 2;
      if(check2(md2) < K) ok2 = md2;
      else ng2 = md2;
    }
    int64 pos = ok2;
    K -= check2(pos);
    string s = to_string(pos + 1);
    cout << s[K - 1] << endl;
  }
}