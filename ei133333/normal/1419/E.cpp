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

map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return (ret);
}

vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

void beet() {
  int N;
  cin >> N;
  auto p = prime_factor(N);

  auto d = divisor(N);

  vector< pair< int64, int > > pd(p.begin(), p.end());
  set< int64 > st(d.begin(), d.end());
  st.erase(1);

  if(pd.size() >= 3) {
    vector< int > ans;
    for(int i = 0; i < pd.size(); i++) {
      ans.emplace_back(pd[i].first);
      st.erase(pd[i].first);
      int64 mul = pd[i].first * pd[(i + 1) % pd.size()].first;
      ans.emplace_back(mul);
      st.erase(mul);
    }
    vector< vector< int > > belong(pd.size());
    for(auto val : st) {
      for(int i = 0; i < pd.size(); i++) {
        if(val % pd[i].first == 0) {
          belong[i].emplace_back(val);
          break;
        }
      }
    }
    vector< int > ret;
    for(int i = 0; i < ans.size(); i++) {
      ret.emplace_back(ans[i]);
      if(i % 2 == 0) {
        for(auto &val : belong[i / 2]) ret.emplace_back(val);
      }
    }
    cout << ret << "\n";
    cout << 0 << "\n";
    return;
  } else if(pd.size() == 2) {
    if(pd[0].second == 1 && pd[1].second == 1) {
      d.erase(begin(d));
      cout << d << "\n";
      cout << 1 << "\n";
      return;
    }
    if(pd[1].second > 1) {
      vector< int > ans;
      ans.emplace_back(pd[0].first);
      ans.emplace_back(pd[0].first * pd[1].first);
      ans.emplace_back(pd[1].first);
      int64 mul = pd[1].first;
      for(int i = 2; i <= pd[1].second; i++) {
        mul *= pd[1].first;
        ans.emplace_back(mul);
        ans.emplace_back(mul * pd[0].first);
      }
      cout << ans << "\n";
      cout << 0 << "\n";
      return;
    }

    vector< int > ans;
    ans.emplace_back(pd[1].first);
    ans.emplace_back(pd[1].first * pd[0].first);
    ans.emplace_back(pd[0].first);
    int64 mul = pd[0].first;
    for(int i = 2; i <= pd[0].second; i++) {
      mul *= pd[0].first;
      ans.emplace_back(mul);
      ans.emplace_back(mul * pd[1].first);
    }
    cout << ans << "\n";
    cout << 0 << "\n";
    return;

  } else {
    d.erase(begin(d));
    cout << d << "\n";
    cout << 0 << "\n";
  }
}

int main() {
  int T;
  cin >> T;
  while(T--) beet();
}