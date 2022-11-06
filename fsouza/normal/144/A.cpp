#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);

  int ret;
  int ma = max_element(v.begin(), v.end())-v.begin();
  int mi = n-1-(min_element(v.rbegin(), v.rend())-v.rbegin());
  
  if (ma < mi) ret = ma + (n-1-mi);
  else ret = ma + (n-1-mi) - 1;

  printf("%d\n", ret);

  return 0;
}