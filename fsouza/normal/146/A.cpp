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
  char s[64];
  scanf("%d %s", &n, s);

  bool ok = true;
  int sum[2] = {0};

  for (int i = 0; i < n; i++) {
    if (s[i] != '4' && s[i] != '7')
      ok = false;
    sum[i/(n/2)] += s[i]-'0';
  }

  if (sum[0] != sum[1]) ok = false;

  if (ok) printf("YES\n");
  else printf("NO\n");

  return 0;
}