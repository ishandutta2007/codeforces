#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int color[2020], d[2020];
vector <int> edges[2020];

int get(int x)
{
  return x == d[x] ? x : d[x] = get(d[x]);
}

void addEdge(int x, int y)
{
  edges[x].push_back(y);
  edges[y].push_back(x);
}

int visit(int x, int c)
{
  color[x] = c;
  for (int y : edges[x])
    if (color[get(y)] < 0)
    {
      if (!visit(get(y), c ^ 1))
        return 0;
    }
    else if (color[get(y)] != c ^ 1)
      return 0;
  return 1;
}

int calc(string s, int k)
{
  int n = s.size();
  // init
  for (int i = 0; i < n + k + 2; i++)
  {
    color[i] = -1;
    d[i] = i;
    edges[i].clear();
  }

  // b itself
  for (int i = 0; i < n - 1 - i; i++)
    d[get(i)] = get(n - 1 - i);

  // first bit of b
  d[get(0)] = get(n + k + 1);

  // a itself
  for (int i = 0; i < k - 1 - i; i++)
    d[get(n + i)] = get(n + k - 1 - i);

  // first bit of a
  d[get(n)] = get(n + k + 1);

  // a ^ b = 0 || no a
  for (int i = 0; i < n; i++)
    if (s[i] != '?')
    {
      if (i >= k) d[get(i)] = get(n + k + s[i] - '0');
      else if (s[i] == '0') d[get(i)] = get(n + i);
    }

  // a ^ b = 1
  for (int i = 0; i < n; i++)
    if (s[i] != '?' && i < k && s[i] == '1')
      addEdge(get(i), get(n + i));

  // 0 and 1
  addEdge(get(n + k), get(n + k + 1));

  // check valid
  int numComponent = 0;
  for (int i = 0; i < n + k + 2; i++)
    if (color[get(i)] < 0)
    {
      if (!visit(get(i), 0))
        return 0;
      numComponent++;
    }

  int res = 1;
  for (int i = 1; i < numComponent; i++)
    res = res * 2 % BASE;
  return res;
}

int main()
{
  string s;
  cin >> s;
  reverse(s.begin(), s.end());

  int ans = 0;
  if (s[0] != '1')
    for (int i = 1; i < s.size(); i++)
      ans = (ans + calc(s, i)) % BASE;
  cout << ans << endl;  
}