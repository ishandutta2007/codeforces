#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <memory.h>

using namespace std;

int x[100005], y[100005];

// vector<pair<int, int> > all;
vector<int> hor[100005], ver[100005];

int main() {
  // freopen("input.txt", "w", stdout);
  // for (int i = 0; i <= 300; ++i) {
  //   for (int j = 0; j <= 300; ++j)
  //     printf("%d %d\n", i, j);
  // }
  // return 0;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    ver[x[i]].push_back(y[i]);
    hor[y[i]].push_back(x[i]);
    // all.push_back(make_pair(x[i], y[i]));
  }
  // sort(all.begin(), all.end());
  for (int i = 0; i <= 100000; ++i) {
    sort(hor[i].begin(), hor[i].end());
    sort(ver[i].begin(), ver[i].end());
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int ph = lower_bound(hor[y[i]].begin(), hor[y[i]].end(), x[i]) - hor[y[i]].begin();
    int pv = lower_bound(ver[x[i]].begin(), ver[x[i]].end(), y[i]) - ver[x[i]].begin();
    ++ph; ++pv;
    while (ph < hor[y[i]].size() && pv < ver[x[i]].size()) {
      if (hor[y[i]][ph] - x[i] == ver[x[i]][pv] - y[i]) {
        // pair<int> np = make_pair(hor[y[i]][ph], ver[x[i]][pv]);
        int pos = lower_bound(ver[hor[y[i]][ph]].begin(), ver[hor[y[i]][ph]].end(), ver[x[i]][pv]) - ver[hor[y[i]][ph]].begin();
        if (pos < ver[hor[y[i]][ph]].size() && ver[hor[y[i]][ph]][pos] == ver[x[i]][pv]) ++ans;
        ++ph; ++pv;
      } else if (hor[y[i]][ph] - x[i] < ver[x[i]][pv] - y[i]) {
        ++ph;
      } else {
        ++pv;
      }
    }
  }
  cout << ans << endl;
  return 0;
}