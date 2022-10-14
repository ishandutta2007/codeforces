#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 501;

int n, deg[N];

int main() {
  scanf("%d", &n);
  int exceeds = 0;
  std::vector<int> leaves, non_leaves;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", deg + i);
    if (deg[i] == 1) {
      leaves.push_back(i);
    } else {
      exceeds += deg[i] - 2;
      non_leaves.push_back(i);
    }
  }
  int leaf_count = leaves.size();
  if (leaf_count == 0) {
    printf("YES %d\n%d\n", n - 1, n - 1);
    for (int i = 2; i <= n; ++i) {
      printf("%d %d\n", i - 1, i);
    }
  } else if (leaf_count == 1) {
    printf("YES %d\n%d\n", n - 1, n - 1);
    printf("%d %d\n", leaves[0], non_leaves[0]);
    for (int i = 1; i < non_leaves.size(); ++i) {
      printf("%d %d\n", non_leaves[i - 1], non_leaves[i]);
    }
  } else if (leaf_count - 2 > exceeds) {
    puts("NO");
  } else {
    printf("YES %d\n%d\n", static_cast<int>(non_leaves.size()) + 1, n - 1);
    printf("%d %d\n", leaves[0], non_leaves[0]);
    for (int i = 1; i < non_leaves.size(); ++i) {
      printf("%d %d\n", non_leaves[i - 1], non_leaves[i]);
    }
    printf("%d %d\n", non_leaves.back(), leaves[1]);
    int p = 2;
    for (int nl : non_leaves) {
      for (int j = 2; j < deg[nl] && p < leaf_count; ++j, ++p) {
        printf("%d %d\n", nl, leaves[p]);
      }
    }
  }
}