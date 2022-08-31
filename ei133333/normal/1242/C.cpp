#include <bits/stdc++.h>
 
using namespace std;
 
using int64 = long long;
const int mod = 0;
 
 
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
  int K;
  cin >> K;
  vector< int64 > be[15];
  int64 sum = 0;
  map< int64, int > pos;
  vector< int64 > cur(K);
  for(int i = 0; i < K; i++) {
    int x;
    cin >> x;
    be[i].resize(x);
    cin >> be[i];
    for(auto &j : be[i]) {
      cur[i] += j;
      pos[j] = i;
    }
    sum += cur[i];
  }
  if(sum != 0) {
    if(sum % K != 0) {
      cout << "No" << endl;
      return 0;
    }
    sum /= K;
  }
 
  vector< pair< int, int > > seq;
 
  vector< int > ok(1 << K);
  vector< vector< pair< int, int > > > dump(1 << K);
 
  auto dfs = MFP([&](auto dfs, int end, int idx, int64 send, int bit) -> void {
    cur[idx] -= send;
    seq.emplace_back(idx, send);
    if(idx == end) {
      if(cur[idx] == sum && dump[bit].empty()) {
        ok[bit] = true;
        dump[bit] = seq;
      }
    } else {
      int64 need = sum - cur[idx];
      if(pos.count(need)) {
        int to = pos[need];
        if((bit & (1 << to)) == 0) {
          dfs(end, (int) pos[need], need, bit | (1 << to));
        }
      }
    }
    seq.pop_back();
    cur[idx] += send;
  });
 
  for(int i = 0; i < K; i++) {
    if(cur[i] == sum) ok[1 << i] = true;
    for(int64 j : be[i]) {
      for(int k = 0; k < K; k++) {
        if(i == k) continue;
        cur[k] += j;
        dfs(k, i, j, (int) (1 << i));
        cur[k] -= j;
      }
    }
  }
 
  auto dp = make_v< int >(1 << K);
  fill_v(dp, -1);
  auto rec = MFP([&](auto rec, int bit) -> int {
    if(bit == 0) return true;
    if(~dp[bit]) return dp[bit];
    if(ok[bit]) return dp[bit] = true;
    for(int i = bit; i > 0; i = (i - 1) & bit) {
      if(i == bit) continue;
      if(rec(i) && rec(i ^ bit)) return dp[bit] = true;
    }
    return dp[bit] = false;
  });
 
 
  vector< int > A(K), B(K);
 
  auto dumpp = [&](int bit) {
    if(__builtin_popcount(bit) == 1) {
      for(int k = 0; k < K; k++) {
        if((bit >> k) & 1) {
          A[k] = be[k][0];
          B[k] = k;
          break;
        }
      }
    } else {
      for(int i = 0; i < dump[bit].size(); i++) {
        auto& p = dump[bit][i];
        A[p.first]=p.second;
        B[p.first]=dump[bit][(i+dump[bit].size()-1)%dump[bit].size()].first;
      }
    }
  };
 
  auto rec2 = MFP([&](auto rec2, int bit) -> void {
    if(bit == 0) return;
    if(ok[bit]) {
      dumpp(bit);
      return;
    }
    for(int i = bit; i > 0; i = (i - 1) & bit) {
      if(i == bit) continue;
      if(rec(i) && rec(i ^ bit)) {
        rec2(i);
        rec2(i ^ bit);
        return;
      }
    }
  });
 
  if(rec((1 << K) - 1)) {
    cout << "Yes\n";
    rec2((1 << K) - 1);
    for(int i = 0; i < K; i++) {
      cout << A[i] << " " << B[i] + 1 << endl;
    }
  } else {
    cout << "No\n";
  }
}