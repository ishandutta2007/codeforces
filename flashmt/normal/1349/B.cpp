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
    int n, k, hasK = 0, hasGoodPair = 0;
    cin >> n >> k;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      hasK |= x == k;
      cnt[i + 1] = cnt[i] + (x >= k);
      hasGoodPair |= cnt[i + 1] - cnt[max(i - 2, 0)] >= 2;
    }
    cout << (hasK && (hasGoodPair || n == 1) ? "yes\n" : "no\n");
  }
}