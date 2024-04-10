// August 16, 2020
// 

/*

*/


#include <bits/stdc++.h>

using namespace std;


void flip(vector<int>& a) {
  int mx = *max_element(a.begin(), a.end());
  for (int i = 0; i < (int) a.size(); i++) {
    a[i] = mx - a[i];
  }
}

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
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    flip(a);
    k--;
    k %= 2;
    if (k == 1) {
      flip(a);
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << a[i];
    }
    cout << '\n';
  }
  
  
  return 0;
}