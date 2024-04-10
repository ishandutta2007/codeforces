#include <bits/stdc++.h>
using namespace std;

int n, leaveCnt[200200];
long long citizens[200200], ans;
vector<int> a[200200];

void visit(int x)
{
  if (a[x].empty()) leaveCnt[x] = 1;
  else
    for (int y : a[x])
    {
      visit(y);
      leaveCnt[x] += leaveCnt[y];
      citizens[x] += citizens[y];
    }

  ans = max(ans, (citizens[x] + leaveCnt[x] - 1) / leaveCnt[x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 2; i <= n; i++)
  {
    int p;
    cin >> p;
    a[p].push_back(i);
  }

  for (int i = 1; i <= n; i++)
    cin >> citizens[i];

  visit(1);
  cout << ans << endl;
}