
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
 
map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
 
int main() {
  int N;
  cin >> N;
  vector< int64 > A(N);
  cin >> A;
 
  int64 sum = accumulate(begin(A), end(A), 0LL);
  if(sum == 1) {
    cout << -1 << endl;
    return 0;
  }
 
 
  auto d = prime_factor(sum);
 
  auto unimodalFunc = [&](int64 now_sum) {
    auto B(A);
    int64 cur = 0;
    vector< pair< int64, int > > uku;
 
    int64 cost = 0;
    for(int i = 0; i < N; i++) {
 
      const int64 need = now_sum - cur;
      const int64 get = min(need, B[i]);
 
      if(get > 0) {
        B[i] -= get;
        cur += get;
        uku.emplace_back(get, i);
      }
 
      if(cur == now_sum) {
        int64 now = 0;
        for(auto& p : uku) {
          now += p.first;
          if(now * 2 > now_sum) {
            for(auto& q : uku) {
              int64 d = abs(q.second - p.second);
              int64 people = q.first;
              cost += d * people;
            }
            break;
          }
        }
        uku.clear();
        cur = 0;
      }
 
      B[i] -= B[i] / now_sum * now_sum;
 
      if(B[i] > 0) {
        cur += B[i];
        uku.emplace_back(B[i], i);
      }
    }
    return cost;
  };

  int64 ret = infll;
  for(auto& p : d) chmin(ret, unimodalFunc(p.first));
  cout << ret << endl;
}