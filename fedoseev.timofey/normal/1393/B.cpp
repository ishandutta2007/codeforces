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

const int N = 1e5 + 7;

int cnt[N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int cnt_2 = 0, cnt_4 = 0, cnt_6 = 0, cnt_8 = 0;
  auto go = [&] (int x, int s) {
    if (cnt[x] >= 2) cnt_2 += s;
    if (cnt[x] >= 4) cnt_4 += s;
    if (cnt[x] >= 6) cnt_6 += s;
    if (cnt[x] >= 8) cnt_8 += s;
  };  
  auto add = [&] (int x, int s) {
    go(x, -1);
    cnt[x] += s;
    go(x, 1);
  };
  auto answer = [&] () {
    if (cnt_8 > 0) return 1;
    if (cnt_6 > 0 && cnt_2 > 1) return 1;
    if (cnt_4 > 1) return 1;
    if (cnt_4 > 0 && cnt_2 > 2) return 1;
    return 0;
  };
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    add(x, 1);
  }
  int q;
  cin >> q;
  while (q--) {
    char c;
    cin >> c;
    int x;
    cin >> x;
    if (c == '+') add(x, 1);
    else add(x, -1);
    if (answer()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }   
}