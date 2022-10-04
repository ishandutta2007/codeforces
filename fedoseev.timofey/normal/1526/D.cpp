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
    string s;
    cin >> s;
    int n = s.size();
    set <char> have;
    for (auto c : s) {
      have.insert(c);
    }
    vector <char> p = vector <char> (have.begin(), have.end());
    ll best = -1;
    string ans;
    do {
      string cur;
      vector <int> go(n);
      int uk = 0;
      for (auto c : p) {
        for (int i = 0; i < n; ++i) {
          if (s[i] == c) {
            cur += c;
            go[i] = uk++;
          }
        }
      }
      vector <int> f(n);
      auto modify = [&] (int x) {
        for (; x < n; x |= x + 1) ++f[x];
      };
      auto sum = [&] (int r) {
        int res = 0;
        for (; r >= 0; r &= r + 1, --r) {
          res += f[r];
        }
        return res;
      };
      ll score = 0;
      for (int i = n - 1; i >= 0; --i) {
        score += sum(go[i]);
        modify(go[i]);
      }
      if (score > best) {
        best = score;
        ans = cur;
      }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
  }
}