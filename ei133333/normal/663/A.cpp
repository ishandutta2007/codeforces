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
  string s;
  getline(cin, s);
  vector< int > st;
  int ptr = 0;
  vector< int > po, ne;
  po.emplace_back(0);
  st.emplace_back(+1);
  while(ptr < s.size()) {
    if(s[ptr] == '+') {
      po.emplace_back(st.size());
      st.emplace_back(+1);
      ++ptr;
    } else if(s[ptr] == '-') {
      ne.emplace_back(st.size());
      st.emplace_back(-1);
      ++ptr;
    } else if(s[ptr] == '?') {
      ++ptr;
      continue;
    } else if(s[ptr] == '=') {
      ++ptr;
      st.emplace_back(0);
    } else if(s[ptr] == ' ') {
      ++ptr;
    } else {
      int d = 0;
      while(ptr < s.size()) {
        d = d * 10 + s[ptr] - '0';
        ++ptr;
      }
      st.emplace_back(d);
    }
  }

  int64 sum = 0;
  for(int i = 0; i < po.size(); i++) {
    int64 add_low = sum + ((int64) po.size() - i) - (int64) ne.size() * st.back();
    int64 add_high = sum + ((int64) po.size() - i) * st.back() - (int64) ne.size();
    if(add_low <= st.back() && st.back() <= add_high) {
      int64 sa = min< int64 >(st.back() - 1, st.back() - add_low);
      st[po[i]] = 1 + sa;
      sum += 1 + sa;
    } else {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  for(int i = 0; i < ne.size(); i++) {
    int64 add_high = sum - ((int64) ne.size() - i);
    int64 add_low = sum - ((int64) ne.size() - i) * st.back();
    if(add_low <= st.back() && st.back() <= add_high) {
      int64 sa = max< int64 >(-st.back()+1, st.back()-add_high);
      st[ne[i]] = sa - 1;
      sum += sa - 1;
    } else {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
  for(int k = 0; k + 1 < st.size(); k++) {
    if(st[k] < 0) {
      cout << "- " << -st[k] << " ";
    } else if(st[k] > 0) {
      if(k) cout << "+ ";
      cout << st[k] << " ";
    } else {
      cout << "= " << st.back() << endl;
    }
  }
}