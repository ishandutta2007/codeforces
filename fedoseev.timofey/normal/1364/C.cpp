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
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector <int> have(n + 1);
  for (int i = 0; i < n; ++i) {
    have[a[i]] = 1;
  }
  have[0] = 1;
  int lst = 0;
  vector <int> ans;
  int uk = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > lst) {
      ans.push_back(lst);
    } else {
      while (uk <= n && have[uk]) ++uk;
      ans.push_back(uk++);
    } 
    lst = a[i];
  }
  for (int x : ans) cout << x << ' ';
}