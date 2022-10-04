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

vector <int> p = {0, 5, 3, 2, 4, 1};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < 6; ++i) {
    if (n & (1 << i)) {
      res |= 1 << (5 - p[5 - i]);
    }
  }
  cout << res << '\n';
}