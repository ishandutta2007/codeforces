#include <bits/stdc++.h>
using namespace std;

int n, edgeOut[100100];
vector<int> edgeIn[100100];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q, m;
  cin >> n >> m;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    if (x > y)
      swap(x, y);
    edgeIn[x].push_back(y);
    edgeOut[y]++;
  }

  long long ans = 0;
  for (int x = 1; x <= n; x++)
    ans += 1LL * edgeIn[x].size() * edgeOut[x];

  cout << ans << '\n';
  cin >> q;
  while (q--)
  {
    int x;
    cin >> x;
    ans -= 1LL * edgeIn[x].size() * edgeOut[x];
    for (int y : edgeIn[x])
    {
      edgeOut[y]--;
      ans += edgeOut[y];
      ans -= edgeIn[y].size();
      edgeOut[x]++;
      edgeIn[y].push_back(x);
    }
    edgeIn[x].clear();
    cout << ans << '\n';
  }
}