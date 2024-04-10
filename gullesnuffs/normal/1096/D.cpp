#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll dp[100005][10];

int main(){
	ios::sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i,0,n)
        cin >> a[i];
    string hard="hard";
    rep(i,1,n+1) {
        rep(j,0,5) {
            dp[i][j] = dp[i-1][j] + a[i-1];
        }
        rep(j,0,4) {
            if (s[i-1] != hard[j]) {
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
            dp[i][j+1] = min(dp[i][j+1], dp[i-1][j]);
        }
    }
    ll ans = 1e18;
    rep(j,0,4)
        ans = min(ans, dp[n][j]);
    cout << ans << endl;
}