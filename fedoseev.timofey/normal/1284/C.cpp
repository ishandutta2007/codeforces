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
#include <cassert>
#include <complex>
 
using namespace std;
 
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <int> f(n + 1);
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = ((ll)f[i - 1] * i) % m;
  }
  int ans = 0;
  for (int len = 1; len <= n; ++len) {
    int cnt = ((ll)(((ll)(n - len + 1) * f[len]) % m) * f[n - len]) % m;
    ans += ((ll)cnt * (n - len + 1)) % m;
    ans %= m;
  }
  cout << ans << '\n';
}