#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int check(string s) {
  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    s += s[0];
    s = s.substr(1);
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    cnt += s == tmp;
  }
  return cnt;
}


void gen(int left, string cur) {
  if (left == 0) {
    if (check(cur) > 1)
      cout << cur << "  " << check(cur) << endl;
    return;
  }
  for (char c = 'a'; c <= 'c'; ++c) {
    gen(left - 1, cur + c);
  }
}

bool isPal(const vector<int>& v) {
  int cntOdd = 0;
  for (int x : v)
    cntOdd += x & 1;
  return cntOdd < 2;
}

int ans = 0;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}

string build(const vector<int>& v, bool in) {
  int g = v[0];
  vector<int> tmp = v;
  for (int i = 0; i < tmp.size(); ++i) {
    g = gcd(g, v[i]);
  }

  for (int i = 0; i < tmp.size(); ++i) {
    tmp[i] /= g;
  }

  if (g > 1 && (g % 2 == 0 || isPal(tmp))) {
    string cur = build(tmp, true), ret = cur;
    for (int i = 1; i < g; ++i) {
      reverse(cur.begin(), cur.end());
      ret += cur;
    }
    ans *= g;
    return ret;
  } else {
    int ind = -1;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] & 1) ind = i;
    }
    string cur, fuck;
    for (int i = 0; i < v.size(); ++i) {
      if (i == ind) continue;
      cur += string(v[i] / 2, char('a' + i));
      if (v[i] & 1) fuck += char('a' + i);
    }
    if (ind != -1)
      cur += string(v[ind] / 2, char('a' + ind));
    string ret = cur;
    if (ind != -1) ret += char('a' + ind);
    reverse(cur.begin(), cur.end());
    ret += cur;

    if (fuck.size() == 0 || in) ans = 1;
    else ans = 0;

    return ret + fuck;
  }
  return "fuck";
}

int main() {
  ios::sync_with_stdio(false);
  // gen(8, "");
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  string s = build(v, false);
  if (n == 1) ans = v[0];
  cout << ans << endl;
  cout << s << endl;
  return 0;
}