#include <bits/stdc++.h>
using namespace std;
const int BASE = 989991077;
const int P = 67;

vector<pair<int, int>> a[200200];
long long h[200200], goalH, s[10][10], ans;
int k;

void go(int sz, long long curH)
{
  if (sz > k) ans += curH == goalH;
  else
    for (int i = 0; i < sz; i++)
      go(sz + 1, (curH + s[sz][i]) % BASE);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    cin >> x >> y >> w;
    a[--x].push_back({w, --y});
  }

  h[0] = 1;
  for (int i = 1; i < n; i++)
    h[i] = h[i - 1] * P % BASE;
  goalH = accumulate(h, h + n, 0LL) % BASE;

  for (int x = 0; x < n; x++)
  {
    sort(a[x].begin(), a[x].end());
    for (int i = 0; i < size(a[x]); i++)
      s[size(a[x])][i] = (s[size(a[x])][i] + h[a[x][i].second]) % BASE;
  }

  go(1, 0);
  cout << ans << endl;
}