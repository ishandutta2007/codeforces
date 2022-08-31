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
  string S, T;

  cin >> N;
  cin >> S >> T;
  vector< int > latte[27], malta[27];
  for(int i = 0; i < S.size(); i++) {
    if(S[i] == '?') latte[26].emplace_back(i);
    else latte[S[i] - 'a'].emplace_back(i);
  }

  for(int i = 0; i < T.size(); i++) {
    if(T[i] == '?') malta[26].emplace_back(i);
    else malta[T[i] - 'a'].emplace_back(i);
  }

  vector< pair< int, int > > uku;
  for(int i = 0; i < 26; i++) {
    while(latte[i].size() > 0 && malta[i].size() > 0) {
      uku.emplace_back(latte[i].back(), malta[i].back());
      latte[i].pop_back();
      malta[i].pop_back();
    }
  }
  for(int i = 0; i < 26; i++) {
    while(latte[i].size() > 0 && malta[26].size() > 0) {
      uku.emplace_back(latte[i].back(), malta[26].back());
      latte[i].pop_back();
      malta[26].pop_back();
    }
    while(latte[26].size() > 0 && malta[i].size() > 0) {
      uku.emplace_back(latte[26].back(), malta[i].back());
      latte[26].pop_back();
      malta[i].pop_back();
    }
  }
  while(latte[26].size() > 0 && malta[26].size() > 0) {
    uku.emplace_back(latte[26].back(), malta[26].back());
    latte[26].pop_back();
    malta[26].pop_back();
  }
  cout << uku.size() << endl;
  for(auto& p : uku) cout << p.first + 1 << " " << p.second + 1 << endl;

}