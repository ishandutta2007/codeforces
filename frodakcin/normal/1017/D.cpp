#include <iostream>
#include <cstdio>

#include <vector>
#include <array>
#include <algorithm>

using namespace std;

const int MN = 12;
const int MQ = 5e5 + 100;
int N, M, Q;
int X;
int c[1<<MN];
using i2 = array<int, 2>;
using vi2 = vector<i2>;
#define sz size()
#define pb push_back
vi2 q[1<<MN];
char s[MN + 5];
int u[MN], v[1<<MN], o[1<<MN];
int next(void)
{
  scanf(" %s", s);
  int x = 0;
  for(int i = 0;i < N;i++)
    if(s[i]=='1')
      x|=1<<i;
  return x;
}
int f[MQ];

int main(void)
{
  scanf("%d%d%d", &N, &M, &Q);
  X = (1<<N)-1;
  for(int i = 0;i < N;i++) scanf("%d", u + i);
  for(int i = 0;i < 1<<N;i++)
  {
    for(int j = 0;j < N;j++)
      if(i&1<<j)
        v[i] += u[j];
    o[i] = i;
  }
  sort(o, o + (1<<N), [](const int& a, const int& b){return v[a]<v[b];});
  for(int i = 0;i < M;i++)
    c[next()]++;
  for(int i = 0, x, y;i < Q;i++)
  {
    x = next(), scanf("%d", &y);
    q[x].pb({y, i});
  }
  for(int i = 0;i < 1<<N;i++)
    sort(q[i].begin(), q[i].end(), [](const i2& a, const i2& b){return a[0]<b[0];});
  for(int m = 0, i, j, k;m < 1<<N;m++)
  {
    for(i=j=k=0;i < q[m].sz;i++)
    {
      for(;j < 1<<N&&v[o[j]] <= q[m][i][0];j++)
        k += c[o[j]^m^X];
      f[q[m][i][1]] = k;
    }
  }
  for(int i = 0;i < Q;i++)
    printf("%d\n", f[i]);
  return 0;
}