#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  ll x, y;
  cin >> x >> y;
  int n = (int)s.size();
  vector <ll> cnt0(n + 1), cnt1(n + 1), cntq(n + 1);
  for (int i = 0; i < n; i++) {
    cnt0[i + 1] = cnt0[i];
    cnt1[i + 1] = cnt1[i];
    cntq[i + 1] = cntq[i];
    if (s[i] == '0')
      cnt0[i + 1]++;
    if (s[i] == '1')
      cnt1[i + 1]++;
    if (s[i] == '?')
      cntq[i + 1]++;
  }
  ll polybasu = 0;
  for (int i = 1; i <= n; i++) {
    char c = s[i - 1];
    if (c == '0') {
      ll left = cnt1[i];
      ll right = cnt1[n] - cnt1[i];
      polybasu += y * left + x * right;
    }
    if (c == '1') {
      ll left = cnt0[i];
      ll right = cnt0[n] - cnt0[i];
      polybasu += x * left + y * right;
    }
  }
  polybasu /= 2;
  vector <ll> pref0(n + 1), pref1(n + 1);
  for (int i = 1; i <= n; i++) {
    pref0[i] = pref0[i - 1];
    pref1[i] = pref1[i - 1];
    if (s[i - 1] != '?')
      continue;
    {
      ll left = cnt1[i];
      ll right = cnt1[n] - cnt1[i];
      pref0[i] += y * left + x * right;
    }
    {
      ll left = cnt0[i];
      ll right = cnt0[n] - cnt0[i];
      pref1[i] += x * left + y * right;
    }
  }
  vector <ll> suf0(n + 1), suf1(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    suf0[i] = suf0[i + 1];
    suf1[i] = suf1[i + 1];
    if (s[i] != '?')
      continue;
    {
      ll left = cnt1[i + 1];
      ll right = cnt1[n] - cnt1[i + 1];
      suf0[i] += y * left + x * right;
    }
    {
      ll left = cnt0[i + 1];
      ll right = cnt0[n] - cnt0[i + 1];
      suf1[i] += x * left + y * right;
    }
  }
  ll ans = 1e18;
  for (int i = 0; i <= n; i++) {
    {
      ll res = pref0[i] + suf1[i];
      ll left = cntq[i];
      ll right = cntq[n] - cntq[i];
      res += left * right * x;
      ans = min(ans, res);
    }
    {
      ll res = pref1[i] + suf0[i];
      ll left = cntq[i];
      ll right = cntq[n] - cntq[i];
      res += left * right * y;
      ans = min(ans, res);
      if (res + polybasu == 1)
        cout << i << endl;
    }
  }
  cout << ans + polybasu;
  return 0;
}