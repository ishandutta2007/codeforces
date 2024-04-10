#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  ll s;
  cin >> s;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <ll> fact(19);
  fact[0] = 1;
  for (int i = 1; i <= 18; i++)
    fact[i] = fact[i - 1] * i;
  if (n == 1) {
    cout << (a[0] == s) + (k && a[0] <= 18 && fact[a[0]] == s);
    return 0;
  }
  vector <ll> p3(15);
  p3[0] = 1;
  for (int i = 1; i <= 14; i++)
    p3[i] = p3[i - 1] * 3;
  int m = n / 2;
  int l = n - m;
  if (n > 15) {
    m = (n + 3) / 2;
    l = n - m;
  }
  vector <ll> b, c;
  for (int i = 0; i < m; i++)
    b.push_back(a[i]);
  for (int i = m; i < n; i++)
    c.push_back(a[i]);
  map <pair <int, ll>, ll> ma;
  ll answer = 0;
  for (int mask = 0; mask < p3[m]; mask++) {
    int cnt = 0;
    ll curs = 0;
    int copymask = mask;
    for (int i = 0; i < m; i++) {
      if (copymask % 3 == 0) {
        copymask /= 3;
        continue;
      }
      if (copymask % 3 == 1) {
        curs += b[i];
      } else {
        cnt++;
        if (b[i] >= 19)
          cnt = 123;
        else
          curs += fact[b[i]];
      }
      copymask /= 3;
    }
    ma[{cnt, curs}]++;
  }
  for (int mask = 0; mask < p3[l]; mask++) {
    int cnt = 0;
    ll curs = 0;
    int copymask = mask;
    for (int i = 0; i < l; i++) {
      if (copymask % 3 == 0) {
        copymask /= 3;
        continue;
      }
      if (copymask % 3 == 1) {
        curs += c[i];
      } else {
        cnt++;
        if (c[i] >= 19)
          cnt = 123;
        else
          curs += fact[c[i]];
      }
      copymask /= 3;
    }
    for (int j = 0; j + cnt <= k; j++)
      answer += ma[{j, s - curs}];
  }
  cout << answer;
  return 0;
}