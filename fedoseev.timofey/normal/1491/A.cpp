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
  int n, q;
  cin >> n >> q;
  vector <int> a(n);
  vector <int> cnt(2);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int id;
      cin >> id;
      --id;
      --cnt[a[id]];
      a[id] ^= 1;
      ++cnt[a[id]];
    } else {
      int k;
      cin >> k;
      if (cnt[1] >= k) cout << "1\n";
      else cout << "0\n";
    }
  }
}