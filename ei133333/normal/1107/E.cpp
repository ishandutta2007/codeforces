#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 58;

int N, A[100];
string S;
int64 dp[100][101][2][101];

void chmax(int64 &a, int64 b) { a = max(a, b); }

void update(int come) {
  for(int type = 0; type < 2; type++) {
    for(int from = come; from < N; from++) {
      if(S[from] != type) break;
      dp[come][from + 1][type][from - come + 1] = 0;
    }
  }
  for(int type = 0; type < 2; type++) {
    vector< vector< int64 > > dp2(N + 1, vector< int64 >(N + 1, -INF));
    dp2[come][0] = 0;
    for(int from = come; from <= N; from++) {
      for(int to = from + 1; to <= N; to++) {
        for(int pre = 0; pre <= from - come; pre++) {
          if(dp2[from][pre] == -INF) continue;

          if(dp[from][to][1 ^ type][0] != -INF) {
            chmax(dp2[to][pre], dp2[from][pre] + dp[from][to][1 ^ type][0]);
          }

          for(int add = 0; add <= to - from; add++) {
            if(dp[from][to][type][add] == -INF) continue;
            chmax(dp2[to][pre + add], dp2[from][pre] + dp[from][to][type][add]);
          }

        }
      }

      for(int k = from - come; k >= 0; k--) {
        for(int l = k; l > 0; l--) {
          if(dp2[from][k] == -INF) continue;
          chmax(dp2[from][k - l], dp2[from][k] + A[l - 1]);
        }
        chmax(dp[come][from][type][k], dp2[from][k]);
      }
    }
  }
}


int main() {
  cin >> N;
  cin >> S;
  for(auto &c : S) c -= '0';
  for(int i = 0; i < N; i++) cin >> A[i];
  fill_n(***dp, 100 * 101 * 2 * 101, -INF);
  for(int i = N - 1; i >= 0; i--) update(i);
  cout << max(dp[0][N][0][0], dp[0][N][1][0]) << endl;
}