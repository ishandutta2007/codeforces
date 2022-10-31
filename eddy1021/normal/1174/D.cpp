#include <bits/stdc++.h>
using namespace std;
constexpr int N = 18;
int n, x;
int main() {
  scanf("%d%d", &n, &x);
  vector<int> v;
  v.push_back(0);
  for (int i = 1; i < (1 << n); ++i) {
    int idx = lower_bound(v.begin(), v.end(), i ^ x) - v.begin();
    if (idx == (int)v.size() or (v[idx] != (i ^ x))) {
      v.push_back(i);
    }
  }
  printf("%d\n", (int)v.size() - 1);
  for (size_t i = 1; i < v.size(); ++i) {
    printf("%d%c", v[i] ^ v[i - 1], " \n"[i + 1 == v.size()]);
  }
}