#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  vector<pair<char, int>> intervals;
  for (int i = 0; i < s.size();)
  {
    int j = i + 1;
    while (j < s.size() && s[j] == s[i])
      j++;
    intervals.push_back({s[i], j - i});
    i = j;
  }

  int numInterval = intervals.size();
  if (numInterval % 2 == 0) cout << 0 << endl;
  else if (intervals[numInterval / 2].second == 1) cout << 0 << endl;
  else
  {
    for (int i = 0; i < numInterval / 2; i++)
    {
      auto [c, cntL] = intervals[i];
      auto [cc, cntR] = intervals[numInterval - 1 - i];
      if (c != cc || cntL + cntR < 3)
      {
        cout << 0 << endl;
        return 0;
      }
    }
    cout << intervals[numInterval / 2].second + 1 << endl;
  }
}