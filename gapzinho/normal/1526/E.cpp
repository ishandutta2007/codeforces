#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 4e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;


int a[ms];
int fat[ms];
int ia[ms];

int fexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int comb(int a, int b) {
  int k = fat[b]*fat[a-b]%mod;
  // cout << a << ' ' << b << endl;
  // cout << fat[a] << ' ' << k << endl;
  return fat[a] * fexp(k, mod-2) % mod;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    fat[0] = 1;
    for(int i = 1; i < ms; i++) {
      fat[i] = fat[i-1]*i%mod;
    }
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      ia[a[i]] = i;
    }
    a[n] = -1;
    ia[n] = -1;
    int difAns = 0;
    int x, y;
    x = k, y = 1;
    int inversoes = 0;
    for(int i = 0; i < n-1; i++) {
      int p1 = a[i];
      int p2 = a[i+1];
      if(ia[p1+1] > ia[p2+1]) {
        y++;
        inversoes++;
      } else {
        x++; y++;
      }
    }
    // cout << inversoes << endl;
    if(y > x) cout << 0 << endl;
    else {
      cout << comb(x,y) << endl;
    }
    // cout << x << ' ' << y << endl;
    return 0;
}