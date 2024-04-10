#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n, k, a[200200], idA[200200], b[200200];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      idA[a[i]] = i;
    }
    vector<int> idB(n + 1, -1);
    for (int i = 0; i < k; i++)
    {
      cin >> b[i];
      idB[b[i]] = i;
    }

    int ans = 1;
    for (int i = 0; i < k; i++)
    {
      int hasLeft = 1, hasRight = 1, curIdA = idA[b[i]];
      if (!curIdA || idB[a[curIdA - 1]] > i)
        hasLeft = 0;
      if (curIdA == n - 1 || idB[a[curIdA + 1]] > i)
        hasRight = 0;
      ans = ans * (hasLeft + hasRight) % BASE;
    }

    cout << ans << endl;
  }
}