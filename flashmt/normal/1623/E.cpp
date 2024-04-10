#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, k, l[N], r[N], isGood[N], dup[N];
string s;
vector<int> order;

void dfs(int x)
{
  if (x < 0)
    return;
  dfs(l[x]);
  order.push_back(x);
  dfs(r[x]);
}

void dfsSolve(int x, int dupCost)
{
  if (x < 0)
    return;

  dfsSolve(l[x], dupCost + 1);

  if (l[x] >= 0 && dup[l[x]]) dup[x] = 1;
  else if (isGood[x] && dupCost <= k)
  {
    k -= dupCost;
    dup[x] = 1;
  }

  if (dup[x])
    dfsSolve(r[x], dup[x] ? 1 : dupCost + 1);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++)
  {
    cin >> l[i] >> r[i];
    l[i]--; r[i]--;
  }

  dfs(0);
  vector<int> id(26, n);
  for (int i = n - 1; i >= 0; i--)
  {
    int c = s[order[i]] - 'a';
    int minId = n, minC = -1;
    for (int cc = 0; cc < 26; cc++)
      if (cc != c && id[cc] < minId)
      {
        minId = id[cc];
        minC = cc;
      }

    isGood[order[i]] = minC > c;
    id[c] = i;
  }

  dfsSolve(0, 1);
  for (int x : order)
  {
    cout << s[x];
    if (dup[x])
      cout << s[x];
  }
  cout << endl;
}