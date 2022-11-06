#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long dopuble

 typedef pair<int, int> ii;
typedef long long ll;

const int ms = 5e4+5, mb = (1<<20);
const int mod = 998244353;

int ifat;
int d[ms][23];

int fexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int n, m;
    cin >> n >> m;
    int fat = 1;
    for(int i = 2; i <= n; i++) fat = (fat*i)%mod;
    ifat = fexp(fat, mod-2);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            d[j][x]++;
            // cout << d[j][x] <<  " de " << j << ' ' << x << endl;
        }
    }
    // cout << d[2][2] << " helppp" << endl;
    int ans = 0;
    for(int i = 0; i < m; i++) {
        int poss = 1;
        int carasInclusos = d[i][n+1];
        for(int j = n; j > 0; j--) {
            // cout << i << " " << j << " = " << carasInclusos << endl;
            // cout << d[i][j] << endl;
            if(carasInclusos == 0) {
                poss = 0;
                break;
            }
            poss = (poss * carasInclusos) % mod;
            carasInclusos+=d[i][j] - 1;
        }
        // cout << i << " =  " << poss << endl;
        poss = (fat + mod - poss)%mod;
        // cout << poss << endl;
        ans = (ans + poss * ifat) % mod;
    }
    cout << ans << endl;
    return 0;
}