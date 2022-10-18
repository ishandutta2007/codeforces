#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char s[100002];

int main() {
  int n, k;
  scanf("%d%d\n", &n, &k);
  gets(s);
  vector<int> v;
  int ans = 1e+9;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') v.push_back(i);
    if (v.size() >= k + 1) {
      int st = v.size() - (k + 1), fn = v.size() - 1;
      int l = st, r = fn;
      while (r - l > 2) {
        int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (max(v[m1] - v[st], v[fn] - v[m1]) < max(v[m2] - v[st], v[fn] - v[m2])) r = m2;
        else l = m1;
      }
      for (int j = l; j <= r; ++j)
        ans = min(ans, max(v[j] - v[st], v[fn] - v[j]));
    }
  }
  cout << ans << endl;
  return 0;
}