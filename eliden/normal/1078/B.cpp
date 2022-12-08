#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    int m = 101;
    vector<int> f(m);
    rep(i,0,n) ++f[a[i]];
    int distinct = 0;
    rep(i,0,m) if(f[i]) ++distinct;
    int ans = n;
    if(distinct>2) {
        vector<vector<int>> pos(n*m,vector<int>(n));
        pos[0][0]=1;
        rep(i,0,m) if(f[i]) {
            for(int j=n*m-1;j>=i;--j) {
                rep(k,1,n) {
                    for(int r=1;r<=f[i] && j-r*i>=0 && r<=k;++r) {
                        pos[j][k]=min(2,pos[j][k]+pos[j-r*i][k-r]);
                    }
                }
            }
        }
        ans = 0;
        rep(i,0,m) {
            rep(j,1,f[i]+1) {
                // debug(i);
                // debug(j);
                // debug(pos[i*j][j]);
                if(pos[i*j][j]==1) ans=max(ans,j);
            }
        }
    }
    cout << ans <<endl;
    
}