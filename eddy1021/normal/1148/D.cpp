#include <bits/stdc++.h>
using namespace std;
constexpr int N = 303030;
int n, a[N], b[N];
vector<int> x, y;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] > b[i]) {
      x.push_back(i);
    }
    if (a[i] < b[i]) {
      y.push_back(i);
    }
  }
  if (x.size() > y.size()) {
    sort(x.begin(), x.end(), [&](int id1, int id2){
      return b[id1] < b[id2];
    });
  } else {
    sort(y.begin(), y.end(), [&](int id1, int id2){
      return b[id1] > b[id2];
    });
    x = y;
  }
  printf("%d\n", (int)x.size());
  for (size_t i = 0; i < x.size(); ++i) {
    printf("%d%c", x[i], " \n"[i + 1 == x.size()]);
  }
}