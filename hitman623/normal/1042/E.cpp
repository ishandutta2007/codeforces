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
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
int n,m,ans[1004][1004],r,c;
map<int,vii> v;
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        rep(j,0,m){
            int x;
            cin>>x;
            v[x].pb({i,j});
        }
    }
    cin>>r>>c;
    int cur=0,cnt=0,sumx=0,sqsumx=0,sumy=0,sqsumy=0;
    for(auto i:v){
        int den=expo(cnt,hell-2,hell);
        for(auto j:i.y){
            ans[j.x][j.y]=cur;
            int temp=j.x*j.x%hell;
            ans[j.x][j.y]=(ans[j.x][j.y]+(cnt*temp))%hell;
            ans[j.x][j.y]=(ans[j.x][j.y]+sqsumx)%hell;
            temp=2*j.x*sumx%hell;
            ans[j.x][j.y]=(ans[j.x][j.y]-temp+hell)%hell;
            temp=j.y*j.y%hell;
            ans[j.x][j.y]=(ans[j.x][j.y]+(cnt*temp))%hell;
            ans[j.x][j.y]=(ans[j.x][j.y]+sqsumy)%hell;
            temp=2*j.y*sumy%hell;
            ans[j.x][j.y]=(ans[j.x][j.y]-temp+hell)%hell;
            ans[j.x][j.y]=(ans[j.x][j.y]*den)%hell;
        }
        for(auto j:i.y){
            cnt++;
            cur+=ans[j.x][j.y];
            cur%=hell;
            sumx+=j.x;
            sumx%=hell;
            sumy+=j.y;
            sumy%=hell;
            sqsumx+=j.x*j.x;
            sqsumx%=hell;
            sqsumy+=j.y*j.y;
            sqsumy%=hell;
        }
    }
    cout<<ans[r-1][c-1]<<endl;
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