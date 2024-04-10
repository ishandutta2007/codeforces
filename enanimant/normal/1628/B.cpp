/*
 * author:  ADMathNoob
 * created: 01/22/22 09:35:12
 * problem: https://codeforces.com/contest/1628/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

string Reversed(const string& s) {
  string t = s;
  reverse(t.begin(), t.end());
  return t;
}

bool TestCase() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == Reversed(a[i])) {
      return true;
    }
  }
  set<string> s;
  for (int i = 0; i < n; i++) {
    string rev = Reversed(a[i]);
    if (s.count(rev)) {
      return true;
    }
    int L = a[i].size();
    if (L == 2) {
      for (char c = 'a'; c <= 'z'; c++) {
        string t = rev + c;
        if (s.count(t)) {
          return true;
        }
      }
    } else {
      assert(L == 3);
      string t = rev.substr(0, 2);
      if (s.count(t)) {
        return true;
      }
    }
    s.insert(a[i]);
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cout << (TestCase() ? "YES" : "NO") << '\n';
  }
  return 0;
}