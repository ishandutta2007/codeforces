#include <bits/stdc++.h>
using namespace std;
const int A = 60;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[300300];
  long long x;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    a[i] = __builtin_popcountll(x);
  }

  int cnt[2][300300] = {0};
  cnt[0][0] = 1;
  long long ans = 0;
  for (int i = 1, parity = 0; i <= n; i++)
  {
    cnt[0][i] = cnt[0][i - 1];
    cnt[1][i] = cnt[1][i - 1];
    parity ^= a[i] % 2;
    cnt[parity][i]++;

    int sum = 0, maxA = 0;
    for (int j = i; j; j--)
    {
      sum += a[j];
      maxA = max(maxA, a[j]);
      ans += sum % 2 == 0 && maxA * 2 <= sum;
      if (sum >= A * 2 && j > 1)
      {
        ans += cnt[parity][j - 2];
        break;
      }
    }
  }

  cout << ans << endl;
}