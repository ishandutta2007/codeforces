#include <bits/stdc++.h>
using namespace std;

int n, a[200200], b[200200], c[200200], tree[800800];

int get(int x)
{
  int res = 0;
  for (int i = x + 1; i; i -= i & -i) res += tree[i];
  return res;
}

void add(int x)
{
  for (int i = x + 1; i <= n; i += i & -i) tree[i]++;
}

void init(int nd, int l, int r)
{
  tree[nd] = r - l + 1;
  if (l == r) return;
  int m = (l + r) / 2;
  init(nd * 2, l, m);
  init(nd * 2 + 1, m + 1, r);
}

void update(int nd, int l, int r, int x)
{
  tree[nd]--;
  if (l == r) return;
  int m = (l + r) / 2;
  if (x <= m) update(nd * 2, l, m, x);
  else update(nd * 2 + 1, m + 1, r, x);
}

int query(int nd, int l, int r, int k)
{
  if (l == r) return l;
  int m = (l + r) / 2;
  if (tree[nd * 2] >= k) return query(nd * 2, l, m, k);
  return query(nd * 2 + 1, m + 1, r, k - tree[nd * 2]);
}

int main()
{
  ios::sync_with_stdio(0);
  
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    int x = a[i];
    a[i] -= get(a[i]);
    add(x);
  }
  
  memset(tree, 0, sizeof tree);
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    int x = b[i];
    b[i] -= get(b[i]);
    add(x);
  }
  
  for (int i = n - 1, mem = 0; i >= 0; i--)
  {
    c[i] = a[i] + b[i] + mem;
    if (c[i] >= n - i)
    {
      c[i] -= n - i;
      mem = 1;
    }
    else mem = 0;
  }
  
  init(1, 0, n - 1);
  for (int i = 0; i < n; i++)
  {
    c[i] = query(1, 0, n - 1, c[i] + 1);
    update(1, 0, n - 1, c[i]);
    cout << c[i] << ' ';
  }
}