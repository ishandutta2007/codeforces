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
const int M=1000006;
int f[M],inv[M];
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void compute(){
    f[0]=1;
    rep(i,1,M){
        f[i]=(1LL*i*f[i-1])%hell;
    }
    inv[M-1]=expo(f[M-1],hell-2,hell);
    for(int i=M-2;i>=0;i--){
        inv[i]=(1LL*(i+1)*inv[i+1])%hell;
    }
}
int C(int n,int r){
    return (1LL*((1LL*f[n]*inv[r])%hell)*inv[n-r])%hell;
}
int n;
int get(vii v){
    int res=1;
    int cur=0,last=v[0].x;
    rep(i,0,sz(v)){
        if(v[i].x==last) cur++;
        else{
            res=res*f[cur]%hell;
            cur=1;
            last=v[i].x;
        }
    }
    return res*f[cur]%hell;
}
void solve(){
    vii v1,v2;
    cin>>n;
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v1.pb({x,y});
        v2.pb({y,x});
    }
    sort(all(v1));
    sort(all(v2));
    int ans=(get(v1)+get(v2))%hell;
    vi a,b;
    for(auto i:v1){
        a.pb(i.x),b.pb(i.y);
    }
    if(is_sorted(all(a)) and is_sorted(all(b))){
        int cur=1,res=1;
        rep(i,1,sz(v1)){
            if(v1[i-1]==v1[i]) cur++;
            else{
                res=res*f[cur]%hell;
                cur=1;
            }
        }
        res=res*f[cur]%hell;
        ans=(ans-res+hell)%hell;
    }
    cout<<(f[n]-ans+hell)%hell<<endl;
}

signed main(){
    compute();
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