#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a)
      cin >> x;
    for (int &x : b)
      cin >> x;

    vector<int> cnt(n + 1);
    int ans = 1, i = 0, j = 0;
    while (i < n || j < n)
    {
      if (i < n && a[i] == b[j])
      {
        i++;
        j++;
      }
      else if (j && b[j] == b[j - 1] && cnt[b[j]]) cnt[b[j++]]--;
      else if (i < n) cnt[a[i++]]++;
      else
      {
        ans = 0;
        break;
      }
    }

    cout << (ans ? "YES" : "NO") << '\n';
  }
}