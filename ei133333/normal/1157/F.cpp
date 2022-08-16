#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

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
  vector< int > A(N);
  cin >> A;

  map< int, int > mp;
  for(auto &p : A) mp[p]++;


  set< int > tapu;
  vector< pair< int, int > > tapi;
  for(auto &p : mp) {
    if(p.second >= 2) tapi.emplace_back(p);
    else tapu.emplace(p.first);
  }

  int r = 0;
  int ret = 0;
  int latte, malta;
  for(auto &p : tapu) {
    if(chmax(ret, 1)) {
      latte = p;
      malta = p;
    }
    if(tapu.count(p + 1) && chmax(ret, 2)) {
      latte = p;
      malta = p + 1;
    }
  }
  while(r < tapi.size()) {
    int l = r, sum = tapi[r].second;
    while(r + 1 < tapi.size() && tapi[r + 1].first == tapi[r].first + 1) {
      ++r;
      sum += tapi[r].second;
    }
    bool is_l = tapu.count(tapi[l].first - 1);
    bool is_r = tapu.count(tapi[r].first + 1);
    if(chmax(ret, sum + is_l + is_r)) {
      latte = tapi[l].first - is_l;
      malta = tapi[r].first + is_r;
    }
    ++r;
  }
  cout << ret << endl;
  multiset< int > X, Y;
  for(auto &p : A) {
    if(latte <= p && p <= malta) {
      if(X.find(p) != end(X)) Y.emplace(-p);
      else X.emplace(p);
    }
  }

  for(auto& p : X) cout << p << " ";
  for(auto& p : Y) cout << -p << " ";
  cout << endl;
}