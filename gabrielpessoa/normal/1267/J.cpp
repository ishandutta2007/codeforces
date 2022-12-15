#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 2e6+5;

int q[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for(int i = 1; i<= n; i++) q[i] = 0;
    for(int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      q[x]++;
    }
    vector<int> v;
    for(int i = 1; i <= n; i++) {
      if(q[i]) v.push_back(q[i]);
    }
    sort(v.begin(), v.end());
    vector<int> poss;
    for(int s = v[0]+1; s >= 2; s--) {
      int n = v[0];
      if((s - n%s) % s <= (s+n-1)/s) poss.push_back(s);
    }
    for(int s : poss) {
      int ans = 0;
      for(int n : v) {
        if((s - n%s) % s <= (s+n-1)/s) ans += (s+n-1)/s;
        else {
          ans = -1;
          break;
        }
      }
      if(~ans) {
        cout << ans << '\n';
        break;
      }
    }
  }
}