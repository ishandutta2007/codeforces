#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  const int sum = accumulate(a.begin(), a.end(), 0);
  int ret = 0;

  for (int i = 0; i < n; i++)
    if (a[i]%2 == sum%2)
      ret++;
  
  printf("%d\n", ret);

  return 0;
}