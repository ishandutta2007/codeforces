#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n * 2);
  for (int i = 0; i < n * 2; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n * 2; i += 2)
    if (a[i + 1] != a[i])
    {
      int j = find(begin(a) + i + 1, end(a), a[i]) - begin(a);
      ans += j - i - 1;
      rotate(begin(a) + i + 1, begin(a) + j, begin(a) + j + 1);
    }

  cout << ans << endl;
}