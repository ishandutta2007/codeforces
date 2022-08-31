#include<bits/stdc++.h>

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
  for(T &in: v) is >> in;
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
  for(auto &e: t) fill_v(e, v);
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

bool beet() {
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;
  set< int > mp[256];
  for(int i = 0; i < N; i++) {
    mp[S[i]].emplace(i);
  }
  for(int i = 0; i < N; i++) {
    if(S[i] != T[i]) {
      if(S[i] == 'a') {
        if(T[i] == 'c') return false;
        // ab
        // ac
        auto bb = mp['b'].begin();
        if(bb == end(mp['b'])) return false;
        auto cc = mp['c'].begin();
        if(cc != end(mp['c']) and *bb > *cc) return false;

        int idx = *bb;
        swap(S[idx], S[i]);
        mp['b'].erase(idx);
        mp['b'].emplace(i);
        mp['a'].erase(i);
        mp['a'].emplace(idx);

      } else if(S[i] == 'b') {
        if(T[i] == 'a') return false;
        auto bb = mp['c'].begin();
        if(bb == end(mp['c'])) return false;
        auto cc = mp['a'].begin();
        if(cc != end(mp['a']) and *bb > *cc) return false;
        int idx = *bb;
        swap(S[idx], S[i]);
        mp['c'].erase(idx);
        mp['c'].emplace(i);
        mp['b'].erase(i);
        mp['b'].emplace(idx);
      } else {
        return false;
      }
    }
    mp[S[i]].erase(i);
  }
  return true;
}

int main() {
  int Q;
  cin >> Q;
  while(Q--) {
    if(beet()) cout << "Yes\n";
    else cout << "No\n";
  }
}