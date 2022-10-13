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
    string s;
    cin >> s;

    int n = s.size();
    vector<int> isRemoved(n, 0);
    for (int i = 0; i + 5 <= n; i++)
      if (s.substr(i, 5) == "twone")
        isRemoved[i + 2] = 1;

    for (int i = 0; i + 3 <= n; i++)
    {
      int isGood = 1;
      for (int j = 0; j < 3; j++)
        if (isRemoved[i + j])
          isGood = 0;
      string t = s.substr(i, 3);
      if (isGood && (t == "two" || t == "one"))
        isRemoved[i + 1] = 1;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
      if (isRemoved[i])
        ans.push_back(i);

    cout << ans.size() << '\n';
    for (int id : ans)
      cout << id + 1 << ' ';
    cout << '\n';
  }
}