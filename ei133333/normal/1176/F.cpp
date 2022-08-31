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
  vector< vector< int > > uku;
  for(int i = 0; i <= 3; i++) {
    for(int j = 0; j <= 3; j++) {
      for(int k = 0; k <= 3; k++) {
        int sum = i * 3 + j * 2 + k;
        if(sum <= 3) uku.emplace_back(vector< int >{k, j, i});
      }
    }
  }

  vector< int64 > dp(10, -inf);
  dp[0] = 0;
  for(int z = 0; z < N; z++) {
    int K;
    cin >> K;
    vector< int > P[3];
    for(int i = 0; i < K; i++) {
      int s, t;
      cin >> s >> t;
      --s;
      P[s].emplace_back(t);
    }
    for(int i = 0; i < 3; i++) {
      sort(P[i].rbegin(), P[i].rend());
    }
    vector< int64 > nxtdp(10, -infll);
    for(auto &t : uku) {
      int64 add = 0;
      int64 mx = 0;
      int64 sum = 0;
      bool ok = true;
      for(int k = 0; k < 3; k++) {
        if(t[k] > P[k].size()) {
          ok = false;
          break;
        }
        for(int l = 0; l < t[k]; l++) {
          add += P[k][l];
          chmax(mx, P[k][l]);
          ++sum;
        }
      }
      if(ok) {
        for(int k = 0; k < 10; k++) {
          if(dp[k] >= 0) {
            if(k + sum >= 10) {
              chmax(nxtdp[(k + sum) - 10], dp[k] + add + mx);
            } else {
              chmax(nxtdp[k + sum], dp[k] + add);
            }
          }
        }
      }
    }
    dp.swap(nxtdp);
  }
  cout << *max_element(begin(dp), end(dp)) << endl;
}