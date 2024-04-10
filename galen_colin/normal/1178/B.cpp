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
const ll mod = 1000000007;

ll n, q, Q, T, m, k, r, x, y, z, g;
string s;
ll dp[2];
ll ans = 0;

int main() {
  io;
  cin >> s;
  dp[0] = dp[1] = 0;
  int pt = 0;
  f1r(i, 1, s.length()) {
    if (s[i] == 'v' && s[i-1] == 'v') {
      dp[0]++;
      ans += dp[1];
    }
    else if (s[i] == 'o') dp[1]+= dp[0]; 
  }
  cout << ans << endl;
}