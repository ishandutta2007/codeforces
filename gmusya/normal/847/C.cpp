#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

void solve(int n, ll k, string &s) {
  if (!n)
    return;
  if (n / 2 <= k + 1) {
    s += "(";
    solve(n - 2, k - (n / 2 - 1), s);
    s += ")";
  } else {
    s += "()";
    solve(n - 2, k, s);
  }
}

int main() {
  ll n, k;
  cin >> n >> k;
  if (n * (n - 1) / 2 < k) {
    cout << "Impossible";
    return 0;
  }
  n *= 2;
  string ans = "";
  solve(n, k, ans);
  cout << ans;
  return 0;
}