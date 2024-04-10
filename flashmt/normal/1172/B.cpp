#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

vector <int> a[200200];
long long fact[200200];

long long visit(int x, int par)
{
  long long ans = fact[a[x].size()];
  for (int y : a[x])
    if (y != par)
      ans = ans * visit(y, x) % BASE;
  return ans;
}

int main()
{
  ios::sync_with_stdio(0);
  int x, y, n;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  for (int i = 0; i <= n; i++)
    fact[i] = i ? fact[i - 1] * i % BASE : 1;

  cout << visit(1, 0) * n % BASE << endl;
}