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
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int n = s.size();

  ll ans = 0;
  for (char a = 'a'; a <= 'z'; ++a) {
    int have = 0;
    for (int i = 0; i < n; ++i) have += (s[i] == a);
    ans = max(ans, (ll)have);

    for (char b = 'a'; b <= 'z'; ++b) {
      int cnt = 0;
      ll cur = 0;
      for (int i = 0; i < n; ++i) {
        if (s[i] == b) cur += cnt;
        if (s[i] == a) ++cnt;
      }
      ans = max(ans, cur);
    }
  }
  cout << ans << '\n';
}