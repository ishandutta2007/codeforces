#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;

int inv(int a) {
  int r = 1, b = M - 2;
  while (b) {
    if (b & 1) {
      r = 1LL * r * a % M;
    }
    a = 1LL * a * a % M;
    b /= 2;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int sol = 0;
  for (int i = 0; i < n; i++) {
    sol = (sol + M - a[i]) % M;
    sol = (sol + a[i + n]) % M;
  }
  int comb = 1;
  int fact = 1;
  for (int i = 1; i <= 2 * n; i++) {
    fact = 1LL * fact * i % M;
    if (i == n) {
      int invfact = inv(fact);
      comb = 1LL * comb * invfact % M;
      comb = 1LL * comb * invfact % M;
    }
  }
  comb = 1LL * comb * fact % M;
  cout << 1LL * comb * sol % M << "\n";
}