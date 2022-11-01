#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rec (int sz, char c, vector <char> &s) {
  if (sz == 1) {
    if (s[0] == c)
      return 0;
    return 1;
  }
  vector <char> s1, s2;
  for (int i = 0; i < sz / 2; i++)
    s1.push_back(s[i]);
  for (int i = sz / 2; i < sz; i++)
    s2.push_back(s[i]);
  int a = rec(sz / 2, c + 1, s1);
  int b = rec(sz / 2, c + 1, s2);
  for (int i = 0; i < sz / 2; i++)
    a += (s2[i] != c);
  for (int i = 0; i < sz / 2; i++)
    b += (s1[i] != c);
  return min(a, b);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <char> c(n);
    for (int i = 0; i < n; i++)
      cin >> c[i];
    cout << rec(n, 'a', c) << '\n';
  }
  return 0;
}