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
    int n;
    cin >> n;
    int f = 0;
    for (int i = 1; i < n / 2; ++i) {
      f += (1 << i);
    }
    f += (1 << n);
    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += (1 << i);
    int s = sum - f;
    cout << abs(f - s) << '\n';
  }
}