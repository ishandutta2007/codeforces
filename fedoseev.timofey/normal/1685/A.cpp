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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    if (n % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    vector<int> b(n, -1);
    int who = -1;
    if (a[n / 2] == a[n / 2 - 1]) {
      who = a[n / 2];
      int cnt_sm = 0, cnt_bg = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] == who) {
          if (i < n / 2) ++cnt_sm;
          else ++cnt_bg;
        }
      }
      for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
          if (b[(i + n - 1) % n] == -1 && b[(i + 1) % n] == -1 && cnt_sm > 0) {
            b[i] = who;
            --cnt_sm;
          }
        } else {
          if (b[(i + n - 1) % n] == -1 && b[(i + 1) % n] == -1 && cnt_bg > 0) {
            b[i] = who;
            --cnt_bg;
          }
        }
      }
      if (cnt_sm != 0 || cnt_bg != 0) {
        cout << "NO\n";
        continue;
      }
    }
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i) {
      if (b[i] == -1) {
        if (i % 2 == 0) b[i] = a[l++];
        else b[i] = a[r--];
      }
    }
    cout << "YES\n";
    for (auto x : b) cout << x << ' ';
    cout << '\n';
  }
}