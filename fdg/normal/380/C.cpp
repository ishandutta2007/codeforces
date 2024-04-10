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
int sum[1000006];

int get_s(int l, int r) {
  return sum[r] - (l > 0 ? sum[l - 1] : 0);
}

int tree[4000002];

void build(int i, int l, int r) {
  if (l == r) {
    tree[i] = sum[l];
    return;
  }
  int m = (l + r) >> 1;
  build(2 * i, l, m);
  build(2 * i + 1, m + 1, r);
  tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

int find(int i, int l, int r, int L, int R) {
  if (l == L && r == R) {
    return tree[i];
  }
  int m = (l + r) >> 1;
  if (R <= m) return find(2 * i, l, m, L, R);
  if (L > m) return find(2 * i + 1, m + 1, r, L, R);
  return min(find(2 * i, l, m, L, m), find(2 * i +1, m + 1, r, m + 1, R));
}

int main() {
  gets(str);
  int n = strlen(str);
  for (int i = 0; i < n; ++i) {
    sum[i] = str[i] == '(' ? 1 : -1;
    if (i) {
      sum[i] += sum[i - 1];   
    }
  }
  build(1, 0, n - 1);

  int q, l, r;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &l, &r); --l; --r;
    int mn = find(1, 0, n - 1, l, r);
    int ans = r - l + 1;
    int left = l > 0 ? sum[l - 1] : 0;
    int add = get_s(l, r);
    if (mn < left) {
      ans -= (left - mn);
      add += (left - mn);
    }
    if (add != 0) {
      ans -= add;
    }
    // cout << mn << " " << "  " << left << "  " << add << " " << ans << endl;
    printf("%d\n", ans);
  }
  return 0;
}