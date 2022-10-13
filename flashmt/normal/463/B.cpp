#include <bits/stdc++.h>
using namespace std;

int n, h[100100];

int canJump(long long energy)
{
  for (int i = 0; i < n; i++)
  {
    energy += h[i] - h[i + 1];
    if (energy < 0) return 0;
  }
  return 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> h[i];
  
  long long low = 0, high = 1LL << 60, ans;
  while (low <= high)
  {
    long long mid = (low + high) / 2;
    if (canJump(mid)) ans = mid, high = mid - 1;
    else low = mid + 1;
  }
  
  cout << ans << endl;
}