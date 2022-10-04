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
  //freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  if (n % 2 == 1 && k % 2 == 0) {
    cout << "-1\n";
    return 0;
  }
  for (int cnt = 0; ;++cnt) {
    if (cnt * k >= n && (cnt * k) % 2 == n % 2) {
      vector <int> op(n);
      int ans = 0;
      int have = cnt * k;
      for (int i = 0; i < n; ++i) {
        ++op[i];
        --have;
      }
      int uk = 0;
      assert(have % 2 == 0);
      while (have > 0) {
        op[uk] += 2;
        uk = (uk + 1) % n;
        have -= 2;
      }
      vector <vector <int>> go;
      bool bad = false;
      //for (int i = 0; i < n; ++i) cout << op[i] << ' ';
      //cout << endl;
      for (int i = 0; i < cnt; ++i) {
        vector <int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&] (int i, int j) {
          return op[i] > op[j];
        });
        go.push_back(vector <int> ());
        for (int i = 0; i < k; ++i) {
          go.back().push_back(ord[i] + 1);
          if (op[ord[i]] == 0) {
            bad = true;
            break;
          }
          --op[ord[i]];
        }
      }
      if (bad) continue;
      for (auto v : go) {
        cout << "? ";
        for (auto x : v) cout << x << ' ';
        cout << endl;
        int res;
        cin >> res;
        ans ^= res;
      }
      cout << "! " << ans << endl;
      return 0;
    }
  } 
}