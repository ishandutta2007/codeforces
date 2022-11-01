#include <iostream>
#include <string>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

const ll MAXN = 6e5;
const ll MOD1 = 1e9 + 123;
const ll MOD2 = 1e9 + 321;
const ll P1 = 89;
const ll P2 = 91;

ll p1[MAXN + 1], p2[MAXN + 1];

void init() {
  p1[0] = p2[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    p1[i] = p1[i - 1] * P1 % MOD1;
    p2[i] = p2[i - 1] * P2 % MOD2;
  }
}

ll f(char c) {
  return (c - 'a' + 1);
}

int main() {
  init();
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  set <pair <int, pair <ll, ll>>> s;
  while (n--) {
    string str;
    cin >> str;
    ll h1 = 0, h2 = 0;
    for (int i = 0; i < (int)str.size(); i++) {
      h1 = (h1 + p1[i] * f(str[i])) % MOD1;
      h2 = (h2 + p2[i] * f(str[i])) % MOD2;
    }
    s.insert({(int)str.size(), {h1, h2}});
  }
  while (m--) {
    string str;
    cin >> str;
    ll h1 = 0, h2 = 0;
    for (int i = 0; i < (int)str.size(); i++) {
      h1 = (h1 + p1[i] * f(str[i])) % MOD1;
      h2 = (h2 + p2[i] * f(str[i])) % MOD2;
    }
    bool flag = false;
    for (int i = 0; i < (int)str.size() && !flag; i++) {
      for (int j = 1; j <= 26; j++) {
        if (j == f(str[i])) continue;
        ll newh1 = h1, newh2 = h2;
        newh1 = (newh1 - p1[i] * f(str[i])) % MOD1;
        newh2 = (newh2 - p2[i] * f(str[i])) % MOD2;
        newh1 = (newh1 + p1[i] * j) % MOD1;
        newh2 = (newh2 + p2[i] * j) % MOD2;
        if (newh1 < 0)
          newh1 += MOD1;
        if (newh2 < 0)
          newh2 += MOD2;
        if (s.find({(int)str.size(), {newh1, newh2}}) != s.end())
          flag = true;
      }
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}