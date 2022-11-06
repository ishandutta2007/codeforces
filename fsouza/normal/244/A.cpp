#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int n, k;
  
  cin >> n >> k;

  vector <bool> used(n*k, false);
  vector <vector <int> > ans(k);

  for (int i = 0; i < k; i++) {
    int want;
    cin >> want; want--;
    ans[i].push_back(want);
    used[want] = true;
  }

  int now = 0;

  for (int i = 0; i < k; i++) {
    while (ans[i].size() < n) {
      if (!used[now]) {
	ans[i].push_back(now);
	used[now] = true;
	now++;
      } else
	now++;
    }

    for (int j = 0; j < (int)ans[i].size(); j++) {
      if (j-1 >= 0) cout << " ";
      cout << ans[i][j]+1;
    }
    cout << endl;
  }

  return 0;
}