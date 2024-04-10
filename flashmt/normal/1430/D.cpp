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
    int len;
    string s;
    cin >> len >> s;
    vector<int> a;
    for (int i = 0, cnt = 0; i < len; i++)
    {
      cnt++;
      if (i == len - 1 || s[i] != s[i + 1])
      {
        a.push_back(cnt);
        cnt = 0;
      }
    }

    int n = a.size(), extra = 0;
    for (int i = 0; i < n; i++)
      extra = min(extra + a[i] - 1, i + 1);

    cout << (n - extra + 1) / 2 + extra << '\n';
  }
}