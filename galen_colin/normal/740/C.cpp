#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
int i, j, k;
typedef long long ll;

int main() {
  int n, m; cin >> n >> m;
  int an = 1000000000;
  f0r(i, m) {
    int a, b; cin >> a >> b;
    an = min(an, b - a + 1);
  }
  cout << an << endl;
  f0r(i, n) {
    if (i) cout << " ";
    cout << i % an;
  }
  cout << endl;
}