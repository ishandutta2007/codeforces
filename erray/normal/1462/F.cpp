// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    vector<pair<int, int>> event;
    for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i];
      event.emplace_back(l[i], -i - 1);
      event.emplace_back(r[i], i);
    }

    sort(event.begin(), event.end());
    vector<int> ans(n);
    int begin = 0;
    int end = 0;

    for (auto[foo, x] : event) {
      if (x < 0) {
        ++begin;
        ans[-x - 1] += end;
      } else {
        ans[x] += n - begin;
        ++end;
      } 
    }

    cout << *min_element(ans.begin(), ans.end()) << '\n';
  }
}