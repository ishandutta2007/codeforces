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

const int N = 2e5 + 7;

bool pr[N];
vector <int> p[N];
int cnt[N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  for (int i = 2; i < N; ++i) pr[i] = true;
  for (int i = 2; i < N; ++i) {
    if (pr[i]) {
      for (int j = i; j < N; j += i) {
        p[j].push_back(i);
        if (j != i) pr[j] = false;
      }
    }
  }
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int x : p[a[i]]) {
      ++cnt[x];
    }
  }
  ll ans = 1;
  for (int i = 2; i < N; ++i) {
    if (cnt[i] >= n - 1) {
      int m1 = 1e9, m2 = 1e9;
      for (int j = 0; j < n; ++j) {
        int cur = a[j], cnt = 0;
        while (cur % i == 0) {
          ++cnt;
          cur /= i;
        }
        if (cnt < m1) swap(m1, cnt);
        if (cnt < m2) swap(m2, cnt);
      }
      for (int j = 0; j < m2; ++j) {
        ans *= i;
      }
    }
  }
  cout << ans << '\n';
}