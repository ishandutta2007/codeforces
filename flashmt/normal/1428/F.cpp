#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;

  vector<pair<int, int>> intervals;
  long long ans = 0;
  for (int i = 0, cur = 0; i < n; i++)
  {
    if (s[i] == '0') cur = 0;
    else
    {
      if (!cur) intervals.push_back({i, i});
      else intervals[intervals.size() - 1].second = i;
      int j = int(intervals.size()) - 2;
      while (j >= 0 && cur >= intervals[j].second - intervals[j].first + 1)
        j--;
      intervals[++j] = intervals.back();
      intervals.resize(j + 1);
      cur++;
    }

    int prevL = i, maxLen = 0;
    for (int j = int(intervals.size()) - 1; j >= 0; j--)
    {
      auto [l, r] = intervals[j];
      int m = r - maxLen + 1;
      ans += 1LL * (prevL - m) * maxLen; // [m, prevL)
      int from = maxLen + 1, to = r - l + 1;
      ans += (from + to) * (to - from + 1LL) / 2;
      maxLen = r - l + 1;
      prevL = l;
    }
    ans += 1LL * maxLen * prevL; // [0, prevL)
  }

  cout << ans << endl;
}