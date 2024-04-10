#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    vector<int> a(4);
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
      cin >> a[i];
      sum += (a[i] & 1);
    }
    sort(a.begin(), a.begin() + 3);
    if ((a[0] != 0 && sum >= 3) || sum <= 1) cout << "Yes";
    else cout << "No";
    cout << '\n';
  }
}