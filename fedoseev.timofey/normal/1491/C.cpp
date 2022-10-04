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
    vector <int> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector <int> nxt(n + 1);
    auto recalc = [&] () {
      nxt[n] = n;
      for (int i = n - 1; i >= 0; --i) {
        if (s[i] != 1) {
          nxt[i] = i;
        } else {
          nxt[i] = nxt[i + 1];
        }
      }
    };
    recalc();
    vector <int> kl(n);
    ll ans = 0;

    function <void(int)> go = [&] (int pos) {
      if (pos == n) return;
      int jump = s[pos];
      if (s[pos] > 1) {
        --s[pos];
        go(nxt[min(n, pos + jump)]);
      } else {
        if(!kl[pos]) {
          kl[pos] = 1;
          recalc();
          go(nxt[pos + 1]);
        }
      }
    };  
    for (int i = 0; i < n; ++i) {
      int extra = max(0, i + s[i] - n);
      ans += extra;
      s[i] -= extra;
      while (s[i] > 1) {
        go(i);
        ++ans;
      }
    }
    cout << ans << '\n';
  }   
}