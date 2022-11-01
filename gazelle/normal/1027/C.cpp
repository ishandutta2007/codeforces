#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)

signed main () {
    cin.tie(0);
    ios::sync_with_stdio(false);
  cout << setprecision(10);

  int t; cin >> t;
  int n;

  while(t!=0) {
    cin >> n;
    map<int, int> a;
    int tmp;
    REP(i, n) {
      cin >> tmp;
      a[tmp]++;
    }

    vector<int>b;
    for(auto i = a.begin(); i != a.end(); i++) {
      if(i->second >= 4) {
        b.pb(i->first);
        b.pb(i->first);
      } else if(i->second >= 2) b.pb(i->first);
    }

    sort(b.begin(), b.end());

    int sum = b[0] + b[1];
    pair<int, int> ans;
    double mi = 1000000000;
    double l, r;
    REP(i, b.size()-1) {
      l = (double) b[i];
      r = (double) b[i+1];
      if(mi > (2 * (l + r)) * (2 * (l + r)) / (l * r)) {
        mi = (2 * (l + r)) * (2 * (l + r)) / (l * r);
        ans.first = b[i];
        ans.second = b[i+1];
      }
    }

    cout << ans.first << " "
         << ans.first << " "
         << ans.second << " "
         << ans.second << endl;
    
    t--;
  }
}