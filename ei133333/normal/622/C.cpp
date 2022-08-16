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

int main() {
  int N, M;
  cin >> N >> M;
  vector< int > A(N);
  cin >> A;

  vector< pair< int, int > > belong[1010101];
  for(int i = 0; i < A.size(); i++) {
    if(belong[A[i]].size() && belong[A[i]].back().second + 1 == i) {
      ++belong[A[i]].back().second;
    } else {
      belong[A[i]].emplace_back(i, i);
    }
  }

  while(M--) {
    int L, R, X;
    cin >> L >> R >> X;
    --L, --R;
    auto it = lower_bound(begin(belong[X]), end(belong[X]), make_pair(R + 1, -1));
    if(it == begin(belong[X])) {
      cout << L + 1 << endl;
    } else {
      --it;
      if(it->first <= L && R <= it->second) {
        cout << -1 << endl;
      } else if(it->first > L) {
        cout << it->first << endl;
      } else {
        cout << R + 1 << endl;
      }
    }
  }
}