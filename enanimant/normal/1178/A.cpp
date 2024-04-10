// July 20, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector< pair<int, int> > a(n);
  int seats = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    seats += a[i].first;
    a[i].second = i;
  }
  sort(a.begin() + 1, a.end());
  int t = a[0].first;
  vector<int> ans;
  ans.push_back(0);
  for (int i = 1; i < n; i++) {
    if (a[0].first >= 2 * a[i].first) {
      t += a[i].first;
      ans.push_back(a[i].second);
    }
  }
  if (t * 2 <= seats) {
    cout << "0\n";
  } else {
    cout << ans.size() << '\n';
    for (int i : ans) {
      cout << i + 1 << ' ';
    }
    cout << '\n';
  }


  return 0;
}