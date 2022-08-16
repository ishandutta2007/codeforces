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
    int H, G;
    cin >> H >> G;
    vector< int > A(1<<H);
    int64 all = 0;
    for(int i = 1; i < (1 << H); i++) {
      cin >> A[i];
      all += A[i];
    }
    using pi = pair< int, int >;
    priority_queue< pi > head;
    head.emplace(A[1], 1);
    vector< int > V;

    auto tap = MFP([&](auto tap, int idx) -> void {
      if(idx * 2 >= A.size() || (A[idx * 2] == 0 && A[idx * 2 + 1] == 0)) {
        A[idx] = 0;
      } else if(A[idx * 2] > A[idx * 2 + 1]) {
        A[idx] = A[idx * 2];
        tap(idx * 2);
      } else {
        A[idx] = A[idx * 2 + 1];
        tap(idx * 2 + 1);
      }
    });

    auto tap2 = MFP([&](auto tap, int idx) -> bool {
      if(idx * 2 >= A.size() || (A[idx * 2] == 0 && A[idx * 2 + 1] == 0)) {
        return idx >= (1 << G);
      } else if(A[idx * 2] > A[idx * 2 + 1]) {
        return tap(idx * 2);
      } else {
        return tap(idx * 2 + 1);
      }
    });

    for(int i = 0; i < (1 << H) - (1 << G); i++) {
      while(!tap2(head.top().second)) {
        auto p = head.top();
        head.pop();
        if(p.second * 2 < A.size()) {
          head.emplace(A[p.second * 2 + 0], p.second * 2 + 0);
          head.emplace(A[p.second * 2 + 1], p.second * 2 + 1);
        }
      }
      auto p = head.top();
      tap(p.second);
      all -= p.first;
      V.emplace_back(p.second);
      head.pop();
      head.emplace(A[p.second], p.second);
    }
    cout << all << endl;
    cout << V << endl;
  }
}