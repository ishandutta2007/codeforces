#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <ll> p2(101);
  p2[0] = 1;
  for (int i = 1; i <= 100; i++)
    p2[i] = p2[i - 1] * 2 % MOD;
  string s;
  cin >> s;
  int n = (int) s.size();
  reverse(s.begin(), s.end());
  ll val = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '1')
      val = (val + p2[i]) % MOD;
  val *= p2[n - 1];
  val %= MOD;
  cout << val;
  return 0;
}