#include <bits/stdc++.h>
using namespace std;

int n, tree[200200];
pair <int,int> a[200200];
map <int,int> m;

void update(int x, int v)
{
  for (int i = x; i <= n; i += i & -i)
    tree[i] = max(tree[i], v);
}

int get(int x)
{
  int res = 0;
  for (int i = x; i; i -= i & -i)
    res = max(res, tree[i]);
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) 
  {
    cin >> a[i].first >> a[i].second;
    m[a[i].first + a[i].second] = 0;
  }
    
  sort(a, a + n);
  int id = 0;
  for (auto i : m) m[i.first] = ++id;
  
  for (int i = 0; i < n; i++)
  {
    auto bound = m.upper_bound(a[i].first - a[i].second);
    if (bound == m.begin()) 
    {
      update(m[a[i].first + a[i].second], 1);
      continue;
    }
    bound--;
    update(m[a[i].first + a[i].second], get(bound -> second) + 1);
  }
  
  cout << get(n) << endl;
}