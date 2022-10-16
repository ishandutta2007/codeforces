#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

int n, l, a[100100], b[100100];
vector<pair<int, int>> r;

bool solvable(int s) {
  int cp = l;
  b[n] = cp;
  for (int i = n - 1; i >= 0; i--) {
    if (cp < a[i])
      return false;
    cp = min(cp - s, a[i]);
    b[i] = cp;
  }
  return cp >= 0;
}

bool solve(int s, int e) {
  r.clear();
  solvable(s);
  int cp = 0;
  for (int i = 0; i < n; i++) {
    int np = min(cp + e, b[i + 1]);
    if (np < a[i])
      return false;
    r.emplace_back(cp, np);
    cp = np;
  }
  return cp == l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> l >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int s = 1, e = l + 1;
  while (s + 1 < e) {
    int m = (s + e) / 2;
    if (solvable(m))
      s = m;
    else
      e = m;
  }
  int se = s - 1;
  e = l;
  while (se + 1 < e) {
    int m = (se + e) / 2;
    if (solve(s, m))
      e = m;
    else
      se = m;
  }
  solve(s, e);
  for (auto [si, fi] : r)
    cout << si << " " << fi << "\n";
}