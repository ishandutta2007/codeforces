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

ll n, m;
ll a[200002], t = 0, ans = 0;
multiset<ll> s, os;

// int main() {
//   io;
//   cin >> n >> m;
//   f0r(i, n) cin >> a[i];
//   f0r(i, n) {
//     t += a[i];
//     while (t > m) {
//       t -= *(--s.end());
//       os.insert(*(--s.end()));
//       s.erase(--s.end());
//       ans++;
//     }
//     while (os.size() && t + *(os.begin()) <= m) {
//       t += *(os.begin());
//       s.insert(*(os.begin()));
//       os.erase(os.begin());
//       ans--;
//     }
//     s.insert(a[i]);
//     cout << ans << endl;
//   }
// }

ll oa[200002];

int main() {
  io;
  cin >> n >> m;
  f0r(i, n) cin >> a[i];
  f0r(i, n) {
    t += a[i];
    int ot = t;
    f0r(j, i) oa[j] = a[j];
    sort(oa, oa + i);
    int pt = i - 1;
    while (ot > m) {
      ot -= oa[pt];
      pt--;
    }
    cout << (i - pt - 1) << endl;
  }
}