#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
  printf("? %d %d\n", a, b);
  fflush(stdout);
  char c;
  scanf(" %c", &c);
  return c == '<';
}

void answer(int mn, int mx) {
  printf("! %d %d\n", mn, mx);
  fflush(stdout);
}

void licz(int n) {
  vector<int> g, d;
  for (int i = 2; i <= n; i += 2) {
    if (cmp(i - 1, i)) {
      d.push_back(i - 1);
      g.push_back(i);
    } else {
      d.push_back(i);
      g.push_back(i - 1);
    }
  }
  if (n % 2 == 1) {
    if (cmp(g.back(), n)) {
      g.push_back(n);
    } else {
      d.push_back(n);
    }
  }
  while ((int) g.size() > 1) {
    const int a = g.back();
    g.pop_back();
    const int b = g.back();
    g.pop_back();
    if (cmp(a, b)) {
      g.push_back(b);
    } else {
      g.push_back(a);
    }
  }
  while ((int) d.size() > 1) {
    const int a = d.back();
    d.pop_back();
    const int b = d.back();
    d.pop_back();
    if (cmp(a, b)) {
      d.push_back(a);
    } else {
      d.push_back(b);
    }
  }
  answer(d[0], g[0]);
}

void przyp() {
  int n;
  scanf("%d", &n);
  if (n == 1) answer(1, 1);
  else licz(n);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) przyp();
  return 0;
}