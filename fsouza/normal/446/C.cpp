#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <numeric>

using namespace std;

typedef long long lint;

const int gsize = 4096;
const int mod = 1000000009;

int main() {
  int n, mq;

  scanf("%d %d", &n, &mq);

  vector<int> f(n), facc(n);

  f[0] = 1;
  facc[0] = 1;
  for (int i = 1; i < n; i++) {
    f[i] = f[i-1];
    if (i-2 >= 0) {
      f[i] += f[i-2];
      if (f[i] >= mod) f[i] -= mod;
    }

    facc[i] = f[i] + facc[i-1];
    if (facc[i] >= mod) facc[i] -= mod;
  }

  vector<int> delta(n), v(n), acc(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);

    delta[i] = v[i];
    if (i-1 >= 0) {
      delta[i] -= v[i-1];
      if (delta[i] < 0) delta[i] += mod;
    }
    if (i-2 >= 0) {
      delta[i] -= v[i-2];
      if (delta[i] < 0) delta[i] += mod;
    }

    acc[i] = v[i];
    if (i-1 >= 0) {
      acc[i] += acc[i-1];
      if (acc[i] >= mod) acc[i] -= mod;
    }
  }
  
  for (int q = 0; q < mq; q++) {
    int kind, l, r;
    
    scanf("%d %d %d", &kind, &l, &r); l--, r--;

    if (kind == 1) {
      if (l == r) {
	delta[l]++;
	if (delta[l] == mod) delta[l] = 0;
	if (r+1 < n) {
	  delta[r+1]--;
	  if (delta[r+1] == -1) delta[r+1] = mod-1;
	  if (r+2 < n) {
	    delta[r+2]--;
	    if (delta[r+2] == -1) delta[r+2] = mod-1;
	  }
	}
      } else {
	delta[l]++;
	if (delta[l] == mod) delta[l] = 0;
	if (r+1 < n) {
	  delta[r+1] -= f[r-l];
	  if (delta[r+1] < 0) delta[r+1] += mod;
	  delta[r+1] -= f[r-1-l];
	  if (delta[r+1] < 0) delta[r+1] += mod;
	  
	  if (r+2 < n) {
	    delta[r+2] -= f[r-l];
	    if (delta[r+2] < 0) delta[r+2] += mod;
	  }
	}
      }

      for (int x = -2+gsize; x < n; x += gsize)
	for (int y = x; y <= x+1; y++) {
	  if (l <= y && y <= r) {
	    v[y] += f[y-l];
	    if (v[y] >= mod) v[y] -= mod;
	    acc[y] += facc[y-l];
	    if (acc[y] >= mod) acc[y] -= mod;
	  } else if (r < y) {
	    acc[y] += facc[r-l];
	    if (acc[y] >= mod) acc[y] -= mod;
	  }
	}
    } else {
      for (int fixi = 0; fixi < 2; fixi++) {
	int fix = (fixi ? r : (l-1));
	if (fix < 0) continue;
	
	int start = fix - fix%gsize;
	
	for (int j = start; j <= fix; j++) {
	  v[j] = delta[j];
	  if (j-1 >= 0) {
	    v[j] += v[j-1];
	    if (v[j] >= mod) v[j] -= mod;
	    if (j-2 >= 0) {
	      v[j] += v[j-2];
	      if (v[j] >= mod) v[j] -= mod;
	    }
	  }
	  acc[j] = v[j];
	  if (j-1 >= 0) {
	    acc[j] += acc[j-1];
	    if (acc[j] >= mod) acc[j] -= mod;
	  }
	}
      }
      
      int ret = acc[r];
      if (l-1 >= 0) {
	ret -= acc[l-1];
	if (ret < 0) ret += mod;
      }

      printf("%d\n", ret);
    }
  }

  return 0;
}