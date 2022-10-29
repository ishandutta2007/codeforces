#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,p[200005];
string a,b;
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void solve(){
    int ans=0;
    cin>>n>>m>>a>>b;
    reverse(all(a));
    reverse(all(b));
    while(n<m) a+='0',n++;
    while(m<n) b+='0',m++;
    reverse(all(a));
    reverse(all(b));
    rep(i,0,m){
        p[i]=b[i]=='1';
        if(i) p[i]+=p[i-1];
    }
    rep(i,0,n){
        if(a[i]=='1'){
            ans=(ans+p[i]*expo(2,n-i-1,hell))%hell;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}