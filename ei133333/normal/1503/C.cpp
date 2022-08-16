#include<bits/stdc++.h>

using namespace std;
using int64 = long long;
// const int mod = 1e9 + 7;
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
  int N;
  cin >> N;
  vector< int64 > A(N), C(N);
  vector< int > ord(N);
  int64 sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> C[i];
    ord[i] = i;
    sum += C[i];
  }
  sort(begin(ord), end(ord), [&](int a, int b) {
    return A[a] < A[b];
  });
  vector< int > rev(N);
  for(int i = 0; i < N; i++) {
    rev[ord[i]] = i;
  }
  int64 cost = 0;

  if(rev[0] == 0) {
    int left = 0;
    while(left < N) {
      int ptr = left;
      int64 mx = A[ord[left]] + C[ord[left]];
      while(ptr <= rev[0] or (ptr < N and A[ord[ptr]] <= mx)) {
        chmax(mx, C[ord[ptr]] + A[ord[ptr]]);
        ++ptr;
      }
      left = ptr;
      if(ptr < N) {
        cost += A[ord[ptr]] - mx;
      }
    }
    cout << sum + cost << "\n";
  } else {
    {
      int left = 0;
      while(left < N) {
        int ptr = left;
        int64 mx = A[ord[left]] + C[ord[left]];
        while(ptr <= rev[0] or (ptr < N and A[ord[ptr]] <= mx)) {
          chmax(mx, C[ord[ptr]] + A[ord[ptr]]);
          ++ptr;
        }
        left = ptr;
        if(ptr < N) {
          cost += A[ord[ptr]] - mx;
        }
      }
    }

    cost += max(0LL, (A[0] - A[ord[0]]) - C[ord[0]]);


    {
      int left = 0;
      int64 cost2 = 0;
      {
        int64 mx = A[ord[0]] + C[ord[0]];
        while(left < N and A[ord[left]] <= mx) {
          chmax(mx, C[ord[left]] + A[ord[left]]);
          ++left;
        }
        if(left < N) {
          cost2 += A[ord[left]] - mx;
        }
      }
      while(left < N) {
        int ptr = left;
        int64 mx = A[ord[left]] + C[ord[left]];
        while(ptr < N and A[ord[ptr]] <= mx) {
          chmax(mx, C[ord[ptr]] + A[ord[ptr]]);
          ++ptr;
        }
        left = ptr;
        if(ptr < N) {
          cost2 += A[ord[ptr]] - mx;
        }
      }
      chmin(cost, cost2);
    }
    cout << sum + cost << "\n";
  }
}