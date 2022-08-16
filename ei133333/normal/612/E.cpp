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
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  for(auto &a : A) --a;

  vector< int > used(N);
  vector< int > rem[1010101];
  vector< int > Q(N);
  for(int i = 0; i < N; i++) {
    if(used[i]) continue;
    int cur = i;
    vector< int > st;
    while(cur != i || st.empty()) {
      used[cur] = true;
      st.emplace_back(cur);
      cur = A[cur];
    }
    if(st.size() & 1) {
      for(int j = 0; j < st.size(); j++) {
        Q[st[j]] = st[(j + (st.size() + 1) / 2) % st.size()];
      }
    } else {
      if(rem[st.size()].size()) {
        for(int j = 0; j < st.size(); j++) {
          Q[rem[st.size()][j]] = st[j];
          Q[st[j]] = rem[st.size()][(j + 1) % st.size()];
        }
        rem[st.size()].clear();
      } else {
        rem[st.size()] = st;
      }
    }
  }
  for(int i = 0; i < N; i++) {
    if(rem[i].size()) {
      cout << -1 << endl;
      return 0;
    }
  }
  for(int i = 0; i < N; i++) cout << Q[i] + 1 << " ";
  cout << endl;
}