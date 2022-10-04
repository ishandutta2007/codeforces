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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <vector <int>> nums;
    nums.push_back(vector <int> {1});
    for (int i = 1; i < (int)a.size(); ++i) {
      int x = a[i];
      vector <int> cur = nums.back();
      if (x == 1) {
        cur.push_back(1);
        nums.push_back(cur);
        continue;
      }
      while (x != cur.back() + 1) {
        cur.pop_back();
      }
      ++cur.back();
      nums.push_back(cur);
    }
    for (auto v : nums) {
      for (int i = 0; i < (int)v.size(); ++i) {
        cout << v[i];
        if (i != (int)v.size() - 1) cout << '.';
      }
      cout << '\n';
    }
  }
}