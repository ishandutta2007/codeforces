#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int K = 18;
const long long oo = 1LL << 60;

int phi[N];
long long sumPhi[N], f[K][N];
vector<int> floors[N];
vector<long long> sumC[N];

void init()
{
  iota(phi, phi + N, 0);
  for (int i = 2; i < N; i++)
    if (phi[i] == i)
      for (int j = i; j < N; j += i)
        phi[j] = phi[j] / i * (i - 1);

  for (int i = 2; i < N; i++)
    sumPhi[i] = sumPhi[i - 1] + phi[i];

  for (int i = 2; i < N; i++)
  {
    int j;
    for (j = 1; j * j <= i; j++)
    {
      int k = i / j;
      if (k > j)
        floors[i].push_back(k);
    }
    j--;
    for (; j; j--)
      floors[i].push_back(j);
    reverse(begin(floors[i]), end(floors[i]));

    int sz = size(floors[i]);
    sumC[i].resize(sz);
    sumC[i][0] = sumPhi[i];
    for (int j = 1; j < sz; j++)
      sumC[i][j] = sumC[i][j - 1] + sumPhi[i / floors[i][j]] * (floors[i][j] - floors[i][j - 1]);
  }
}

long long getC(int l, int r)
{
  if (r == 1)
    return 0;
  int sz = size(floors[r]);
  long long res = sumC[r][sz - 1];
  if (l == 0)
    return res;
  if (1LL * l * l <= r) res -= sumC[r][l - 1];
  else
  {
    int k = sz - r / l - 1;
    res -= sumC[r][k] + sumPhi[r / l] * (l - floors[r][k]);
  }
  return res;
}

void calc(int i, int low, int high, int optL, int optR)
{
  if (low > high)
    return;

  int mid = (low + high) / 2, optM = -1;
  f[i][mid] = oo;
  for (int j = optL; j <= min(mid - 1, optR); j++)
  {
    long long curF = f[i - 1][j] + getC(j, mid);
    if (curF < f[i][mid])
    {
      f[i][mid] = curF;
      optM = j;
    }
  }

  calc(i, low, mid - 1, optL, optM);
  calc(i, mid + 1, high, optM, optR);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  init();
  for (int i = 1; i < N; i++)
    f[0][i] = oo;
  for (int i = 1; i < K; i++)
    calc(i, 1, N - 1, 0, N - 1);


  int test;
  cin >> test;
  while (test--)
  {
    int n, k;
    cin >> n >> k;
    if (k > __lg(n)) cout << n << '\n';
    else cout << f[k][n] + n << '\n';
  }
}