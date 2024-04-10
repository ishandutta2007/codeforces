// August 11, 2019
// https://codeforces.com/contest/1200/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


long long ceil(long long n, long long d) {
  return (n + d - 1) / d;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  long long n, m;
  int q;
  cin >> n >> m >> q;
  long long g = __gcd(n, m);
  long long tn = n / g, tm = m / g;
  while (q--) {
    long long sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    long long ss = (sx == 1 ? ceil(sy, tn) : ceil(sy, tm));
    long long se = (ex == 1 ? ceil(ey, tn) : ceil(ey, tm));
    cout << (ss == se ? "YES" : "NO") << '\n';
  }


  return 0;
}