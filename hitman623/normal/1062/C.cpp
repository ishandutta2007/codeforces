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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,q,p[100005];
string s;
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
    cin>>n>>q;
    cin>>s;
    p[0]=s[0]=='1';
    rep(i,1,n){
        p[i]=(s[i]=='1')+p[i-1];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int x=p[r]-(l?p[l-1]:0);
        int y=r-l+1-x;
        int ans=(expo(2,x,hell)-1+hell)%hell;
        ans=(ans*expo(2,y,hell))%hell;
        cout<<ans<<endl;
    }
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