#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string a[111];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    string ans = "NO";
    for (int j = 0; j < i; j++)
      if (a[j] == a[i])
        ans = "YES";
    cout << ans << endl;
  }
}