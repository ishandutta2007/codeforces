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
    string s;
    cin >> n >> s;
    string t = s;
    sort(begin(t), end(t));
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += s[i] != t[i];
    cout << ans << endl;
  }
}