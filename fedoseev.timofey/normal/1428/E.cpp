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
  int n, k;
  cin >> n >> k;
  k -= n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  auto get = [&] (int x, int y) {
    int l = x / y;
    int h = l + 1;
    int cnth = x % y;
    int cntl = y - cnth;
    return (ll)l * l * cntl + (ll)h * h * cnth;
  };  
  ll ans = 0;
  set <pair <ll, int>> have;
  vector <int> num(n, 1);
  for (int i = 0; i < n; ++i) {
    ans += (ll)a[i] * a[i];
    if (a[i] > num[i]) {
      have.insert(make_pair(-get(a[i], num[i]) + get(a[i], num[i] + 1), i));
    }
  }
  for (int tt = 0; tt < k; ++tt) {
    auto p = *have.begin();
    have.erase(have.begin());
    ans += p.first;
    int i = p.second;
    ++num[i];
    if (a[i] > num[i]) {
      have.insert(make_pair(-get(a[i], num[i]) + get(a[i], num[i] + 1), i));
    }
  }
  cout << ans << '\n';
}