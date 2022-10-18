#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
using namespace std;

#define MAX 505
#define MAX2 1010

int N, M, K;
int a, b;

int t[MAX];

int cnt[MAX][MAX];
int deg[MAX];

int node[MAX];

double tmp[MAX][MAX];
double G[MAX2][MAX2];
double P[MAX][MAX];
double S[MAX][MAX];

double B[MAX];
double Q[MAX];
double p[MAX];

void invert(double M[MAX2][MAX2], int n) {
  for (int i = 0; i < n; ++i)
    M[i][i + n] = 1.0;

  int r = 0;
  for (int c = 0; c < n; ++c) {
    int best = r;
    for (int i = r + 1; i < n; ++i) 
      if (fabs(M[i][c]) > fabs(M[best][c])) 
        best = i;

    for (int i = 0; i < 2 * n; ++i)
      swap(M[r][i], M[best][i]);

    double div = M[r][c];
    for (int i = 0; i < 2 * n; ++i)
      M[r][i] /= div;

    for (int i = 0; i < n; ++i) {
      if (i == r) continue;
      double mul = M[i][c];
      for (int j = 0; j < 2 * n; ++j)
        M[i][j] -= mul * M[r][j];
    }

    ++r;
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      M[i][j] = M[i][j + n];
}

void mult(double A[MAX][MAX], double B[MAX][MAX], int n) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      tmp[i][j] = 0.0;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
        tmp[i][j] += A[i][k] * B[k][j];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      A[i][j] = tmp[i][j];
}

int main(void)
{
  scanf("%d%d%d", &N, &M, &K);

  for (int i = 0; i < N; ++i)
    scanf("%d", t + i);

  for (int i = 0; i < M; ++i) {
    scanf("%d%d", &a, &b); --a; --b;
    ++cnt[a][b];
    ++cnt[b][a];
    ++deg[a];
    ++deg[b];
  }

  int n = 0;
  for (int i = 0, r = 0; i < N; ++i) {
    if (t[i]) continue;
    node[r] = i;
    for (int j = 0, c = 0; j < N; ++j) {
      if (t[j]) continue;
      G[r][c] = (double)cnt[i][j] / (double)deg[i];
      if (r == c) G[r][c] -= 1.0;
      ++c;
    }
    ++r;
    ++n;
  }

  invert(G, n);

  int m = 0;
  for (int i = 0, c = 0; i < N; ++i) {
    if (!t[i]) continue; // ovaj je rupa
    for (int j = 0; j < n; ++j) {
      B[j] = -(double)cnt[node[j]][i] / (double)deg[node[j]];
      p[j] = 0.0;
    }

    for (int j = 0; j < n; ++j) 
      for (int k = 0; k < n; ++k)
        p[j] += G[j][k] * B[k];
    
    Q[i] = p[0];
     
    for (int j = 0, r = 0; j < N; ++j) {
      if (!t[j]) continue;
      // od j do i vjerojatnost
      P[r][c] = (double)cnt[j][i] / (double)deg[j];
      for (int k = 0; k < n; ++k) 
        P[r][c] += (double)cnt[j][node[k]] / (double)deg[j] * p[k];
      ++r;
    }
    ++c;
    ++m;
  }

  for (int i = 0; i < m; ++i)
    S[i][i] = 1.0;

  K -= 2;
  for (int i = 0; (1 << i) <= K; ++i) {
    if (((K >> i) & 1) == 1) 
      mult(S, P, m);
    mult(P, P, m);
  }
  
  double sol = 0.0;
  for (int i = 0, c = 0; i < N; ++i) {
    if (t[i]) {
      sol += Q[i] * S[c][m - 1];
      ++c;
    }
  }

  printf("%.6lf\n", sol);

  return 0;
}