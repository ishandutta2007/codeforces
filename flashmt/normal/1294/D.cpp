#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q, x;
  cin >> q >> x;
  vector<int> cnt(x, 0);
  set<int> s[500500];
  for (int i = 0; i < x; i++)
    s[0].insert(i);

  int minCnt = 0;
  while (q--)
  {
    int y;
    cin >> y;
    y %= x;
    s[cnt[y]].erase(y);
    s[++cnt[y]].insert(y);
    while (s[minCnt].empty())
      minCnt++;
    cout << minCnt * x + *s[minCnt].begin() << '\n';
  }
}