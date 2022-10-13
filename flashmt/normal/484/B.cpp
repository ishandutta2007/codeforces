#include <bits/stdc++.h>
using namespace std;
const int MAX_A = int(2e6);

int n, a[200200], cnt[2000100];

int check(int mod)
{
  for (int i = 0; i < n; i++)
    if (a[i] > mod)
      for (int j = a[i]; j + a[i] - 1 <= MAX_A; j += a[i])
        if (cnt[j + a[i] - 1] > cnt[j + mod - 1])
          return 1;
  return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    cnt[a[i]]++;
  }
  
  if (n == 1)
  {
    cout << 0 << endl;
    return 0;
  }
  
  sort(a, a + n);
  n = unique(a, a + n) - a;
  for (int i = 1; i <= MAX_A; i++) cnt[i] += cnt[i - 1];
  
  int low = 1, high = a[n - 2] - 1, ans = 0;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (check(mid)) ans = mid, low = mid + 1;
    else high = mid - 1;
  }
  
  cout << ans << endl;
}