#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int inf = 200000000;

#define MAX 1005

int N, M;

int a[MAX][MAX];
int ul[MAX][MAX];
int ur[MAX][MAX];
int dr[MAX][MAX];
int dl[MAX][MAX];
int tmp[MAX][MAX];

void rot(int t, int a[MAX][MAX], int N, int M) {
  for (int i = 0; i <= N + 1; ++i)
    for (int j = 0; j <= M + 1; ++j)
      tmp[i][j] = a[i][j];

  for (int i = 0; i <= M + 1; ++i) 
    for (int j = 0; j <= N + 1; ++j) 
      a[i][j] = tmp[j][M + 1 - i];

  if (t == 1) return;
  rot(t - 1, a, M, N);
}

void calc(int ul[MAX][MAX], int N, int M) {
  for (int i = 0; i <= N + 1; ++i) {
    for (int j = 0; j <= M + 1; ++j) {
      if (i == 0 || j == 0 || i == N + 1 || j == M + 1)
        ul[i][j] = -inf;
      else {
        ul[i][j] = a[i][j];
        ul[i][j] = max(ul[i][j], max(ul[i - 1][j], ul[i][j - 1]) + a[i][j]);
      }
    }
  }
}

const int mdx[] = { 0, -1 };
const int mdy[] = { -1, 0 };

const int fdx[] = { +1, 0 };
const int fdy[] = { 0, -1 };

int main(void)
{
  scanf("%d%d", &N, &M);

  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      scanf("%d", &a[i][j]);

  calc(ul, N, M);
  rot(1, a, N, M);
  calc(ur, M, N);
  rot(3, ur, M, N);
  rot(1, a, M, N);
  calc(dr, N, M);
  rot(2, dr, N, M);
  rot(1, a, N, M);
  calc(dl, M, N);
  rot(1, dl, M, N);

  int sol = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      for (int d = 0; d < 2; ++d) {
        sol = max(sol, 
          ul[i + mdx[d]][j + mdy[d]] + 
          dl[i + fdx[d]][j + fdy[d]] +
          dr[i - mdx[d]][j - mdy[d]] + 
          ur[i - fdx[d]][j - fdy[d]]);
      }
    }
  }

  printf("%d\n", sol);

  return 0;
}