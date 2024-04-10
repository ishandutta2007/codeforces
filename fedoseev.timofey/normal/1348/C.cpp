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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 1) {
      sort(s.begin(), s.end());
      cout << s << '\n';
      continue;
    }
    vector <int> cnt(26);
    for (char c : s) {
      ++cnt[c - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > 0) {
        if (cnt[i] < k) {
          int sum = 0;
          for (int j = 0; j < 26; ++j) {
            sum += cnt[j];
            if (sum >= k) {
              cout << char('a' + j);
              break;
            }
          }
          cout << '\n';
        } else {
          cnt[i] -= k;
          cout << char('a' + i);
          int have = 0;
          for (int j = 0; j < 26; ++j) have += (cnt[j] > 0);
          if (have == 0);
          else if (have == 1) {
            for (int j = 0; j < 26; ++j) {
              if (cnt[j] > 0) {
                int ln = (cnt[j] + k - 1) / k;
                for (int k = 0; k < ln; ++k) cout << char('a' + j);
              }
            }
          } else {
            for (int j = 0; j < 26; ++j) {
              for (int k = 0; k < cnt[j]; ++k) {
                cout << char('a' + j);
              }
            }
          }
          cout << '\n';
        }
        break;
      }
    }
  }
}