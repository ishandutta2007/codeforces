#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;
const ll mod = 1e9 + 7;

ll n, a[3], d, ans = 0;

int main() {
  io;
  cin >> a[0] >> a[1] >> a[2] >> d;
  sort(a, a+3);

  //together
  if (a[1] - a[0] >= d) {
    ans = max(d - (a[2] - a[1]), 0LL);
  } else if (a[2] - a[1] >= d) {
    ans = max(d - (a[1] - a[0]), 0LL);
  } else if (a[2] - a[0] >= 2*d) {
    int mid = (a[2] - a[0]) / 2;
    ans = min(abs(a[1] - (a[0] + d)), abs(a[1] - (a[2] - d)));
  } else {
    ll opt1 = a[2] - 2*d, opt2 = a[2] - d;
    ans = abs(opt1 - a[0]) + abs(opt2 - a[1]);
    ll opt3 = a[0] + 2*d, opt4 = a[0] + d;
    ans = min(ans, abs(opt3 - a[2]) + abs(opt4 - a[1]));
    ll opt5 = a[1] + d, opt6 = a[1] - d;
    ans = min(ans, abs(opt5 - a[2]) + abs(opt6 - a[0]));
  }
  cout << ans << endl;
}