#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 300005

int N, M;
int a, b;
int in[MAXN];
int s[MAXN], top;

int g[MAXN][3];
int d[MAXN];
int r[MAXN];
int c[MAXN];

int main(void)
{
  scanf("%d%d", &N, &M);

  for (int i = 0; i < M; ++i) {
    scanf("%d%d", &a, &b); --a; --b;
    g[a][d[a]++] = b; r[a] = d[a];
    g[b][d[b]++] = a; r[b] = d[b];
  }

  for (int i = 0; i < N; ++i)
    if (r[i] > 1) s[top++] = i, in[i] = 1;

  while (top) {
    int n = s[--top];
    in[n] = 0;

    if (r[n] <= 1) continue;

    c[n] ^= 1;
    r[n] = d[n] - r[n];

    for (int i = 0; i < d[n]; ++i) {
      if (c[n] != c[g[n][i]]) {
        --r[g[n][i]];
      } else{
        if (++r[g[n][i]] > 1 && !in[g[n][i]]) s[top++] = g[n][i], in[g[n][i]] = 1;
      }
    }
  }

  for (int i = 0; i < N; ++i)
    putchar(c[i] + '0');
  putchar('\n');

  return 0;
}