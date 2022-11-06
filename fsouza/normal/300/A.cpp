#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <numeric>

using namespace std;

typedef long long lint;

int main() {
  int n;
  vector<int> ans[3];

  cin >> n;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (v < 0) ans[0].push_back(v);
    if (v > 0) ans[1].push_back(v);
    if (v == 0) ans[2].push_back(v);
  }

  if (ans[1].empty()) {
    ans[1].push_back(ans[0].back()); ans[0].pop_back();
    ans[1].push_back(ans[0].back()); ans[0].pop_back();
  }
  if (ans[0].size()%2 == 0) {
    ans[2].push_back(ans[0].back()); ans[0].pop_back();
  }

  for (int k = 0; k < 3; k++) {
    cout << ans[k].size();
    for (int i = 0; i < (int)ans[k].size(); i++)
      cout << " " << ans[k][i];
    cout << endl;
  }

  return 0;
}