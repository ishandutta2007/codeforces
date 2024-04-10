#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> prefix_function (const vector<int>& s) {
  int n = s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])  ++j;
    pi[i] = j;
  }
  return pi;
}

int n;
set<int> f[100005];

int getLen(int a, int b) {
  int len = b - a;
  if (len <= 0) len += n;

  return len;
}

int go(int len) {
  if (f[len].size() == 0) return 1;
  else if (f[len].size() < 2) return -1;
  // cout << "Go: " << len << endl;

  vector<int> diffs;
  int last = -1, fir = -1;
  for (int x : f[len]) {
    if (last == -1) fir = x;
    else diffs.push_back(getLen(last, x));
    last = x;
  }
  diffs.push_back(getLen(last, fir));

  vector<int> pref = prefix_function(diffs);
  // for (int x : diffs)
  //   cout << x << "  ";
  // cout << endl;

  int cand = diffs.size() - pref.back();

  // cout << "Cand:  " << cand << endl;
  if (diffs.size() % cand == 0 && cand < diffs.size()) {
    int sum = 0;
    for (int i = 0; i < cand; ++i)
      sum += diffs[i];
    return sum;
  }

  return -1;
}

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int main() {
  ios::sync_with_stdio(false);
  int m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    int len = getLen(a, b);
    // cout << len << endl;
    if (2 * len > n || 2 * len == n && a > b) len = n - len, swap(a, b);
    // cout << len << "  " << a << " " << b << endl;

    f[len].insert(a - 1);
  }

  long long ans = 1;

  for (int i = 1; i < n; ++i) {
    if (2 * i == n) continue;
    int cur = go(i);
    // cout << "What: " << i << " " << cur << endl;

    if (cur == - 1) {
      cout << "No" << endl;
      return 0;
    }

    ans = lcm(ans, cur);
    if (ans >= n) {
      cout << "No" << endl;
      return 0;
    }
  }

  if (n % 2 == 0) {
    int cur = go(n / 2);
    if (cur != -1 && lcm(ans, cur) < n || lcm(ans, n / 2) < n) {

    } else {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}