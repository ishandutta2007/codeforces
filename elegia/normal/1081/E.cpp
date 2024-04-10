#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 100010;

int n;
int cur;
ll sum = 0;
ll x[N];

bool issq(ll x) {
  int v = sqrt(x);
  while (v * (ll)v < x)
    ++v;
  return v * (ll)v == x; 
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 2; i <= n; i += 2) {
    scanf("%lld", &x[i]);
  }
  for (int i = 1; i <= n; i += 2) {
    bool flag = false;
    while (cur <= 300000) {
      ++cur;
      ll good = cur * (ll)cur - x[i + 1];
      if (good > 0 && issq(good)) {
        if (good > sum) {
          flag = true;
          x[i] = good - sum;
          sum = cur * (ll)cur; 
          break;
        }
      }
    }
    if (!flag) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  for (int i = 1; i <= n; ++i)
    printf("%lld ", x[i]);
  
#ifdef LBT
  LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}