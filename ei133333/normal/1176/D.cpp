#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

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


int main() {
  int N;
  cin >> N;

  vector< int > dp(2750132), prime;
  for(int i = 2; i < dp.size(); i++) {
    if(dp[i] == 0) {
      prime.emplace_back(i);
    }
    for(int j = i + i; j < dp.size(); j += i) {
      dp[j] = i;
    }
  }
  multiset< int > st;
  for(int i = 0; i < 2 * N; i++) {
    int x;
    cin >> x;
    st.emplace(x);
  }
  vector< int > primes;
  while(st.size()) {
    auto it = *st.rbegin();
    st.erase(st.find(it));
    if(dp[it] == 0) {
      primes.emplace_back(it);
    } else { // not prime
      st.erase(st.find(dp[it]));
      cout << it << " ";
    }
  }
  for(auto &t : primes) st.emplace(t);
  while(st.size()) {
    auto it = *st.begin();
    st.erase(st.find(it));
    st.erase(st.find(prime[it-1]));
    cout << it << " ";
  }
  cout << endl;
}