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
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  multiset <int> gs;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    if (sum + a[i] >= 0) {
      sum += a[i];
      gs.insert(a[i]);
    } else if (!gs.empty() && a[i] >= *gs.begin()) {
      sum -= *gs.begin();
      gs.erase(gs.begin());
      gs.insert(a[i]);
      sum += a[i];
    }
  }   
  cout << gs.size() << '\n';
}