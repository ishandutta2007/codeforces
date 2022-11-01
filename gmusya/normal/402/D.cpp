#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set <int> s;

int f(int x) {
  int res = 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i)
      continue;
    int mult;
    if (s.find(i) == s.end())
      mult = 1;
    else
      mult = -1;
    while (x % i == 0) {
      x /= i;
      res += mult;
    }
  }
  if (x == 1)
    return res;
  if (s.find(x) == s.end())
    res++;
  else
    res--;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  for (int p : b)
    s.insert(p);
  vector <int> g(n);
  for (int i = 0; i < n; i++)
    g[i] = __gcd(a[i], (i ? g[i - 1] : 0));
  int k = 1;
  for (int i = n - 1; i >= 0; i--) {
    g[i] /= k;
    if (f(g[i]) < 0)
      k *= g[i];
    a[i] /= k;
  }
  int s = 0;
  for (int x : a)
    s += f(x);
  cout << s;
  return 0;
}