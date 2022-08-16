#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

const int INF = 1 << 30;

int N, M, A[400];
int S[250000], F[250000], C[2500000], R[250000];
vector< int > dp[400][400];


int main() {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) scanf("%d", &A[i]);

  for(int i = 0; i < M; i++) {
    scanf("%d %d %d %d", &S[i], &F[i], &C[i], &R[i]);
    --S[i], --F[i];
  }

  for(int i = N - 1; i >= 0; i--) {
    for(int j = i; j >= 0; j--) {
      dp[i][j].assign(N + 1, INF);
    }
    for(int j = N; j >= 0; j--) dp[i][i][j] = 0;
    for(int j = i - 1; j >= 0; j--) {
      for(int l = N; l >= 1; l--) {
        int ok = i + 1, ng = j;
        while(ok - ng > 1) {
          int mid = (ok + ng) / 2;
          if(A[mid] - A[j] >= dp[i][mid][l - 1]) ok = mid;
          else ng = mid;
        }
        for(int p = max(ok - 1, j + 1); p <= min(ok + 1, i); p++) {
          dp[i][j][l] = min(dp[i][j][l], max(A[p] - A[j], dp[i][p][l - 1]));
        }
      }
    }
  }

  int64 ret = 0;
  for(int i = 0; i < M; i++) {
    ret = max(ret, 1LL * dp[F[i]][S[i]][min(N, R[i] + 1)] * C[i]);
  }
  cout << ret << endl;
}