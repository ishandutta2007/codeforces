#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;


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


int ask(const vector< int > &a, const vector< int > &b) {
  cout << a.size() << " " << b.size() << " ";
  for(auto &t : a) cout << t + 1 << " ";
  for(auto &t : b) cout << t + 1 << " ";
  cout << endl;
  int x;
  cin >> x;
  return x;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;

    int root = 0;
    vector< int > ok(N, true);
    ok[root] = false;
    vector< int > uku2;
    for(int i = 1; i < N; i++) uku2.emplace_back(i);
    int D1 = ask({0}, uku2);

    int rest = 0;
    while((rest = count(begin(ok), end(ok), true)) > 1) {
      int mid = (rest + 1) / 2;
      vector< int > latte, malta;
      for(int i = 0; i < N; i++) {
        if(ok[i]) {
          if(mid > 0) {
            --mid;
            latte.push_back(i);
          } else {
            malta.push_back(i);
          }
        }
      }
      int x = ask({0}, latte);
      if(x == D1) {
        for(auto t : malta) ok[t] = false;
      } else {
        for(auto t : latte) ok[t] = false;
      }
    }
    int pos = -1;
    vector< int > uku;
    for(int i = 0; i < N; i++) {
      if(ok[i]) pos = i;
      else uku.emplace_back(i);
    }
    int D2 = ask({pos}, uku);
    cout << "-1 " << D2 << endl;
  }
}