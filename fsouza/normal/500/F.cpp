#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 4000
#define MAXB 4000

using namespace std;

struct item_t {
  int cost;
  int gain;
  int when;
  bool operator < (const item_t& other) const {return when < other.when;}
  bool operator < (const int t) const {return when < t;}
} item[MAXN];

bool operator < (int v, const item_t &item) {
  return v < item.when;
}

struct dp_t {
  int maxgain[MAXB+1];

  void update(int c, int g) {
    for (int b = MAXB; b >= 0; b--)
      if (b + c <= MAXB)
	maxgain[b + c] = max(maxgain[b + c], maxgain[b] + g);
  }
} toleft[MAXN], toright[MAXN];

int main() {
  int n, window;

  scanf("%d %d", &n, &window);

  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &item[i].cost, &item[i].gain, &item[i].when);
  }
  sort(item, item+n);

  memset(toleft, 0, sizeof(toleft));
  memset(toright, 0, sizeof(toright));

  for (int i = 0; i < n; i++) {
    if (i-1 >= 0 && item[i-1].when/window == item[i].when/window)
      toleft[i] = toleft[i-1];
    toleft[i].update(item[i].cost, item[i].gain);
  }

  for (int i = n-1; i >= 0; i--) {
    if (i+1 < n && item[i+1].when/window == item[i].when/window)
      toright[i] = toright[i+1];
    toright[i].update(item[i].cost, item[i].gain);
  }

  int nq;

  scanf("%d", &nq);

  for (int q = 0; q < nq; q++) {
    int vis_when, budget;

    scanf("%d %d", &vis_when, &budget);

    int b = vis_when;
    int a = b - window + 1;
    
    int lb = lower_bound(item, item+n, a)-item;
    int _ub = upper_bound(item, item+n, b)-item;

    int gain;

    if (lb == _ub) gain = 0;
    else {
      int ub1 = _ub-1;
      
      if (item[lb].when/window != item[ub1].when/window) {
	gain = 0;
	for (int lbud = 0; lbud <= budget; lbud++)
	  gain = max(gain, toright[lb].maxgain[lbud] +
		     toleft[ub1].maxgain[budget - lbud]);
      } else {
	if (item[ub1].when/window == b/window)
	  gain = toleft[ub1].maxgain[budget];
	else
	  gain = toright[lb].maxgain[budget];
      }
    }

    printf("%d\n", gain);
  }

  return 0;
}