#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100005

int N;
int a, b;
int dad[MAXN];
int init[MAXN];
int goal[MAXN];

vector< int > T[MAXN];
vector< int > flips;

int solve(int n, int f1, int f2) {
  int sol = 0;

  if ((init[n] ^ f1) != goal[n]) {
    flips.push_back(n);
    f1 ^= 1;
    sol = 1;
  }

  for (int i = 0; i < T[n].size(); ++i) {
    if (T[n][i] == dad[n]) continue;
    dad[T[n][i]] = n;
    sol += solve(T[n][i], f2, f1);
  }

  return sol;
}

int main(void)
{
  scanf("%d", &N);

  for (int i = 0; i < N - 1; ++i) {
    scanf("%d%d", &a, &b);
    T[a].push_back(b);
    T[b].push_back(a);
  }

  for (int i = 1; i <= N; ++i)
    scanf("%d", &init[i]);

  for (int i = 1; i <= N; ++i)
    scanf("%d", &goal[i]);

  printf("%d\n", solve(1, 0, 0));
  
  for (auto flip : flips) 
    printf("%d\n", flip);

  return 0;
}