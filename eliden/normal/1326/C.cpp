#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    ll ans=1;
    int last=-1;
    const ll MOD= 998244353;
    ll sum=0;
    rep(i,0,n) {
        int x;
        cin>>x;
        --x;
        if(x>=n-k) {
            sum+=x+1;
            if(last!=-1) {
                ans=(ans*(i-last))%MOD;
            }
            last=i;
        }
    }
    cout<<sum<<" "<<ans<<endl;
}