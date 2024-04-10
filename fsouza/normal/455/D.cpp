#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

const int maxv = 100000;
const int maxn = 100000;
const int divby = 512, ng = (maxn + divby-1)/divby;

int n, temp[maxn];

struct group {
  vector <int> v;
  int many[maxv];
} g[ng];

void regroup() {
  for (int i = 0; i < ng; i++) {
    for (int j = 0; j < (int)g[i].v.size(); j++)
      g[i].many[g[i].v[j]]--;
    g[i].v.clear();
    g[i].v.reserve(divby);
  }
  for (int i = 0; i < n; i++) {
    g[i / divby].v.push_back(temp[i]);
    g[i / divby].many[temp[i]]++;
  }
}

void fullregroup() {
  int n2 = 0;
  for (int i = 0; i < ng; i++)
    for (int j = 0; j < (int)g[i].v.size(); j++)
      temp[n2++] = g[i].v[j];
  regroup();
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp[i]); temp[i]--;
  }
  regroup();

  int nq;

  scanf("%d", &nq);

  int lastans = 0;  

  for (int q = 0; q < nq; q++) {
    int kind, _l, _r;
    scanf("%d %d %d", &kind, &_l, &_r);
    int l = ((_l + lastans - 1)%n+n)%n;
    int r = ((_r + lastans - 1)%n+n)%n;
    bool schedreg = false;

    if (l > r) swap(l, r);

    if (kind == 1) {
      int oldrv;
      {
	int start = 0;
	for (int i = 0; i < ng; i++) {
	  if (start <= r && r < start + g[i].v.size()) {
	    oldrv = g[i].v[r - start];
	    g[i].v.erase(g[i].v.begin() + r - start);
	    g[i].many[oldrv]--;
	    if (g[i].v.size() > 4 * divby)
	      schedreg = true;
	    break;
	  }
	  start += g[i].v.size();
	}
      }
      {
	int start = 0;
	for (int i = 0; i < ng; i++) {
	  if (start <= l && l <= start + g[i].v.size()) {
	    g[i].v.insert(g[i].v.begin() + l - start, oldrv);
	    g[i].many[oldrv]++;
	    if (g[i].v.size() > 4 * divby)
	      schedreg = true;
	    break;
	  }
	  start += g[i].v.size();
	}
      }
    } else {
      int _k;
      scanf("%d", &_k);
      int k = ((_k + lastans - 1)%n+n)%n;
      
      int ret = 0;

      {
	int start = 0;
	for (int i = 0; i < ng; i++) {
	  const int end = start + g[i].v.size() - 1;

	  if (end < l || start > r) {}
	  else if (l <= start && end <= r) {
	    ret += g[i].many[k];
	  } else {
	    int ss = max(l, start), ee = min(r, end);
	    for (int j = ss; j <= ee; j++)
	      if (g[i].v[j - start] == k)
		ret++;
	    if (g[i].v.size() > 4 * divby)
	      schedreg = true;
	  }
	  
	  start = end+1;
	}
      }

      lastans = ret;
      printf("%d\n", ret);
    }

    if (schedreg)
      fullregroup();
  }
  
  return 0;
}