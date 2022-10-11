#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
int i, j;
typedef long long ll;
typedef pair<int, int> pii;

ll n, q, Q, t, T, m, k;
string s;
int a[100001], b[100001];

int main() {
  io;
  cin >> n;
  f0r(i, n) cin >> a[i];
  sort(a, a+n);
  b[0] = a[n-2];
  b[1] = a[n-1];
  b[2] = a[n-3];
  if (b[1] >= b[0] + b[2]) {
    cout << "NO" << endl;
    exit(0);
  }
  f1r(i, 3, n) b[i] = a[n-i-1];
  cout << "YES" << endl;
  f0r(i, n) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << endl;
}