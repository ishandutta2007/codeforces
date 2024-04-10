#include <bits/stdc++.h>
using namespace std;
const int K = 128000;

int main()
{
  int n, mod;
  cin >> n >> mod;

  vector<long long> f(K * 2);
  for (int i = K; i < K * 2; i++)
    f[i] = 1;

  vector<long long> ways(n + 1);
  for (int i = 2; i < n; i++)
  {
    vector<long long> newF(K * 2);
    int maxJ = i * (i - 1) / 2;
    long long sum = 0;
    for (int j = -maxJ - (i - 1); j <= -maxJ + (i - 1); j++)
    {
      sum += (f[j + K] - f[j - 1 + K] + mod) * (i - abs(-maxJ - j));
      sum %= mod;
    }

    for (int j = -maxJ + K; j <= maxJ + K; j++)
    {
      newF[j] = (newF[j - 1] + sum) % mod;
      sum = (sum + f[j + i] - f[j]) % mod;
      sum = (sum - f[j] + f[j - i] + mod) % mod;
    }
    for (int j = maxJ + K + 1; j < K * 2; j++)
      newF[j] = newF[j - 1];
    f = newF;

    for (int j = 1; j < i + 1; j++)
      for (int k = j + 1; k <= i + 1; k++)
        ways[i + 1] = (ways[i + 1] + f[maxJ + K] - f[k - j + K] + mod) % mod;
  }

  long long ans = 0;
  for (int i = 3; i <= n; i++)
  {
    long long toAdd = ways[i];
    for (int j = i + 1; j <= n; j++)
      toAdd = toAdd * j % mod;
    ans = (ans + toAdd) % mod;
  }
  cout << ans << endl;
}