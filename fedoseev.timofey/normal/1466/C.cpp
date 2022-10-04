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
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] != '#' && i - 1 >= 0 && s[i] == s[i - 1]) {
        s[i] = '#';
        ++ans;
      }
      if (s[i] != '#' && i - 2 >= 0 && s[i] == s[i - 2]) {
        s[i] = '#';
        ++ans;
      }
    } 
    cout << ans << '\n';
  }
}