#include <bits/stdc++.h>

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
  int N;
  cin >> N;
  vector< int > S(N);
  cin >> S;

  vector< int > ord[101];
  for(int i = 0; i < N; i++) {
    ord[S[i]].emplace_back(i);
  }

  vector< int > one, more;
  for(int i = 0; i < 101; i++) {
    if(ord[i].size() == 1) {
      one.emplace_back(i);
    } else if(ord[i].size() >= 3) {
      more.emplace_back(i);
    }
  }

  if(one.size() % 2 == 1) {
    if(more.size() > 0) {
      one.emplace_back(more.back());
      more.pop_back();
    } else {
      cout << "NO\n";
      return 0;
    }
  }


  vector< int > ans(N);
  while(one.size()) {
    auto p = one.back();
    one.pop_back();
    auto q = one.back();
    one.pop_back();
    ans[ord[p][0]] = 1;
    for(int k = 1; k < ord[q].size(); k++) {
      ans[ord[q][k]] = 1;
    }
  }

  cout << "YES" << endl;
  for(auto &p : ans) cout << "AB"[p];
  cout << endl;


}