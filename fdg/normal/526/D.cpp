#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char str[1000006];
int p[1000006];

int main() {
  int n, k;
  scanf("%d%d\n", &n, &k);
  gets(str);

  for (int i = 1; i < n; ++i) {
    int j = p[i - 1];
    while (j > 0 && str[i] != str[j])
      j = p[j - 1];
    if (str[i] == str[j])  ++j;
    p[i] = j;
  }
  // for (int i = 0; i < n; ++i) {
  //   cout << p[i] << " ";
  // }
  // cout << endl;
  for (int i = 0; i < n; ++i) {
    if (k == 1) {
      printf("1");
      continue;
    }
    long long len = (i + 1 - p[i]);
    if (len > 0) {
      long long x = (i + 1) / len / k;
      long long shift = len * x;
      // cout << i << "  " << len << "  " << shift << endl;
      if (i + 1 >= 1LL * shift * k && i + 1 <= 1LL * shift * (k + 1)) printf("1");
      else printf("0");
    } else {
      printf("0");
    }
  }
  puts("");
  // cout << endl;

  return 0;
}