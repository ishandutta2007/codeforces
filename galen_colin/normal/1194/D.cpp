#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
ll i, j;

ll n, q, Q, T, m, k, r, x;
ll a, b, c, d;
string s, t, p;
ll mv = 0;
bool dp[1000001];

int main() {
  io;
  cin >> Q;
  f0r(q, Q) {
    cin >> n >> k;
    // ms(dp, 0);
    // f1r(i, 1, n) {
    //   dp[i] = !dp[i-1];
    //   if (i > 1) dp[i] |= !dp[i-2];
    //   if (i >= k) dp[i] |= !dp[i-k];
    // }
    // f0r(i, n) cout << i << " " << dp[i] << endl;
    bool ans;
    if (k % 3 == 0) {
      int r = n % (k+1);
      if (r == k) ans = 1;
      else ans = !!(r%3);
    } else ans = !!(n % 3);
    cout << (ans ? "Alice" : "Bob") << endl;
  }
}