#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 205;
const int shift = 20*200;
const int lim = 19*200;

int t[ms], f[ms];
int dif[ms], qnt[ms];
int dp[ms][ms*40];

main() {
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    while(x % 2 == 0) {
      t[i]++;
      x /= 2;
    }
    while(x % 5 == 0) {
      f[i]++;
      x /= 5;
    }
    qnt[i] = min(t[i], f[i]);
    dif[i] = t[i] - f[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = k; j >= 1; j--) {
      for(int k = -lim; k <= lim; k++) {
        int buff = qnt[i];
        if((k > 0) != (dif[i] > 0)) {
          buff += min(abs(k), abs(dif[i]));
        }
        dp[j][k+shift] = max(dp[j][k+shift], dp[j-1][max(min(lim, k + dif[i]), -lim)+shift] + buff);
        //cout << i << ' ' << j << ' ' << k << " = " << dp[j][k+shift] << endl;
      }
    }
  }
  cout << dp[k][shift] << '\n';
  
}