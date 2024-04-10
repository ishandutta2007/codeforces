// April 10, 2020
// https://codeforces.com/contest/1334/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

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
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second;
    }
    long long health = 0, dmg = 0, mn = 1e18;
    for (int i = 0; i < n; i++) {
      v[i].second = min(v[i].second, v[(i + 1) % n].first);
      health += v[i].first;
      dmg += v[i].second;
      mn = min(mn, v[i].second);
    }
    cout << health - dmg + mn << '\n';
    //
    // if (n == 1) {
    //   cout << v[0].first << '\n';
    //   continue;
    // }
    // bool all = true;
    // vector<int> fail;
    // for (int i = 0; i < n; i++) {
    //   int j = (i + 1) % n;
    //   if (v[i].second < v[j].first) {
    //     fail.push_back(i);
    //     all = false;
    //   }
    // }
    // if (all) {
    //   cout << mn << '\n';
    //   continue;
    // }
    // long long ans = 0;
    // long long min_dmg = 1e18;
    // for (int x : fail) {
    //   ans -= v[x].second;
    //   ans += v[(x + 1) % n].first;
    //   min_dmg = min(min_dmg, v[x].second);
    // }
    // ans += min_dmg;
    // cout << ans << '\n';
  }


  return 0;
}