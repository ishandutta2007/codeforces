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

const int N = 100010;

int ans;
ll n;
int m;
ll k;
ll p[N];

int main() {
  scanf("%lld%d%lld", &n, &m, &k);
  for (int i = 1; i <= m; ++i)
    scanf("%lld", &p[i]);
  for (int l = 1, r; l <= m; l = r + 1) {
    ++ans;
    r = l;
    ll curpos = p[l] - (l - 1);
    ll top = (curpos + k - 1) / k * k - curpos + p[l];
    while (r < m && p[r + 1] <= top) ++r;
  }
  printf("%d\n", ans);
  return 0;
}