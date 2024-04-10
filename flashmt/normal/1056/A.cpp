#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, cnt[111] = {0};
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int r, x;
    cin >> r;
    while (r--)
    {
      cin >> x;
      cnt[x]++;
    }
  }

  for (int i = 1; i <= 100; i++)
    if (cnt[i] == n)
      cout << i << ' ';
}