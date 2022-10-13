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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    sort(begin(a), end(a));
    sort(begin(b), end(b));

    string ans = "YES";
    for (int i = 0; i < n; i++)
      if (a[i] > b[i] || a[i] + 1 < b[i])
        ans = "NO";
    cout << ans << endl;
  }
}