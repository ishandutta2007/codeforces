#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

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
  int N, K;
  cin >> N >> K;
  vector< int > A(N);
  cin >> A;

  sort(begin(A), end(A));
  vector< pair< int, int > > st;
  for(int i = 0; i < N; i++) {
    if(st.empty() || st.back().first != A[i]) st.emplace_back(A[i], 0);
    st.back().second++;
  }

  auto solve = [&](vector< pair< int, int > > &st) -> int64 {
    for(auto &p : st) if(p.second >= K) return 0;
    int64 cost = 0;
    int64 ret = infll;
    vector< int64 > latte(st.size()), malta(st.size());
    for(int i = 0; i < st.size(); i++) {
      latte[i] += 1LL * st[i].first * st[i].second;
      malta[i] += 1LL * st[i].second;
    }
    for(int i = 1; i < st.size(); i++) {
      latte[i] += latte[i - 1];
      malta[i] += malta[i - 1];
    }
    while(st.size() >= 2) {
      auto p = st.back();
      st.pop_back();
      if(st.back().first + 1 != p.first) {
        cost += 1LL * p.second * (p.first - (st.back().first + 1));
        st.emplace_back(st.back().first + 1, p.second);
        continue;
      }
      int need = max(0, min(K - st.back().second, p.second));
      st.back().second += need;
      cost += need;
      if(st.back().second >= K) {
        chmin(ret, cost);
      } else {
        need = K - st.back().second;
        if(st.size() == 1 || malta[(int) st.size() - 2] < need) {
          continue;
        }
        int64 pre_cost = 0, pre_need = st.back().first - 1;
        pre_cost -= latte[(int) st.size() - 2];
        pre_cost += malta[(int) st.size() - 2] * pre_need;
        pre_cost += need;
        chmin(ret, pre_cost + cost);
      }
    }
    return ret;
  };


  int64 tap = solve(st);


  st.clear();
  for(auto &p : A) p *= -1;
  sort(begin(A), end(A));
  for(int i = 0; i < N; i++) {
    if(st.empty() || st.back().first != A[i]) st.emplace_back(A[i], 0);
    st.back().second++;
  }

  cout << min(tap, solve(st)) << endl;
}