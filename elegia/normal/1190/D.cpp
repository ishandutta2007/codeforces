#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>
 
#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200010;

ll ans;
int n;
int dc[N], fw[N];
bool vis[N];

pair<int, int> p[N];

int lowBit(int k) { return k & -k; }

void ch(int k) {
  for (; k <= n; k += lowBit(k))
    ++fw[k];
}

int qry(int k) {
  int ret = 0;
  for (; k; k -= lowBit(k))
    ret += fw[k];
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = make_pair(-y, x);
    dc[i] = x;
  }
  sort(dc + 1 , dc + n + 1);
  sort(p + 1, p + n + 1);
  int cnt = 0;
  for (int l = 1, r = 1; l <= n; l = r + 1) {
    while (r < n && p[r + 1].first == p[l].first) ++r;
    int cur = 0;
    for (int i = l; i <= r; ++i) {
      int ind = lower_bound(dc + 1, dc + n + 1, p[i].second) - dc;
      if (!vis[ind]) {
        vis[ind] = true;
        ch(ind);
        ++cnt;
      }
      int cn = qry(ind - 1) - qry(cur);
      ans -= cn * (cn + 1LL) / 2;
      cur = ind;
    }
    int cn = qry(n) - qry(cur);
    ans -= cn * (cn + 1LL) / 2;
    ans += cnt * (cnt + 1LL) / 2;
  }
  printf("%lld\n", ans);
  return 0;
}