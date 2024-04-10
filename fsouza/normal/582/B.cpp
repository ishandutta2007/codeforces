#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

#define INF 1000000000

const int maxv = 302;

using namespace std;

typedef long long lint;

vector<int> calcdp(vector<int> &a, int maxlen, int v) {
  vector<int> dp(maxlen+1, 0);
  vector<int> minv(maxlen+1, INF); minv[0] = -INF;

  int resultnow = 0;
  
  int i = 0;
  for (int l = 1; l <= maxlen; ++l) {
    int value = a[i];
    if (value <= v) {
      int pos = upper_bound(minv.begin(), minv.end(), value) - minv.begin();
      minv[pos] = min(minv[pos], value);
      resultnow = max(resultnow, pos);
    }

    dp[l] = resultnow;
    
    ++i;
    if (i == (int)a.size()) i = 0;
  }

  return dp;
}

int solve(vector<int> &a, int t, int v) {
  const int n = a.size();
  const int manyv = count(a.begin(), a.end(), v);
  const int maxlen = min(maxv + 1, t) * n;

  vector<int> dpleft = calcdp(a, maxlen, v);
  for (int &x : a) x = -x;
  reverse(a.begin(), a.end());
  vector<int> dpright = calcdp(a, maxlen, -v);
  reverse(a.begin(), a.end());
  for (int &x : a) x = -x;

  const int totallen = t * n;

  int result = 0;
  for (int left = 0; left <= maxlen; left += n) {
    int fullright = totallen - left;
    int extra = max(fullright - maxlen, 0);
    int extrasteps = (extra + n-1) / n;
    int right = fullright - extrasteps * n;

    result = max(result, dpleft[left] + dpright[right] + extrasteps * manyv);
  }

  return result;
}

int solve(vector<int> &a, int t) {
  int ret = 0;
  for (int v = 1; v <= maxv; ++v)
    ret = max(ret, solve(a, t, v));
  return ret;
}

int main() {
  int n, t;

  scanf("%d %d", &n, &t);

  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  printf("%d\n", solve(a, t));
  
  return 0;
}