#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  
  vector<int> toleft(n), toright(n);

  int now = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && v[i] <= v[i-1]) now = 1;
    else now++;
    toleft[i] = now;
  }

  now = 0;
  for (int i = n-1; i >= 0; i--) {
    if (i < n-1 && v[i] >= v[i+1]) now = 1;
    else now++;
    toright[i] = now;
  }

  int ret = max(*max_element(toleft.begin(), toleft.end()), *max_element(toright.begin(), toright.end()));
  
  for (int i = 0; i < n; i++) {
    int res = 1;

    if (i-1 >= 0) res = max(res, toleft[i-1] + 1);
    if (i+1 < n) res = max(res, 1 + toright[i+1]);
    
    if (i-1 >= 0 && i+1 < n && v[i-1]+1 < v[i+1])
      res = max(res, toleft[i-1] + 1 + toright[i+1]);

    ret = max(ret, res);
  }

  printf("%d\n", ret);

  return 0;
}