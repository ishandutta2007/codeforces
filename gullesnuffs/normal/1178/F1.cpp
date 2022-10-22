#include <bits/stdc++.h>
#define MOD 998244353 
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

int highest[505][505];
int cinv[505];
ll dp[505][505];

int main(){
	ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    rep(i,0,m) {
        cin >> c[i];
        cinv[c[i]] = i;
    }
    rep(l,0,m) {
        highest[l][l] = 1e9;
        rep(r,l+1,m+1) {
            highest[l][r] = min(highest[l][r-1], c[r-1]);            
        }
    }
    rrep(l,m+1,0) {
        dp[l][l] = 1;
        rep(r,l+1,m+1) {
            int mid = cinv[highest[l][r]];
            ll L=0, R=0;
            rep(i,l,mid+1) {
                L += dp[l][i]*dp[i][mid];
                L %= MOD;
            }
            rep(i,mid,r) {
                R += dp[mid+1][i+1]*dp[i+1][r];
                R %= MOD;
            }
            dp[l][r] = (L*R) % MOD;
        }
    }
    cout << dp[0][m] << endl;
}