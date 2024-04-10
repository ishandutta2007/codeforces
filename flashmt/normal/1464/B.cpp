#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int x, y;
  cin >> s >> x >> y;
  int n = s.size(), sum[3][100100] = {0};
  for (int i = 0; i < n; i++)
  {
    sum[0][i + 1] = sum[0][i];
    sum[1][i + 1] = sum[1][i];
    sum[2][i + 1] = sum[2][i];
    if (s[i] != '?') sum[s[i] - '0'][i + 1]++;
    else sum[2][i + 1]++;
  }

  long long score[2][100100] = {0}, fixed = 0;
  for (int i = 1; i <= n; i++)
  {
    score[0][i] = score[0][i - 1];
    score[1][i] = score[1][i - 1];
    if (s[i - 1] == '?')
    {
      score[0][i] += 1LL * x * (sum[1][n] - sum[1][i]) + 1LL * y * sum[1][i - 1];
      score[1][i] += 1LL * y * (sum[0][n] - sum[0][i]) + 1LL * x * sum[0][i - 1];
    }
    else if (s[i - 1] == '0') fixed += 1LL * x * (sum[1][n] - sum[1][i]);
    else fixed += 1LL * y * (sum[0][n] - sum[0][i]);
  }

  long long ans = 1LL << 60;
  for (int i = 1; i <= n; i++)
  {
    long long numPair = 1LL * sum[2][i] * (sum[2][n] - sum[2][i]);
    long long score01 = score[0][i] + score[1][n] - score[1][i];
    score01 += numPair * x;
    ans = min(ans, score01);

    long long score10 = score[1][i] + score[0][n] - score[0][i];
    score10 += numPair * y;
    ans = min(ans, score10);
  }

  cout << ans + fixed << endl;
}