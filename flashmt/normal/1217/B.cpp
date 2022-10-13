#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, x, d[100], h[100];
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
      cin >> d[i] >> h[i];
      h[i] = d[i] - h[i];
    }

    int maxD = *max_element(d, d + n);
    int maxH = *max_element(h, h + n);

    if (x <= maxD) cout << 1 << endl;
    else if (maxH <= 0) cout << -1 << endl;
    else cout << (x - maxD + maxH - 1) / maxH + 1 << endl;
  }
}