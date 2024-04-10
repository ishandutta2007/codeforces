#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j;
typedef long long ll;

ll n, m, p, q, Q, k, r;
ll a[100001];
ll ans = 0, page = 0, disp = 0;

int main() {
  io;
  cin >> n >> m >> k;
  f0r(i, m) { cin >> a[i]; a[i]--; }
  sort(a, a+m);
  int pt = 0;
  while (pt < m && page * k + disp < n) {
    int t = 0;
    while (pt < m && a[pt] >= page * k + disp && a[pt] < (page + 1) * k + disp) {
      pt++;
      t++;
    }
    disp += t;
    if (t > 0) {
      ans++;
    } else {
      t = page;
      page = (a[pt] - disp) / k;
    }
  }
  cout << ans << endl;
}