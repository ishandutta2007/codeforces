#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;

int cnt[2][2];

bool check(int n, string s, string t) {
  cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0;
  for (auto &x : s) cnt[0][x - '0']++;
  for (auto &x : t) cnt[1][x - '0']++;
  return max(min(cnt[0][0], cnt[1][0]), min(cnt[0][1], cnt[1][1])) >= n;
}

bool check(int n, string a, string b, string c) {
  return check(n, a, b) || check(n, a, c) || check(n, b, c);
}

void gen(int n) {
  vector<string> v;
  for (int m = 0; m < (1 << (2 * n)); m++) {
    string s;
    for (int i = 0; i < 2 * n; i++) {
      if (m & (1 << i)) s += "0";
      else s += "1";
    }
    v.push_back(s);
  }
  for (auto &a : v) {
    for (auto &b : v) {
      for (auto &c : v) {
        if (a == b || a == c || b == c) continue;
        bool ok = check(n, a, b, c);
        if (!ok) {
          cout << "bad : \n";
          cout << a << " " << b << " " << c << "\n";
          exit(0);
        }
      }
    }
  }
  cout << "done " << n << "\n";
}

void rec(int n, string a, string b) {
  cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0;
  for (auto &x : a) cnt[0][x - '0']++;
  for (auto &x : b) cnt[1][x - '0']++;
  int val = -1;
  if (min(cnt[0][0], cnt[1][0]) >= n) val = 0;
  else val = 1;
  string ret;
  int pos = 0;
  for (int i = 0; i < 2 * n; i++) {
    while (pos < 2 * n && b[pos] - '0' != val) {
      ret += b[pos];

      pos++;
    }
    if (pos < 2 * n) {
      if (a[i] - '0' == val && b[pos] - '0' == val) {
        pos++;
      }
    }
    ret += a[i];
  }
  while (pos < 2 * n) {
    ret += b[pos];
    pos++;
  }
  cout << ret << "\n";
}

void rec(int n, string a, string b, string c) {
  if (check(n, a, b)) {rec(n, a, b); return;}
  if (check(n, a, c)) {rec(n, a, c); return;}
  if (check(n, b, c)) {rec(n, b, c); return;}
  assert(0);
}

int n, p[3];
string s[3];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
 /// freopen ("input", "r", stdin);

  /**for (int n = 1; n <= 20; n++) {
    gen(n);
  }**/

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s[0] >> s[1] >> s[2];
    rec(n, s[0], s[1], s[2]);
  }
  return 0;
}