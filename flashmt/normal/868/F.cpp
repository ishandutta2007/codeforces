#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int K = 22;
const long long oo = 1LL << 60;

int n, k, a[N];
long long f[K][N];
int curL, curR, cnt[N];
long long cost;

void updateCnt(int l, int r)
{
  while (curL > l)
    cost += cnt[a[--curL]]++;
  while (curL < l)
    cost -= --cnt[a[curL++]];
  while (curR < r)
    cost += cnt[a[++curR]]++;
  while (curR > r)
    cost -= --cnt[a[curR--]];
}

void calc(int i, int low, int high, int optL, int optR)
{
  if (low > high)
    return;

  int mid = (low + high) / 2, optM = -1;
  f[i][mid] = oo;
  for (int j = min(mid - 1, optR); j >= optL; j--)
  {
    updateCnt(j + 1, mid);
    long long curF = f[i - 1][j] + cost;
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
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  curL = 1;
  curR = n;
  for (int i = 1; i <= n; i++)
  {
    f[0][i] = oo;
    cost += cnt[a[i]]++;
  }

  for (int i = 1; i <= k; i++)
    calc(i, 1, n, 0, n);
  cout << f[k][n] << endl;
}