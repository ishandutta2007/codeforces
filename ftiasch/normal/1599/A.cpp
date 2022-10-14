#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::vector<char> s(n + 1);
  scanf("%s", s.data());
  std::sort(a.begin(), a.end());
  int keeps = 0;
  for (int i = 1; i < n; ++i) {
    keeps += s[i - 1] == s[i];
  }
  int i = keeps;
  int j = keeps;
  char sides[] = {'L', 'R'};
  if (sides[j & 1] != s[0]) {
    std::swap(sides[0], sides[1]);
  }
  for (int k = 0; k < n; ++k) {
    if (k && s[k - 1] == s[k]) {
      --i;
      printf("%d %c\n", a[i], sides[i & 1]);
    } else {
      printf("%d %c\n", a[j], sides[j & 1]);
      j++;
    }
  }
}