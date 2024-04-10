// original submission:
// https://codeforces.com/contest/1209/submission/109046612

#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find_set(int v) {
  if (v == parent[v]) {
    return v;
  }
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    parent[b] = a;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> temp(n + 1, 0);
  parent = temp;
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    union_sets(x, y);
  }
  vector<int> seen(n + 1, 0);
  int count = -1;
  for (int s : parent) {
    int p = find_set(s);
    if (!seen[p]) {
      count++;
      seen[p] = 1;
    }
  }
  cout << k - (n - count) << endl;
  return 0;
}