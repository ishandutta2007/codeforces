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


  long long x, s;
  cin >> x >> s;
  if (s == 0 && x == 0) {
    cout << "0\n";
    return 0;
  }
  if (s < x) {
    cout << "-1\n";
    return 0;
  }
  vector<long long> ans(1, x);
  long long t = s - x;
  if (t & 1) {
    cout << "-1\n";
    return 0;
  }
  for (int b = 62; b >= 1; b--) {
    long long d = (1LL << b);
    if (t & d) {
      int rem = 2;
      for (int i = 0; i < ans.size() && rem > 0; i++) {
        if ((ans[i] & (1LL << (b - 1))) == 0) {
          ans[i] |= (1LL << (b - 1));
          rem--;
        }
      }
      while (rem--) {
        ans.push_back(1LL << (b - 1));
      }
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << ans[i];
  }
  cout << '\n';


  return 0;
}