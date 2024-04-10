#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

int main() {
  io;
  int q; cin >> q;
  f0r(i, q) {
    ll n, sum = 0; cin >> n;
    
    while (n % 3 == 0) {
      n = n * 2 / 3;
      sum++;
    }
    while (n % 5 == 0) {
      n = n * 4 / 5;
      sum++;
    }
    while (n % 2 == 0) {
      n /= 2;
      sum++;
    }
    if (n == 1) cout << sum << endl;
    else cout << -1 << endl;
  }
}