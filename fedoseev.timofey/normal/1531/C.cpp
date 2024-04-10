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
 
// 1, 3, 5, 7, 9, ...
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  if (n == 2) {
    cout << "-1\n";
    exit(0);
  }
  int sum = 0;
  int x = 1;
  set <int> have;
  while (sum < n) {
    sum += x;
    have.insert(x);
    x += 2;
  }
  int need = sum - n;
  if (need % 2 == 1) {
    have.erase(need);
  } else if (need > 0 && need != 2) {
    have.erase(1);
    have.erase(need - 1);
  } else if (need != 0) {
    have.insert(x);
    have.erase(1);
    have.erase(3);
    have.erase(x - 2);
  }
  
  int mx = *have.rbegin() / 2 + 1;
  vector <vector <char>> ans(mx, vector <char> (mx, '.'));
  int uk = 0;
  for (auto x : vector <int> (have.rbegin(), have.rend())) {
    ans[mx - uk - 1][uk] = 'o';
    for (int i = 0; i < x / 2; ++i) {
      ans[mx - uk - 1][uk + i + 1] = 'o';
      ans[mx - uk - 1 - i - 1][uk] = 'o';
    }
    ++uk;
  }
  cout << mx << '\n';
  for (int i = 0; i < mx; ++i) {
    for (int j = 0; j < mx; ++j) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
}