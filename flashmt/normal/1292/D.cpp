#include <bits/stdc++.h>
using namespace std;
const int K = 5005;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> cnt(K);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    cnt[max(x, 1)]++;
  }

  int numPrime = 0;
  vector<int> id(K);
  for (int i = 2; i < K; i++)
  {
    int isPrime = 1;
    for (int j = 2; j * j <= i; j++)
      if (i % j == 0)
        isPrime = 0;
    if (isPrime)
      id[i] = ++numPrime;
  }

  vector<vector<int>> p(K, vector<int>(numPrime + 1));
  for (int i = 2; i < K; i++)
  {
    p[i] = p[i - 1];
    int x = i;
    for (int j = 2; j * j <= x; j++)
      while (x % j == 0)
      {
        p[i][id[j]]++;
        x /= j;
      }
    if (x > 1)
      p[i][id[x]]++;
  }

  long long sumAll = 0;
  vector<int> maxP(K);
  for (int i = 2; i < K; i++)
    for (int j = 1; j <= numPrime; j++)
      if (p[i][j])
      {
        sumAll += cnt[i] * p[i][j];
        maxP[i] = j;
      }

  long long ans = sumAll, curSum = sumAll;
  while (1)
  {
    vector<int> cntMaxP(numPrime + 1);
    for (int i = 1; i < K; i++)
      cntMaxP[maxP[i]] += cnt[i];
    int best = 0;
    for (int i = 1; i < numPrime; i++)
      if (cntMaxP[i] > cntMaxP[best])
        best = i;
    if (!best)
      break;

    curSum += n - cntMaxP[best] * 2;
    ans = min(ans, curSum);

    for (int i = 0; i < K; i++)
      if (maxP[i] != best) maxP[i] = 0;
      else if (maxP[i])
      {
        if (!--p[i][maxP[i]])
          maxP[i]--;
      }
  }

  cout << ans << endl;
}