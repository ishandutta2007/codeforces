#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

inline void chmin(int64 &a, int64 b) { a = min(a, b); }

using Mat = vector< vector< int64 >>;

int main()
{
  int X, K, N, Q, C[8];

  cin >> X >> K >> N >> Q;
  for(int i = 0; i < K; i++) {
    cin >> C[i];
  }
  int64 ret = 0;
  vector< pair< int, int > > beet;
  for(int i = 0; i < Q; i++) {
    int P, W;
    cin >> P >> W;
    --P;
    if(P + X >= N) ret += W;
    else beet.emplace_back(P, W);
  }
  beet.emplace_back(0, 0);
  beet.emplace_back(N - X, 0);
  sort(begin(beet), end(beet));

  vector< Mat > mats(30, Mat(1 << K, vector< int64 >(1 << K, INF)));
  vector< int > que;
  for(int i = 0; i < 1 << K; i++) {
    if(__builtin_popcount(i) != X) {
      continue;
    }
    que.emplace_back(i);

    if(i & 1) {
      int nextbit = i >> 1;
      for(int j = 0; j < K; j++) {
        if((nextbit >> j) & 1) continue;
        mats[0][i][nextbit | (1 << j)] = C[j];
      }
    } else {
      mats[0][i][i >> 1] = 0;
    }
  }

  for(int i = 1; i < 30; i++) {
    for(int j : que) {
      for(int k : que) {
        for(int l : que) {
          chmin(mats[i][j][l], mats[i - 1][j][k] + mats[i - 1][k][l]);
        }
      }
    }
  }

  vector< int64 > dp(1 << K, INF);
  dp[(1 << X) - 1] = 0;
  for(int i = 1; i < beet.size(); i++) {
    int sa = beet[i].first - beet[i - 1].first;
    for(int j = 0; j < 30; j++) {
      if((sa >> j) & 1) {
        vector< int64 > dp2(1 << K, INF);
        for(int k : que) {
          for(int l : que) {
            chmin(dp2[l], dp[k] + mats[j][k][l]);
          }
        }
        dp2.swap(dp);
      }
    }
    for(int j = 0; j < (1 << K); j++) {
      if(j & 1) dp[j] += beet[i].second;
    }
  }
  cout << dp[(1 << X) - 1] + ret << endl;
}