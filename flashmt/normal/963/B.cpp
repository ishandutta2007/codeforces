#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

vector<int> a[N], ans;
int flag[N];

void addAns(int x, int par)
{
  ans.push_back(x);
  flag[x] = 1;
  for (int y : a[x])
    if (y != par && !flag[y])
      addAns(y, x);
}

int visit(int x, int par = -1)
{
  int deg = par >= 0;
  for (int y : a[x])
    if (y != par)
      deg += 1 - visit(y, x);

  if (deg % 2)
    return 0;

  addAns(x, par);
  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    --x;
    if (x >= 0)
    {
      a[x].push_back(i);
      a[i].push_back(x);
    }
  }

  if (n % 2 == 0) cout << "NO\n";
  else
  {
    visit(0);
    cout << "YES\n";
    for (int x : ans)
      cout << x + 1 << '\n';
  }
}