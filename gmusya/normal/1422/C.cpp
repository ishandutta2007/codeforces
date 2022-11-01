#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef __int128 ll;

const ll MOD = 1e9 + 7;

ll binp(ll a, ll p) {
  if (!p)
    return 1;
  if (p & 1)
    return a * binp(a, p - 1) % MOD;
  ll x = binp(a, p / 2);
  return x * x % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <ll> p10(100'005);
  p10[0] = 1;
  for (int i = 1; i <= 100'004; i++)
    p10[i] = p10[i - 1] * 10 % MOD;
  string s;
  cin >> s;
  int n = (int) s.size();
  vector <ll> ans(n);
  vector <ll> cnt(n), del(n);
  for (int i = 0; i < n; i++) {
    ans[i] += i * 1ll * (i + 1) / 2 % MOD;
    cnt[n - 1] += (s[i] - '0');
    cnt[i] -= (s[i] - '0');
    del[i] -= (s[i] - '0') * (n - i - 1);
  }
  for (auto &now : ans)
    now %= MOD;
  for (auto &now : cnt)
    now %= MOD;
  for (auto &now : del)
    now %= MOD;
  ll pr = 0;
  ll sum = 0;
  ll answer = 0;
  for (int i = n - 1; i >= 0; i--) {
    pr += cnt[i];
    sum += pr + del[i];
    answer = (answer + sum * p10[n - i - 1]) % MOD;
    answer = (answer + ans[i] * p10[n - i - 1] * (s[i] - '0')) % MOD;
  }
  answer %= MOD;
  if (answer < 0)
    answer += MOD;
  cout << (long long) answer;
  return 0;
}