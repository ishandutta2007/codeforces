#line 1 "sol.cpp"
#include <bits/stdc++.h>

std::set<int> xs;
std::set<std::pair<int, int>> ds;

void add(int x) {
  auto it = xs.insert(x).first;
  int prv = it == xs.begin() ? -1 : *std::prev(it);
  int nxt = std::next(it) == xs.end() ? -1 : *std::next(it);
  if (~prv && ~nxt) {
    ds.erase({nxt - prv, nxt});
  }
  if (~prv) {
    ds.emplace(x - prv, x);
  }
  if (~nxt) {
    ds.emplace(nxt - x, nxt);
  }
}

void erase(int x) {
  auto it = xs.find(x);
  int prv = it == xs.begin() ? -1 : *std::prev(it);
  int nxt = std::next(it) == xs.end() ? -1 : *std::next(it);
  xs.erase(it);
  if (~prv && ~nxt) {
    ds.emplace(nxt - prv, nxt);
  }
  if (~prv) {
    ds.erase({x - prv, x});
  }
  if (~nxt) {
    ds.erase({nxt - x, nxt});
  }
}

int ask() {
  if (static_cast<int>(xs.size()) <= 1) {
    return 0;
  }
  return *xs.rbegin() - *xs.begin() - ds.rbegin()->first;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    add(x);
  }
  printf("%d\n", ask());
  while (q--) {
    int op, x;
    scanf("%d%d", &op, &x);
    if (op == 0) {
      erase(x);
    } else {
      add(x);
    }
    printf("%d\n", ask());
  }
}