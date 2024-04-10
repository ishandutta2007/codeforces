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
  const int K = 8;
  vector <int> pw(K);
  pw[0] = 1;
  for (int i = 1; i < K; ++i) pw[i] = 10 * pw[i - 1];
  const int N = 1e6 + 7;
  vector <int> can(N);
  can[0] = 1;
  for (int i = 0; i < N; ++i) {
    if (!can[i]) continue;
    for (int j = 2; j < K; ++j) {
      int ni = i + (pw[j] - 1) / 9;
      if (ni < N) can[ni] = 1;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    if (x < N) cout << (can[x] ? "YES" : "NO") << '\n';
    else cout << "YES\n";
  } 
}