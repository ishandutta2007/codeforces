#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
ll i, j;

ll n, q, Q, T, m, k, r, x;
multiset<int> a[1001], b[1001];
int d[1001][1001][2];

int main() {
  io;
  cin >> n >> m;

  f0r(i, n) {
    f0r(j, m) {
      cin >> d[i][j][0];
    }
  } f0r(i, n) {
    f0r(j, m) {
      cin >> d[i][j][1];
    }
  }
  bool f = 1;
  f0r(i, n+m-1) {
    int r = min(i, n-1), c = max(i+1-n, 0LL);
    while (r > -1 && c < m) {
      a[i].insert(d[r][c][0]); b[i].insert(d[r][c][1]);
      r--;
      c++;
    }
    if (a[i] != b[i]) f = 0;
  }
  cout << (f ? "YES" : "NO") << endl;
}