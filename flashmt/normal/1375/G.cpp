#include <bits/stdc++.h>
using namespace std;

int n, ans, cnt[2];
vector<int> a[200200];

void visit(int x, int c, int par)
{
  cnt[c]++;
  for (int y : a[x])
    if (y != par)
      visit(y, c ^ 1, x);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  visit(0, 0, -1);
  cout << min(cnt[0], cnt[1]) - 1 << endl;
}