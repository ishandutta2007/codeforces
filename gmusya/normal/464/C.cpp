#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll binp(ll a, ll p) {
  if (p <= 0) return 1;
  if (p & 1) return a * binp(a, p - 1) % MOD;
  ll x = binp(a, p / 2);
  return x * x % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector <pair <char, string>> que(q);
  for (int i = 0; i < q; i++) {
    char c;
    cin >> c;
    que[i].first = c;
    cin >> c >> c;
    getline(cin, que[i].second);
    reverse(que[i].second.begin(), que[i].second.end());
  }
  vector <ll> oldlen(10), oldval(10);
  for (int i = 0; i < 10; i++)
    oldlen[i] = 1;
  for (int i = 0; i < 10; i++)
    oldval[i] = i;
  for (int i = q - 1; i >= 0; i--) {
    vector <ll> newlen(10), newval(10);
    newlen = oldlen, newval = oldval;
    int pos = que[i].first - '0';
    newlen[pos] = newval[pos] = 0;
    ll s = 0;
    for (auto &c : que[i].second) {
      newval[pos] = (newval[pos] + binp(10, s) * oldval[c - '0']) % MOD;
      s = (s + oldlen[c - '0']) % (MOD - 1);
    }
    newlen[pos] = s;
    swap(oldlen, newlen);
    swap(oldval, newval);
  }
  reverse(s.begin(), s.end());
  ll ans = 0;
  ll sumlen = 0;
  for (auto &c : s) {
    ans = (ans + binp(10, sumlen) * oldval[c - '0']) % MOD;
    sumlen = (sumlen + oldlen[c - '0']) % (MOD - 1);
  }
  cout << ans;
  return 0;
}