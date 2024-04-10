#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--){
    int n;
    cin >> n;
    int x = (int) 1e8;
    for (int i = 1; i <= n; i++) {
      cout << i + x << " ";
    }
    cout << "\n";
  }

  return 0;
}