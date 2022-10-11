#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
int i, j, k;
typedef long long ll;

int main() {
  int q; cin >> q;
  f0r(i, q) {
    int l, r, d; cin >> l >> r >> d;
    if (d < l) cout << d;
    else if (r % d == 0) cout << r + d;
    else cout << (r / d + 1) * d;
    cout << endl;
  }
}