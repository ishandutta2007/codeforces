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
 
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int sum = 0;
    for (char c : s) sum += c - '0';
    if (sum % 3 != 0) {
      cout << "cyan\n";
      continue;
    }
    bool ok = false;
    for (int i = 0; i < (int)s.size(); ++i) {
      for (int j = 0; j < (int)s.size(); ++j) {
        if (i == j) continue;
        int x = 10 * (s[i] - '0') + s[j] - '0';
        if (x % 10 == 0 && x % 4 == 0) ok = true;
      }
    }
    if (ok) cout << "red\n";
    else cout << "cyan\n";
  }
}