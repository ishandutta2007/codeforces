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

const int md = 998244353;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  vector <int> p(n);
  vector <int> id;
  ll ans = 0; int cnt = 1;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    if (p[i] > n - k) {
      ans += p[i];
      id.push_back(i);
    } 
  }
  for (int i = 1; i < (int)id.size(); ++i) {
    cnt = (ll)cnt * (id[i] - id[i - 1]) % md;
  }
  cout << ans << ' ' << cnt << '\n';
}