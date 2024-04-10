#include <bits/stdc++.h>
using namespace std;

int n, a[2000100], st[2000100], L = 1, R;
map <int,int> cnt;

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    cnt[-a[i]]++;
    a[n + i] = a[i];
  }

  for (int i = 1; i < n; i++)
    a[n + i] = a[i];

  long long ans = 0;
  for (int i = 1; i < n * 2; i++)
  {
    while (R >= L && i - st[L] >= n) L++;
    while (R >= L && a[i] > a[st[R]])
    {
      if (i >= n) ans++;
      R--;
    }
  
    if (R >= L && i >= n) 
    {
      if (a[i] == a[st[R]]) 
      {
        int low = L, high = R, res = R;
        while (low <= high)
        {
          int mid = (low + high) / 2;
          if (a[st[mid]] == a[st[R]])
          {
            res = mid;
            high = mid - 1;
          }
          else low = mid + 1;
        }
        ans += R - max(L, res - 1) + 1;
      }
      else ans++;
    }

    st[++R] = i;
  }

  auto it = cnt.begin();
  int largest = it -> second;
  if (cnt.size() == 1) ans /= 2;
  else if (cnt.begin() -> second == 1)
  {
    it++;
    ans -= 1LL * largest * it -> second;
  }
  else ans -= largest * (largest - 1LL) / 2;

  cout << ans << endl;
}