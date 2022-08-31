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

const int N = 2010;

map<int, vector<int>> pos;

int n;
int l[N];

void upd(int& x, int y) { if (x > y) x = y; }

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    pos[x].push_back(i);
  }
  fill(l + 1, l + n + 1, n + 1);
  for (const auto& pr : pos) {
    if (pr.second.size() == 1) continue;
    const auto& p = pr.second;
    int m = p.size();
    upd(l[n], p[1]);
    upd(l[p[m - 1] - 1], p[0]);
    upd(l[p[m - 2] - 1], 0);
  }
  int ans = n;
  for (int i = n; i; --i) {
    if (l[i] > 0) upd(ans, max(0, i - l[i] + 1));
    upd(l[i - 1], l[i]);
  }
  printf("%d\n", ans);
  return 0;
}