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

const int K = 30;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector <int> cnt(K);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < K; ++j) {
      if (a[i] & (1 << j)) {
        ++cnt[j];
      }
    }
  }
  int ans = -1, id = -1;
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    for (int j = 0; j < K; ++j) {
      if (cnt[j] == 1 && (a[i] & (1 << j))) {
        cur |= (1 << j);
      }
    }
    if (cur > ans) {
      ans = cur;
      id = i;
    }
  }
  cout << a[id] << ' ';
  for (int i = 0; i < n; ++i) {
    if (i != id) {
      cout << a[i] << ' ';
    }
  }
}