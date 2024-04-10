#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
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

const int N = 100010;

int n;
ll best = 5;
ll ans;
deque<int> w, g;
ll l[N];
char s[N];

void cost(ll& a, ll& b, ll c) {
  ll cur = min(a, b);
  a -= cur;
  b -= cur;
  ans += cur * c;
}

void cost(ll& a, deque<int>& q, ll c, bool f) {
  while (!q.empty() && a) {
    int i = f ? q.front() : q.back();
    ll cur = min(a, l[i]);
    l[i] -= cur;
    a -= cur;
    ans += cur * c;
    if (l[i] == 0)
      f ? q.pop_front() : q.pop_back();
  }
}

int main() {
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &l[i]);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i)
    if (s[i] == 'L') {
      cost(l[i], w, 4, true);
      cost(l[i], g, 6, false);
      cost(l[i], g, 6, false);
      ans += l[i] * (best + 1);
    } else if (s[i] == 'W') {
      best = 3;
      w.push_front(i);
    } else {
      g.push_front(i);
    }
  ll wsum = 0, gs = 0;
  for (int i = 1; i <= n; ++i)
    if (s[i] == 'W')
      wsum += l[i];
    else if (s[i] == 'G') {
      cost(l[i], wsum, 4);
      gs += l[i];
    }
  ans += wsum * 2 + gs * 3;
  printf("%lld\n", ans);

  return 0;
}