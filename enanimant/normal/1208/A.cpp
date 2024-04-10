// August 25, 2019
// https://codeforces.com/contest/1208/problem/A

/*
I'm actually bad.
*/


#include <bits/stdc++.h>

using namespace std;


int f[3];

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
    cin >> f[0] >> f[1] >> n;
    f[2] = f[0] ^ f[1];
    cout << f[n % 3] << '\n';
    // int a, b, n;
    // cin >> a >> b >> n;
    // int ans = 0;
    // for (int bit = 0; bit <= 30; bit++) {
    //   int aa = a >> bit, bb = b >> bit;
    //   aa &= 1;
    //   bb &= 1;
    //   if (aa == 0 && bb == 0) {
    //     continue;
    //   }
    //   vector<int> v = {aa, bb, aa ^ bb};
    //   for (int i = 0; i < 3; i++) {
    //     if (v[i] == 0) {
    //       if (n % 3 != i) {
    //         ans |= 1 << bit;
    //       }
    //     }
    //   }
    // }
    // cout << ans << '\n';
  }


  return 0;
}