#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 
 
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
ll i, j;
const ll mod = 1e9 + 7;
 
ll n, q, Q, T, m, k, r, x, y, z, g;
ll dp[100073];
vector<int> divs[100003];
int a[100003];
/* highest number of divisors: 240 */
 
int main() {
  io;
  cin >> n;
  f0r(i, n) cin >> a[i];
  f0r(i, n) {
    int x = ceil(sqrt(a[i]));
    f1r(j, 1, x+1) {
      if (a[i] % j == 0) {
        divs[i].pb(j);
        divs[i].pb(a[i] / j);
      }
    }
  }
 
  ms(dp, 0);
  f0r(i, n) {
    sort(divs[i].begin(), divs[i].end());
    divs[i].erase(unique(divs[i].begin(), divs[i].end()), divs[i].end());
    reverse(divs[i].begin(), divs[i].end());
    for (int j: divs[i]) {
      if (j > n+3) continue;
      dp[j] = (dp[j-1] + dp[j]) % mod;
    }
    dp[1]++;
  }
  ll sum = 0;
  f0r(i, n+3) sum = (sum + dp[i]) % mod;
  cout << sum%mod << endl;
}