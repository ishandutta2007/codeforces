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

string s;
vector<int> a;
ll cache[105][105];

void rec(int l, int r) {
    if (s[r-1] != s[l]) {
        cache[l][r] = -1e18;
        return;
    }
    if (r == l+1) {
        cache[l][r] = a[1];
        return;
    }
    char type = s[l];
    vector<vector<ll>> dp(r+1, vector<ll>(r-l+1, -1e18));
    dp[l+1][2] = 0;
    rep(i,l+1,r-1) {
        rep(j,2,r-l+1) {
            if (dp[i][j] < 0)
                continue;
            if (s[i] == type) {
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
            }
            rep(k,i+1,r) {
                dp[k][j] = max(dp[k][j], dp[i][j]+cache[i][k]);
            }
        }
    }
    cache[l][r] = -1e18;
    rep(i,2,r-l+1) {
        cache[l][r] = max(cache[l][r], dp[r-1][i]+a[i]);
    }
}

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    cin >> s;
    a.resize(n+1);
    rep(i,1,n+1)
        cin >> a[i];
    rrep(l,n,0)
        rep(r,l+1,n+1) {
            rec(l, r);
            /*if (cache[l][r] > 0) {
                cerr << l << " " << r;
                cerr << " " << cache[l][r] << endl;
            }*/
        }
    vector<ll> dp(n+1);
    dp[0] = 0;
    rep(i,0,n) {
        rep(k,i+1,n+1) {
            dp[k] = max(dp[k], dp[i]+cache[i][k]);
        }
    }
    cout << dp[n] << endl;
}