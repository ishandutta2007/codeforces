#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

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

int query(const string &s) {
  cout << s << endl;
  int x;
  cin >> x;

  if(x == 0) exit(0);

  return x;
}

int main() {
  int len = query("a") + 1;

  bool decide = false;
  if(len > 300) {
    len = 300;
    decide = true;
  }
  string make = string(len, 'a');
  int now = query(make);

  if(len == now && !decide) {
    cout << string(len - 1, 'b') << endl;
    return 0;
  }

  vector< int > ver;
  int x = 0, y = len - 1;
  for(int i = 0; i < len; i++) {
    if(i % 2 == 0) {
      ver.emplace_back(x++);
    } else {
      ver.emplace_back(y--);
    }
  }
  int p = ver.back();
  ver.pop_back();

  for(int i : ver) {
    make[i] = 'b';
    int nxt = query(make);
    if(nxt > now) {
      make[i] = 'a';
    } else {
      now = nxt;
    }
  }
  if(now == 1) {
    make[p] = 'b';
  }
  query(make);
}