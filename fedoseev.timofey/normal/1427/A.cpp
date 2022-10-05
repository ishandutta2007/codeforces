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
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum == 0) {
      cout << "NO\n";
    } else if (sum > 0) {
      sort(a.rbegin(), a.rend()); 
      cout << "YES\n";
      for (int x : a) {
        cout << x << ' ';
      }
      cout << '\n';
    } else {
      sort(a.begin(), a.end());
      cout << "YES\n";
      for (int x : a) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
}