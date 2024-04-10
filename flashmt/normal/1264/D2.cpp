#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

long long power(long long x, long long y)
{
  if (!y)
    return 1;
  long long res = power(x, y >> 1);
  res = res * res % BASE;
  if (y & 1)
    res = res * x % BASE;
  return res;
}

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;

  vector<long long> fact(n + 1), invFact(n + 1);
  fact[0] = invFact[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    fact[i] = fact[i - 1] * i % BASE;
    invFact[i] = power(fact[i], BASE - 2);
  }

  vector<vector<long long>> suffixSum(2, vector<long long>(n + 1, 0));
  for (int z = 0; z < 2; z++)
  {
    int total = count(s.begin(), s.end(), '?') - z;
    if (total < 0)
      continue;
    suffixSum[z][total] = 1;
    for (int i = total - 1; i >= 0; i--)
      suffixSum[z][i] = (suffixSum[z][i + 1] + fact[total] * invFact[i] % BASE * invFact[total - i]) % BASE;
  }

  long long ans = 0;
  int openCnt = 0, closeCnt = count(s.begin(), s.end(), ')'), questionCnt = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == ')') closeCnt--;
    else
    {
      ans = (ans + suffixSum[s[i] == '?'][max(0, openCnt - closeCnt + questionCnt + 1)]) % BASE;
      if (s[i] == '?') questionCnt++;
      else openCnt++;
    }

  cout << ans << endl;
}