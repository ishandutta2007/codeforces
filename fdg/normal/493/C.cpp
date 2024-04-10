#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

void read(vector<int>& a) {
  int n;
  scanf("%d", &n);
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
}

int s1, s2;
vector<int> a, b;

void go(int d) {
  if (d < 0) return;
  int r1 = 0, r2 = 0;
  int gr = upper_bound(a.begin(), a.end(), d) - a.begin();
  r1 = 2 * gr + 3 * (a.size() - gr);
  gr = upper_bound(b.begin(), b.end(), d) - b.begin();
  r2 = 2 * gr + 3 * (b.size() - gr);
  if (r1 - r2 > s1 - s2 || r1 - r2 == s1 - s2 && r1 > s1) s1 = r1, s2 = r2;
  // cout << d << "  " << r1 << "  " << r2 << endl;
}

int main() {
  read(a);
  read(b);
  s1 = 2 * a.size();
  s2 = 2 * b.size();
  for (int u : a) {
    go(u);
    go(u - 1);
    go(u + 1);
  }
  for (int u : b) {
    go(u);
    go(u - 1);
    go(u + 1);
  }
  cout << s1 << ":" << s2 << endl;
  return 0;
}