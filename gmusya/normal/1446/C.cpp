#include <iostream>
#include <vector>

using namespace std;

int solve(vector <int> &a, int p2) {
  if (a.size() <= 2)
    return 2;
  vector <int> b, c;
  for (int x : a) {
    if (x & p2)
      b.push_back(x);
    else
      c.push_back(x);
  }
  if (b.size() <= 0)
    return solve(c, p2 / 2);
  if (c.size() <= 0)
    return solve(b, p2 / 2);
  return 1 + max(solve(c, p2 / 2), solve(b, p2 / 2));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << n - solve(a, (1 << 29));
  return 0;
}