// March 14, 2020
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


  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    set<int> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    cout << s.size() << '\n';
  }


  return 0;
}