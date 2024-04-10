#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) { 
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> pos;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        pos.push_back(i);
      }
    }
    if (pos.size() % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    string a(n, '$'), b(n, '$');
    for (int i = 0; i < (int)pos.size(); i += 2) {
      a[pos[i]] = '(';
      a[pos[i + 1]] = ')';
      b[pos[i + 1]] = '(';
      b[pos[i]] = ')';
    }
    for (int it = 0; it < 2; ++it) {
      if (it == 0) {
        string &s = a;
        int cnt = (n - pos.size()) / 2;
        for (int i = 0; i < n; ++i) {
          if (s[i] == '$') {
            if (cnt > 0) {
              s[i] = '(';
              --cnt;
            } else {
              s[i] = ')';
            }
          }
        }
      } else {
        string &s = b;
        int cnt = (n - pos.size()) / 2;
        for (int i = 0; i < n; ++i) {
          if (s[i] == '$') {
            if (cnt > 0) {
              s[i] = '(';
              --cnt;
            } else {
              s[i] = ')';
            }
          }
        }
      }
    }
    auto ok = [&] (string s) {
      int bal = 0;
      for (char c : s) {
        if (c == '(') {
          ++bal;
        } else {
          --bal;
          if (bal < 0) return false;
        }
      }
      return bal == 0;
    };
    if (ok(a) && ok(b)) {
      cout << "YES\n";
      cout << a << '\n' << b << '\n';
    } else {
      cout << "NO\n";
    }
  }
}