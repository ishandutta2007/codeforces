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
    long long k;
    cin >> k;
    if (k % 2) cout << -1 << endl;
    else
    {
      k /= 2;
      vector<int> ans;
      ans.push_back(1);
      k--;
      for (int i = 59; i; i--)
        while (k >= (1LL << i) - 1)
        {
          k -= (1LL << i) - 1;
          for (int j = 0; j < i - 1; j++)
            ans.push_back(0);
          ans.push_back(1);
        }

      cout << ans.size() << endl;
      for (int x : ans)
        cout << x << ' ';
      cout << endl;
    }
  }
}