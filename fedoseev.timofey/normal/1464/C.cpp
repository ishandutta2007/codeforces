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
  /*int n;
  cin >> n;
  vector <set <string>> ok(n + 1);
  ok[1].insert("1");
  for (int i = 2; i <= n; ++i) {
    for (int l = 1; l < i; ++l) {
      int r = i - l;
      for (auto sl : ok[l]) {
        for (auto sr : ok[r]) {
          string cur = sl;
          for (auto &c : cur) {
            if (c == '0') c = '1';
            else c = '0';
          }
          cur += sr;
          ok[i].insert(cur);
        }
      }
    }
  }
  for (int l = 1; l <= n; ++l) {
    for (string s : ok[l]) {
      cout << s << endl;
    }
  }*/
  int n; ll t;
  cin >> n >> t;
  vector <int> pw(n);
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    pw[i] = c - 'a';
  }
  t -= 1 << pw.back();
  pw.pop_back();
  t += 1 << pw.back();
  pw.pop_back();
  n -= 2;
  t = abs(t);
  for (int i = 0; i < n; ++i) t += 1 << pw[i];
  for (int i = 0; i < n; ++i) ++pw[i];
  sort(pw.rbegin(), pw.rend());
  for (auto x : pw) if (t >= (1 << x)) t -= (1 << x);
  if (t == 0) cout << "Yes\n";
  else cout << "No\n";
}