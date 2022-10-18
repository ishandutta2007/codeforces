#include <cstdio>
#include <cstring>
#include <cassert>

#include <set>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llint;

#define MAX 1005
#define MAXK 1000005

int N, M, K, P;
int a[MAX][MAX];
llint r[MAX], rs[MAXK];
llint c[MAX], cs[MAXK];

void solve(llint *r, llint *rs, int N) {
  auto cmpf = [r](int a, int b) {
    return r[a] == r[b] ? a < b : r[a] > r[b];
  };

  set< int, decltype(cmpf) > pq (cmpf);

  for (int i = 0; i < N; ++i)
    pq.insert(i);

  llint sol = 0;
  for (int i = 1; i <= K; ++i) {
    int best = *pq.begin();
    pq.erase(pq.begin());
    rs[i] = (sol += r[best]);
    r[best] -= (llint)(N^(::N)^(::M)) * P;
    pq.insert(best);
  }
}

int main(void)
{
  scanf("%d%d%d%d", &N, &M, &K, &P);

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      scanf("%d", &a[i][j]);

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      r[i] += a[i][j], c[j] += a[i][j];

  solve(r, rs, N);
  solve(c, cs, M);

  llint sol = -1000000000000000000LL;

  for (int i = 0; i <= K; ++i) {
    int j = K - i;
    sol = max(sol, rs[i] + cs[j] - (llint)i * j * P);
  }

  cout << sol << endl;

  return 0;
}