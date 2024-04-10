// August 30, 2019
// https://codeforces.com/contest/1213/problem/E

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  string s, t;
  cin >> n >> s >> t;
  function<bool(string)> works = [&](const string &ss) {
    for (int i = 0; i < (int) ss.size() - 1; i++) {
      string tmp = ss.substr(i, 2);
      if (tmp == s || tmp == t) {
        return false;
      }
    }
    return true;
  };
  string ord = "abc";
  cout << "YES\n";
  do {
    string test = "";
    for (int i = 0; i < n; i++) {
      test += ord;
    }
    if (works(test)) {
      cout << test << '\n';
      return 0;
    }
    test = "";
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
        test += ord[i];
      }
    }
    if (works(test)) {
      cout << test << '\n';
      return 0;
    }
  } while (next_permutation(ord.begin(), ord.end()));
  assert(0);


  return 0;
}