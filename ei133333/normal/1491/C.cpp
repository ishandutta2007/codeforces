#include<bits/stdc++.h>

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

void beet() {
  int N;
  cin >> N;
  vector< int64 > S(N);
  cin >> S;
  vector< int64 > V{S};

  int64 ret = 0;
  vector< int > one(N);
  for(int pos = 0; pos < N; pos++) {
    int64 space = N - pos - 1;
    for(int k = min(space, V[pos]); k > S[pos]; k--) {
      if(S[pos + k] != 1) {
        --S[pos + k];
      } else {
        one[pos + k] += 1;
      }
    }
    if(pos + 1 < N and one[pos] >= 1) {
      int64 pre = S[pos + 1];
      S[pos + 1] -= one[pos];
      chmax(S[pos + 1], 1);
      int64 nxt = S[pos + 1];
      one[pos + 1] += max(0LL, one[pos] - (pre - nxt));
    }
    if(S[pos] == 1) {
      continue;
    }

    int right = pos + S[pos];
    if(pos == N - 1) {
      ret += max(0, right - N);
    } else {
      ret += max(0, right + 1 - N);
    }
    S[pos] = 1;
    for(int j = pos + 2; j < min(N, right + 1); j++) {
      ret += 1;
      if(S[j] >= 2) {
        S[j]--;
      } else {
        one[j] += 1;
      }
    }
  }
  cout << ret << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) beet();
}