#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  long long A, B, n, l, t, m;
  cin >> A >> B >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> l >> t >> m;
    int low = l, high = l + int(1e6), ans = -1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      long long first = A + B * (l - 1);
      long long last = A + B * (mid - 1);
      if (last <= t && (first + last) * (mid - l + 1) / 2 <= m * t)
      {
        ans = mid;
        low = mid + 1;
      }
      else high = mid - 1;
    }
    
    cout << ans << '\n';
  }
}