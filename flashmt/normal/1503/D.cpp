#include <bits/stdc++.h>
using namespace std;

void noAnswer()
{
  cout << -1 << endl;
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, a[200200], flipped[200200] = {0};
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (x > y)
    {
      swap(x, y);
      flipped[x] = 1;
    }
    if (x >= n || y < n)
      noAnswer();
    a[x] = y;
  }

  int minL[200200], maxR[200200];
  minL[0] = a[0];
  for (int i = 1; i < n; i++)
    minL[i] = min(minL[i - 1], a[i]);
  maxR[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--)
    maxR[i] = max(maxR[i + 1], a[i]);

  int ans = 0;
  for (int i = 0; i < n;)
  {
    int j = i + 1;
    while (j < n && maxR[j] > minL[j - 1])
      j++;
    int numFlip = 0, maxFront = n * 2, maxBack = n * 2;
    for (int k = i; k < j; k++)
      if (a[k] < maxFront)
      {
        maxFront = a[k];
        numFlip += flipped[k];
      }
      else if (a[k] < maxBack)
      {
        maxBack = a[k];
        numFlip += flipped[k] ^ 1;
      }
      else noAnswer();

    ans += min(numFlip, j - i - numFlip);
    i = j;
  }
  cout << ans << endl;
}