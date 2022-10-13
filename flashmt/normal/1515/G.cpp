#include <bits/stdc++.h>
using namespace std;
const int N = 200200;

int n;
vector<pair<int, int>> a[N];
int low[N], num[N], flag[N], counter, sccId[N], numScc;
vector<int> st;
long long dist[N], cycleLen[N];

void calcCycle(int x)
{
  for (auto [y, z] : a[x])
    if (sccId[y] == sccId[x])
    {
      if (dist[y] < 0)
      {
        dist[y] = dist[x] + z;
        calcCycle(y);
      }
      else cycleLen[sccId[x]] = __gcd(cycleLen[sccId[x]], llabs(dist[x] + z - dist[y]));
    }
}

void dfs(int x)
{
  low[x] = num[x] = counter++;
  st.push_back(x);
  flag[x] = 1;
  for (auto [y, _] : a[x])
    if (num[y] < 0)
    {
      dfs(y);
      low[x] = min(low[x], low[y]);
    }
    else if (flag[y] == 1) low[x] = min(low[x], num[y]);

  if (low[x] != num[x])
    return;

  while (1)
  {
    int y = st.back();
    st.pop_back();
    flag[y] = 2;
    sccId[y] = numScc;
    if (y == x)
      break;
  }

  dist[x] = 0;
  calcCycle(x);
  numScc++;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> n >> m;
  while (m--)
  {
    int x, y, z;
    cin >> x >> y >> z;
    a[--x].push_back({--y, z});
  }

  memset(num, -1, sizeof num);
  memset(dist, -1, sizeof dist);
  for (int i = 0; i < n; i++)
    if (num[i] < 0)
      dfs(i);

  int q;
  cin >> q;
  while (q--)
  {
    int x;
    long long s, t;
    cin >> x >> s >> t;
    --x;
    if (!s) cout << "YES\n";
    else cout << ((t - s) % __gcd(t, cycleLen[sccId[x]]) == 0 ? "YES" : "NO") << '\n';
  }
}