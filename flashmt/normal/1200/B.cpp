#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n, m, k, h[100];
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
      cin >> h[i];

    int win = 1;
    for (int i = 0; i < n - 1; i++)
      if (h[i] + m + k < h[i + 1])
      {
        win = 0;
        break;
      }
      else m += min(h[i], h[i] + k - h[i + 1]);

    cout << (win ? "YES" : "NO") << endl;
  }
}