#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
int i, j, k;
typedef long long ll;

int n, a[100001];

int main() {
  cin >> n;
  f0r(i, n) cin >> a[i];
  int f = a[0] % 2 + 1;
  f0r(i, n - 1) {
    if (a[i + 1] % 2 + 1 != f) f = 0;
  }
  if(!f) sort(a, a+n);
  f0r(i, n) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}