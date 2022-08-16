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

int dp[252][252][252];
vector< int > nxt[100001];

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  fill_n(**dp, 252 * 252 * 252, inf);
  vector< int > to(26, inf);
  nxt[N] = to;
  for(int i = N - 1; i >= 0; i--) {
    to[S[i] - 'a'] = i;
    nxt[i] = to;
  }

  dp[0][0][0] = 0;
  vector< int > u[3];


  while(Q--) {
    char T;
    cin >> T;
    int idx;
    cin >> idx;
    --idx;

    if(T == '+') {
      char c;
      cin >> c;
      c -= 'a';
      u[idx].push_back(c);


      if(idx == 0) {
        for(int i = u[0].size() - 1; i <= u[0].size(); i++) {
          for(int j = 0; j <= u[1].size(); j++) {
            for(int k = 0; k <= u[2].size(); k++) {
              if(dp[i][j][k] != inf) {
                if(i < u[0].size()) {
                  chmin(dp[i + 1][j][k], nxt[dp[i][j][k]][u[0][i]] + 1);
                }
                if(j < u[1].size()) chmin(dp[i][j + 1][k], nxt[dp[i][j][k]][u[1][j]] + 1);
                if(k < u[2].size()) chmin(dp[i][j][k + 1], nxt[dp[i][j][k]][u[2][k]] + 1);
              }
            }
          }
        }
      } else if(idx == 1) {
        for(int j = u[1].size() - 1; j <= u[1].size(); j++) {
          for(int i = 0; i <= u[0].size(); i++) {
            for(int k = 0; k <= u[2].size(); k++) {
              if(dp[i][j][k] != inf) {
                if(i < u[0].size()) chmin(dp[i + 1][j][k], nxt[dp[i][j][k]][u[0][i]] + 1);
                if(j < u[1].size()) chmin(dp[i][j + 1][k], nxt[dp[i][j][k]][u[1][j]] + 1);
                if(k < u[2].size()) chmin(dp[i][j][k + 1], nxt[dp[i][j][k]][u[2][k]] + 1);
              }
            }
          }
        }
      } else {
        for(int k = u[2].size() - 1; k <= u[2].size(); k++) {
          for(int i = 0; i <= u[0].size(); i++) {
            for(int j = 0; j <= u[1].size(); j++) {
              if(dp[i][j][k] != inf) {
                if(i < u[0].size()) chmin(dp[i + 1][j][k], nxt[dp[i][j][k]][u[0][i]] + 1);
                if(j < u[1].size()) chmin(dp[i][j + 1][k], nxt[dp[i][j][k]][u[1][j]] + 1);
                if(k < u[2].size()) chmin(dp[i][j][k + 1], nxt[dp[i][j][k]][u[2][k]] + 1);
              }
            }
          }
        }
      }

    } else {
      u[idx].pop_back();

      if(idx == 0) {
        for(int j = 0; j <= u[1].size(); j++) {
          for(int k = 0; k <= u[2].size(); k++) {
            dp[u[0].size() + 1][j][k] = inf;
          }
        }
      } else if(idx == 1) {
        for(int j = 0; j <= u[0].size(); j++) {
          for(int k = 0; k <= u[2].size(); k++) {
            dp[j][u[1].size() + 1][k] = inf;
          }
        }
      } else {
        for(int j = 0; j <= u[0].size(); j++) {
          for(int k = 0; k <= u[1].size(); k++) {
            dp[j][k][u[2].size() + 1] = inf;
          }
        }
      }

    }


    if(dp[u[0].size()][u[1].size()][u[2].size()] != inf) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }


}