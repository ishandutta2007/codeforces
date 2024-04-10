#include <bits/stdc++.h>
using namespace std;

int n, p[100100], upL[100100], upR[100100], downL[100100], downR[100100];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i];

  for (int i = 1; i < n; i++)
    if (p[i] < p[i - 1]) downL[i] = downL[i - 1] + 1;
    else upL[i] = upL[i - 1] + 1;
  for (int i = n - 2; i >= 0; i--)
    if (p[i] < p[i + 1]) downR[i] = downR[i + 1] + 1;
    else upR[i] = upR[i + 1] + 1;

  int maxMove = max(*max_element(upL, upL + n), *max_element(upR, upR + n));
  int firstY = n, lastY = -1;
  for (int i = 0; i < n; i++)
    if (downL[i] == maxMove || downR[i] == maxMove)
    {
      firstY = min(firstY, i);
      lastY = max(lastY, i);
    }

  int ans = 0;
  for (int i = 1; i + 1 < n; i++)
    if (upL[i] == upR[i] && upL[i] == maxMove)
    {
      if (firstY < i && (maxMove % 2 || downL[firstY] == maxMove || firstY + maxMove < i))
        continue;

      if (lastY > i && (maxMove % 2 || downR[lastY] == maxMove || lastY - maxMove > i))
        continue;

      ans++;
    }

  cout << ans << endl;
}