#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 2e6+5;

int fat[20];

int solve(vector<int> v, int n) {
  int cur = v[0];
  int ans = 1;
  for(int i = 1; i <= n; i++) {
    cur += v[i];
    ans *= cur;
    cur--;
  }
  for(int j : v) {
    ans /= fat[j];
  }
  return ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  fat[0] = 1;
  for(int i = 1; i < 20; i++) {
    fat[i] = fat[i-1] * i;
  }
  while(t--) {
    int x;
    cin >> x;
    vector<int> v(20);
    int q = 0;
    for(int i = 2; x; i++) {
      v[x%i]++;
      x /= i;
      q++;
    }
    int ans = solve(v, q);
    if(v[0]) {
      v[0]--;
      ans -= solve(v, q-1);
    }
    cout << ans-1 << '\n';
  }
}