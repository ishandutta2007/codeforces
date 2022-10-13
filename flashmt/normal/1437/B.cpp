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
    int ans = 0;
    for (int i = 1; i < n; i++)
      ans += s[i] == s[i - 1];
    cout << (ans + 1) / 2 << endl;
  }
}