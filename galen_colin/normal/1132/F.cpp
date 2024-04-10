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

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

ll i, j;
const ll mod = 1e9 + 7;
 
ll n, q, Q, T, m, k, r, x, y, z, g;
string s;
int dp[501][501];
int cnt[501];

int main() {
  io;
  cin >> n >> s;
  f0r(i, n) f0r(j, n) dp[i][j] = 0;
  f0r(i, n) {
    if (!i || cnt[i-1] == 1) {
      int pt = i+1;
      while (pt < n && s[pt] == s[i]) pt++;
      cnt[i] = pt - i;
    } else cnt[i] = cnt[i-1] - 1;
  }
  f0r(i, n) {
    f1r(j, 0, n-i) {
      int l = j, r = j+i;
      if (r - l < cnt[l]) dp[l][r] = 1;
      else {
        dp[l][r] = 1 + dp[l+1][r];
        f1r(k, l+1, r+1) if (s[l] == s[k]) dp[l][r] = min(dp[l][r], dp[l+1][k] + dp[k+1][r]);
      }
      // cout << l << " " << r << " " << dp[l][r] << endl;
    }
  }
  cout << dp[0][n-1] << endl;
}