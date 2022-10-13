#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
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
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> cnt(26);
    for (char c : s)
      cnt[c - 'a']++;
    string ans(k, 'a');
    for (int i = 0, last = k; i < min(25, n / k); i++)
    {
      last = min(last, cnt[i]);
      for (int j = 0; j < last; j++)
        ans[j]++;
    }
    cout << ans << endl;
  }
}