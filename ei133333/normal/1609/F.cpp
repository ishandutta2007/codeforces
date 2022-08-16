#include<bits/stdc++.h>

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

int main() {
  int N;
  cin >> N;
  vector< int64 > A(N);
  cin >> A;
  vector< int > B(N);
  for(int i = 0; i < N; i++) {
    B[i] = __builtin_popcountll(A[i]);
  }
  auto cmp = [&](int i, int j) {  // i<j
    if(A[i] == A[j]) return i < j;
    else return A[i] < A[j];
  };
  int64 ret = 0;
  vector< int > latte(N), malta(N);
  vector< int > X(64), Y(64);
  auto rec = MFP([&](auto rec, int l, int r) -> void {
    if(l + 1 == r) {
      ++ret;
      return;
    }
    int m = (l + r) / 2;
    rec(l, m);
    rec(m, r);
    // [l, m) -> [m, r)
    {
      int small = m, large = m;
      for(int k = m; k < r; k++) {
        if(cmp(k, small)) small = k;
        if(cmp(large, k)) large = k;
        latte[k] = small;
        malta[k] = large;
      }
    }
    {
      int small = m - 1, large = m - 1;
      for(int k = m - 1; k >= l; k--) {
        if(cmp(k, small)) small = k;
        if(cmp(large, k)) large = k;
        latte[k] = small;
        malta[k] = large;
      }
    }
    // 1) min max | min<v<max
    {
      // smalllarge
      // 
      // B[small]
      // 
      int ptr1 = m, ptr2 = m;
      for(int k = m - 1; k >= l; k--) {
        while(ptr1 < r and cmp(latte[k], latte[ptr1])) {
          X[B[malta[ptr1]]]++;
          Y[B[latte[ptr1]]]--;
          ++ptr1;
        }
        while(ptr2 < r and cmp(malta[ptr2], malta[k])) {
          X[B[malta[ptr2]]]--;
          Y[B[latte[ptr2]]]++;
          ++ptr2;
        }
        int ptr = min(ptr1, ptr2);
        if(B[latte[k]] == B[malta[k]]) {
          ret += ptr - m;
        }
        if(ptr2 < ptr1) {
          int bit = B[latte[k]];
          ret += X[bit];
          /*
          for(int x = ptr2; x < ptr1; x++) {
            ret += B[malta[x]] == bit;
          }
           */
        }
        if(ptr1 < ptr2) {
          int bit = B[malta[k]];
          ret += Y[bit];
          /*
          for(int x = ptr1; x < ptr2; x++) {
            ret += B[latte[x]] == bit;
          }
           */
        }
      }
      while(ptr1 < r) {
        X[B[malta[ptr1]]]++;
        Y[B[latte[ptr1]]]--;
        ++ptr1;
      }
      while(ptr2 < r) {
        X[B[malta[ptr2]]]--;
        Y[B[latte[ptr2]]]++;
        ++ptr2;
      }
    }
    // 4) min<v<max | min max
    {
      int ptr1 = m - 1, ptr2 = m - 1;
      for(int k = m; k < r; k++) {
        while(ptr1 >= l and cmp(latte[k], latte[ptr1])) {
          --ptr1;
        }
        while(ptr2 >= l and cmp(malta[ptr2], malta[k])) {
          --ptr2;
        }
        int ptr = max(ptr1, ptr2) + 1;
        if(B[latte[k]] == B[malta[k]]) {
          ret += m - ptr;
        }
      }
    }
  });
  rec(0, N);
  cout << ret << "\n";
}