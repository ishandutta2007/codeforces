#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
const int mod = 998244353;

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

void beet() {
  string S;
  cin >> S;
  int aa = 0;
  for(auto &c : S) aa |= 1 << (c - 'a');
  aa = __builtin_popcount(aa);
  vector< int > cnt(26);
  for(auto &c : S) cnt[c - 'a']++;

  int k = (int) S.size() - 1;
  int bit = 0;
  string last;
  string xs;
  while(k >= 0) {
    int nxt = 0;
    int ptr = 0;
    string f;

    int rest = aa - (int) xs.size() - 1;
    vector< int > prod(26);
    while(k >= 0 and (((bit | nxt) >> (S[k] - 'a') & 1) or nxt == 0)) {
      int uku = 1 << (S[k] - 'a');
      if((bit & uku) == 0) {
        if(nxt != 0) {
          if(rest != 0 and (cnt[S[k] - 'a'] - prod[S[k]-'a']) / rest == prod[S[k]-'a'] and (cnt[S[k] - 'a'] - prod[S[k]-'a']) % rest == 0) {
            break;
          }
        } else {
          nxt = uku;
        }
        prod[S[k]-'a']++;
      } else {
        if(rest != 0 and (cnt[S[k] - 'a'] - prod[S[k]-'a']) / rest == prod[S[k]-'a'] and (cnt[S[k] - 'a'] - prod[S[k]-'a']) % rest == 0) {
          break;
        }
        if(ptr >= last.size() or last[ptr] != S[k]) {
          cout << -1 << "\n";
          return;
        }
        prod[S[k]-'a']++;
        ++ptr;
      }
      f += S[k];
      --k;
    }
    if(nxt == 0 or ptr != last.size()) {
      cout << -1 << "\n";
      return;
    }
    for(auto &c : f) cnt[c - 'a']--;
    xs += (char) (__builtin_ctz(nxt) + 'a');
    bit |= nxt;
    last = move(f);
  }
  reverse(begin(last), end(last));
  reverse(begin(xs), end(xs));
  cout << last << " " << xs << "\n";
}


int main() {
  int T;
  cin >> T;
  while(T--) {
    beet();
  }
}