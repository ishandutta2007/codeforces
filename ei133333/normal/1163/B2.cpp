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

  vector< int > S(100000);
  map< int, int > kind;
  kind[0] = 100000;

  int ret = 0;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    --x;

    kind[S[x]]--;
    if(kind[S[x]] == 0) kind.erase(S[x]);
    S[x]++;
    kind[S[x]]++;

    if(kind.size() > 5) continue;


    vector< pair< int, int > > conv(kind.begin(), kind.end());
    for(int j = 0; j < conv.size(); j++) {
      if(conv[j].first == 0) continue;
      conv[j].second--;

      bool ok = true;
      int val = conv[j].first - 1;

      for(int k = 0; k < conv.size(); k++) {
        if(conv[k].first == 0 || conv[k].second == 0) continue;
        if(val == 0) val = conv[k].first;
        else if(val != conv[k].first) ok = false;
      }
      if(ok) chmax(ret, i + 1);
      conv[j].second++;
    }
  }
  cout << ret << endl;
}