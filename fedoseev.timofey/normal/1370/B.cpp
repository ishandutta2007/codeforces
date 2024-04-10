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
    vector <int> a(2 * n);
    vector <vector <int>> who(2);
    for (int i = 0; i < 2 * n; ++i) {
      cin >> a[i];
      who[a[i] % 2].push_back(i);
    }
    int have = 0;
    for (int tt = 0; tt < 2; ++tt) {
      for (int i = 0; i + 1 < (int)who[tt].size(); i += 2) {
        if (have + 2 < 2 * n) {
          have += 2;
          cout << who[tt][i] + 1 << ' ' << who[tt][i + 1] + 1 << '\n';
        }
      }
    }
  }   
}