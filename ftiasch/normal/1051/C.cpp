#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100;

int n;
char plan[N + 1];
std::pair<int, int> a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  std::sort(a, a + n);
  std::fill(plan, plan + n, 'A');
  plan[n] = '\0';
  int parity = 0, free = -1;
  for (int i = 0; i < n;) {
    int j = i;
    while (j < n && a[i].first == a[j].first) {
      j++;
    }
    if (j - i == 1) {
      plan[a[i].second] = "AB"[parity];
      parity ^= 1;
    } else if (j - i == 2) {
      plan[a[i + 1].second] = 'B';
    } else {
      free = a[i].second;
    }
    i = j;
  }
  if (!parity || ~free) {
    if (parity) {
        plan[free] = 'B';
    }
    printf("YES\n%s\n", plan);
  } else {
    puts("NO");
  }
}