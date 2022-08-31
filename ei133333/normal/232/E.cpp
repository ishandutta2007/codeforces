#include<bits/stdc++.h>

using namespace std;

int N, M, Q;
char S[500][501];
int A[600000], B[600000], C[600000], D[600000], E[600000];
vector< vector< int > > g;
bitset< 500 > latte[501][501], malta[501][501];

void rec(int l, int r, vector< int > query)
{
  if(query.empty()) return;
  int mid = (l + r) >> 1;

  for(int i = mid; i >= l; i--) {
    for(int j = M - 1; j >= 0; j--) {
      latte[i][j].reset();
      if(S[i][j] != '.') continue;
      if(i == mid) latte[i][j][j] = true;
      if(i < mid) latte[i][j] |= latte[i + 1][j];
      if(j < M - 1) latte[i][j] |= latte[i][j + 1];
    }
  }
  for(int i = mid; i < r; i++) {
    for(int j = 0; j < M; j++) {
      malta[i][j].reset();
      if(S[i][j] != '.') continue;
      if(i == mid) malta[i][j][j] = true;
      if(i > mid) malta[i][j] |= malta[i - 1][j];
      if(j > 0) malta[i][j] |= malta[i][j - 1];
    }
  }
  vector< int > LL, RR;
  for(int i : query) {
    if(C[i] < mid) LL.push_back(i);
    else if(A[i] > mid) RR.push_back(i);
    else E[i] = (latte[A[i]][B[i]] & malta[C[i]][D[i]]).any();
  }
  rec(l, mid, LL);
  rec(mid + 1, r, RR);
}

int main()
{
  scanf("%d %d", &N, &M);
  g.resize(N * M);
  for(int i = 0; i < N; i++) {
    scanf("%s", S[i]);
  }
  scanf("%d", &Q);
  for(int i = 0; i < Q; i++) {
    scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    --A[i], --B[i], --C[i], --D[i];
  }
  vector< int > S(Q);
  iota(begin(S), end(S), 0);
  rec(0, N, S);
  for(int i = 0; i < Q; i++) puts(E[i] ? "Yes" : "No");
}