// Codeforces Beta Round #2
// Problem B -- The least round way
#include <cstdio>
#include <cstring>

#define maxN 1001
#define INF 1000001

using namespace std;

int n, a[maxN][maxN], b[maxN][maxN], f[maxN][maxN], zero;
char *step;

bool exsit()
{
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= n; ++ j)
      if(a[i][j] == 0)
        return true;
  return false;
}

void solve(int &zero, char *&step)
{
  for(int i = 0; i <= n; ++ i)
    for(int j = 0; j <= n; ++ j)
      f[i][j] = INF;     
  f[0][1] = f[1][0] = 0;
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= n; ++ j)
      f[i][j] = (f[i - 1][j] < f[i][j - 1]? f[i - 1][j]: f[i][j - 1]) + b[i][j];
  zero = f[n][n], step = new char[n + n];
  for(int i = n, j = n; i != 1 || j != 1;)
    if(1 < i && f[i - 1][j] + b[i][j] == f[i][j])
      step[i + j - 3] = 'D', i --;
    else
      step[i + j - 3] = 'R', j --;
  step[(n - 1) + (n - 1)] = '\0';
}

int get_power(int p, int n)
{
  int e = 0;
  while(n % p == 0)
    n /= p, e ++;
  return e;
}

int main()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= n; ++ j)
      scanf("%d", &a[i][j]);
  zero = INF;
  int temp_zero; char *temp_step;
  if(exsit())
  {
    for(int i = 1; i <= n; ++ i)
      for(int j = 1; j <= n; ++ j)
        b[i][j] = (a[i][j] == 0)? -1: 0;
    solve(temp_zero, temp_step);
    if(1 < zero)
      zero = 1, step = temp_step;
  }
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= n; ++ j)
      b[i][j] = (a[i][j] == 0)? INF: get_power(2, a[i][j]);
  solve(temp_zero, temp_step);
  if(temp_zero < zero)
    zero = temp_zero, step = temp_step;
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= n; ++ j)
      b[i][j] = (a[i][j] == 0)? INF: get_power(5, a[i][j]);
  solve(temp_zero, temp_step);
  if(temp_zero < zero)
    zero = temp_zero, step = temp_step;
  printf("%d\n%s\n", zero, step);
  return 0;
}