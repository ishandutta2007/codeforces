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

int main(){
	ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    vector<set<int>> inds(n+1);
    rep(i,0,m) {
        cin >> c[i];
        if (i && c[i] == c[i-1]) {
            c.pop_back();
            --i;
            --m;
            continue;
        }
        inds[c[i]].insert(i);
    }
    if (sz(c) > 1050) {
        cout << 0 << endl;
        return 0;
    }
    auto dp = vector<vector<ll>>(sz(c)+1, vector<ll>(sz(c)+1));
    auto highest = vector<vector<int>>(sz(c)+1, vector<int>(sz(c)+1));
    rep(l,0,m) {
        highest[l][l] = 1e9;
        rep(r,l+1,m+1) {
            highest[l][r] = min(highest[l][r-1], c[r-1]);            
        }
    }
    rrep(l,m+1,0) {
        dp[l][l] = 1;
        rep(r,l+1,m+1) {
            int C = highest[l][r];
            if (*inds[C].begin() < l) {
                dp[l][r] = 0;
                continue;
            }
            if (*inds[C].rbegin() >= r) {
                dp[l][r] = 0;
                continue;
            }
            if (*inds[C].begin() == l && *inds[C].rbegin() == r-1) {
                dp[l][r] = 1;
                for (auto it = inds[C].begin(); it != inds[C].end(); ++it) {
                    auto it2 = it;
                    ++it2;
                    if (it2 == inds[C].end())
                        break;
                    dp[l][r] *= dp[*it+1][*it2];
                    dp[l][r] %= MOD;
                }
                continue;
            }
            int L0 = *inds[C].begin();
            int R0 = *inds[C].rbegin();
            ll L=0, R=0;
            rep(i,l,L0+1) {
                L += dp[l][i]*dp[i][L0];
                L %= MOD;
            }
            rep(i,R0,r) {
                R += dp[R0+1][i+1]*dp[i+1][r];
                R %= MOD;
            }
            dp[l][r] = (L*R) % MOD;
            dp[l][r] *= dp[L0][R0+1];
            dp[l][r] %= MOD;
        }
    }
    cout << dp[0][m] << endl;
}