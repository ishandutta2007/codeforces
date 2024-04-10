#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 200005

int N, M;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int v[MAXN];

int top;
int stk[MAXN];
int bio[MAXN];
int sol[MAXN];

vector< int > G[MAXN];
vector< int > W[MAXN];
vector< int > D[MAXN];

int main(void)
{
  scanf("%d%d", &N, &M);

  for (int i = 0; i < M; ++i) {
    scanf("%d%d%d", a + i, b + i, c + i);
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
    W[a[i]].push_back(c[i]);
    W[b[i]].push_back(c[i]);
    D[a[i]].push_back(+i + 1);
    D[b[i]].push_back(-i - 1);
    v[a[i]] += c[i];
    v[b[i]] += c[i];
  }

  for (int i = 1; i <= N; ++i)
    v[i] /= 2;

  stk[top++] = 1;
  bio[1] = 1;
  
  while (top) {
    int n = stk[--top];

    for (int i = 0; i < G[n].size(); ++i) {
      if (bio[G[n][i]]) continue;

      v[G[n][i]] -= W[n][i];

      if (D[n][i] > 0) sol[+D[n][i] - 1] = 0;
      if (D[n][i] < 0) sol[-D[n][i] - 1] = 1;

      if (v[G[n][i]] == 0 && G[n][i] != N) 
        stk[top++] = G[n][i], bio[G[n][i]] = 1;
    }
  }

  for (int i = 0; i < M; ++i)
    printf("%d\n", sol[i]);

  return 0;
}