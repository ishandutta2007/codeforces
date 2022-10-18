#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair< int, int > pi;

#define MAXN 100005
#define mp make_pair

int N, mod;
int a[MAXN];
int b[MAXN];
pi v[2 * MAXN];

int f[2 * MAXN];
int p[2 * MAXN];

void fact(int n, int s) {
  while (f[n] != 1) {
    p[f[n]] += s;
    n /= f[n];
  }
}

int main(void)
{
  scanf("%d", &N);

  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i < 2 * MAXN; ++i) {
    if (f[i] == 0) {
      f[i] = i;
      for (int j = 2 * i; j < 2 * MAXN; j += i)
        f[j] = i;
    }
  }

  for (int i = 0; i < N; ++i)
    scanf("%d", a + i);
  
  for (int i = 0; i < N; ++i)
    scanf("%d", b + i);

  scanf("%d", &mod);

  for (int i = 0; i < N; ++i)
    v[i] = mp(a[i], i);
  
  for (int i = 0; i < N; ++i)
    v[i + N] = mp(b[i], i);

  sort(v, v + (2 * N));
  
  ll sol = 1;

  for (int i = 0, j; i < 2 * N; i = j) {
    for (j = i + 1; v[i].first == v[j].first && j < 2 * N; ++j);
    for (int k = 1; k <= j - i; ++k)
      fact(k, +1);

    for (int k = i, l; k < j; k = l) {
      for (l = k + 1; v[k] == v[l] && l < j; ++l);
      for (int m = 1; m <= l - k; ++m)
        fact(m, -1);
    }
  }

  for (int i = 0; i < 2 * N; ++i) 
    for (int j = 0; j < p[i]; ++j) 
      sol = (sol * i) % mod;

  printf("%d\n", (int)sol);

  return 0;
}