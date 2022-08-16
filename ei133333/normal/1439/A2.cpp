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
  int T;
  cin >> T;
  while(T--) {
    int H, W;
    cin >> H >> W;
    auto S = make_v< string >(H);
    cin >> S;
    for(auto &s : S) for(auto &c : s) c -= '0';
 
    vector< pair< int, int > > ans;
    for(int i = 0; i + 1 < H; i++) {
      for(int j = 0; j + 2 < W; j++) {
        auto a = S[i][j];
        auto b = S[i + 1][j];
        if(a == 0 and b == 0) continue;
        if(a == 1 and b == 1) {
          ans.emplace_back(i, j);
          ans.emplace_back(i + 1, j);
          ans.emplace_back(i, j + 1);
          S[i][j] ^= 1;
          S[i + 1][j] ^= 1;
          S[i][j + 1] ^= 1;
        } else if(a == 1) {
          ans.emplace_back(i, j);
          ans.emplace_back(i, j + 1);
          ans.emplace_back(i + 1, j + 1);
          S[i][j] ^= 1;
          S[i][j + 1] ^= 1;
          S[i + 1][j + 1] ^= 1;
        } else {
          ans.emplace_back(i + 1, j);
          ans.emplace_back(i, j + 1);
          ans.emplace_back(i + 1, j + 1);
          S[i + 1][j] ^= 1;
          S[i][j + 1] ^= 1;
          S[i + 1][j + 1] ^= 1;
        }
      }
    }
    for(int i = 0; i + 1 < H; i++) {
      auto a = S[i][W - 2];
      auto b = S[i][W - 1];
      if(a == 0 and b == 0) continue;
 
      if(a == 1 and b == 1) {
        ans.emplace_back(i, W - 2);
        ans.emplace_back(i, W - 1);
        ans.emplace_back(i + 1, W - 2);
        S[i][W - 2] ^= 1;
        S[i][W - 1] ^= 1;
        S[i + 1][W - 2] ^= 1;
      } else if(a == 1) {
        ans.emplace_back(i, W - 2);
        ans.emplace_back(i + 1, W - 1);
        ans.emplace_back(i + 1, W - 2);
        S[i][W - 2] ^= 1;
        S[i + 1][W - 1] ^= 1;
        S[i + 1][W - 2] ^= 1;
      } else {
        ans.emplace_back(i, W - 1);
        ans.emplace_back(i + 1, W - 1);
        ans.emplace_back(i + 1, W - 2);
        S[i][W - 1] ^= 1;
        S[i + 1][W - 1] ^= 1;
        S[i + 1][W - 2] ^= 1;
      }
    }
    vector< pair< int, int > > b[2];
    b[S[H - 2][W - 2]].emplace_back(H - 2, W - 2);
    b[S[H - 2][W - 1]].emplace_back(H - 2, W - 1);
    b[S[H - 1][W - 2]].emplace_back(H - 1, W - 2);
    b[S[H - 1][W - 1]].emplace_back(H - 1, W - 1);
 
    if(b[0].size() == 4) {
 
    } else if(b[0].size() == 1) {
      ans.emplace_back(b[1][0]);
      ans.emplace_back(b[1][1]);
      ans.emplace_back(b[1][2]);
    } else if(b[0].size() == 2) {
      ans.emplace_back(b[1][0]);
      ans.emplace_back(b[0][0]);
      ans.emplace_back(b[0][1]);
 
      ans.emplace_back(b[0][0]);
      ans.emplace_back(b[0][1]);
      ans.emplace_back(b[1][1]);
    } else if(b[0].size() == 3) {
      // 000, 1
      ans.emplace_back(b[0][0]); // 0->1
      ans.emplace_back(b[0][1]); // 0->1
      ans.emplace_back(b[1][0]); // 1->0
 
      S[b[0][0].first][b[0][0].second] ^= 1;
      S[b[0][1].first][b[0][1].second] ^= 1;
      S[b[1][0].first][b[1][0].second] ^= 1;
 
      // 110, 0
      b[0].clear();
      b[1].clear();
 
      b[S[H - 2][W - 2]].emplace_back(H - 2, W - 2);
      b[S[H - 2][W - 1]].emplace_back(H - 2, W - 1);
      b[S[H - 1][W - 2]].emplace_back(H - 1, W - 2);
      b[S[H - 1][W - 1]].emplace_back(H - 1, W - 1);
 
      ans.emplace_back(b[1][0]);
      ans.emplace_back(b[0][0]);
      ans.emplace_back(b[0][1]);
 
      ans.emplace_back(b[0][0]);
      ans.emplace_back(b[0][1]);
      ans.emplace_back(b[1][1]);
    } else {
      ans.emplace_back(b[1][0]);
      ans.emplace_back(b[1][1]);
      ans.emplace_back(b[1][2]);
      S[b[1][0].first][b[1][0].second] ^= 1;
      S[b[1][1].first][b[1][1].second] ^= 1;
      S[b[1][2].first][b[1][2].second] ^= 1;
      b[0].clear();
      b[1].clear();
 
 
      b[S[H - 2][W - 2]].emplace_back(H - 2, W - 2);
      b[S[H - 2][W - 1]].emplace_back(H - 2, W - 1);
      b[S[H - 1][W - 2]].emplace_back(H - 1, W - 2);
      b[S[H - 1][W - 1]].emplace_back(H - 1, W - 1);
 
 
      cout << b[0].size() << "\n";
 
      // 000, 1
      ans.emplace_back(b[0][0]); // 0->1
      ans.emplace_back(b[0][1]); // 0->1
      ans.emplace_back(b[1][0]); // 1->0
 
      S[b[0][0].first][b[0][0].second] ^= 1;
      S[b[0][1].first][b[0][1].second] ^= 1;
      S[b[1][0].first][b[1][0].second] ^= 1;
 
      // 110, 0
      b[0].clear();
      b[1].clear();
 
      b[S[H - 2][W - 2]].emplace_back(H - 2, W - 2);
      b[S[H - 2][W - 1]].emplace_back(H - 2, W - 1);
      b[S[H - 1][W - 2]].emplace_back(H - 1, W - 2);
      b[S[H - 1][W - 1]].emplace_back(H - 1, W - 1);
 
      ans.emplace_back(b[1][0]);
      ans.emplace_back(b[0][0]);
      ans.emplace_back(b[0][1]);
 
      ans.emplace_back(b[0][0]);
      ans.emplace_back(b[0][1]);
      ans.emplace_back(b[1][1]);
 
 
 
    }
 
    cout << ans.size() / 3 << "\n";
    for(auto &p : ans) p.first++, p.second++;
    for(int i = 0; i < ans.size(); i += 3) {
      cout << ans[i] << " " << ans[i + 1] << " " << ans[i + 2] << "\n";
    }
  }
}