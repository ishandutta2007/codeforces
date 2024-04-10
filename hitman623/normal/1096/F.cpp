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
int n,p[200005];
int bit[200005];
void update(int x,int y=1){
    for(;x<=200001;x+=x&(-x)) bit[x]+=y;
}
int query(int x){
    int res=0;
    for(;x>0;x-=x&(-x)) res+=bit[x];
    return res;
}
int f(int x){
    int res=x*(x-1)/2%hell;
    return res*(hell+1)/2%hell;
}
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
vi v;
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>p[i];
        if(p[i]>0) v.pb(p[i]);
    }
    int cnt=0;
    for(int i=sz(v)-1;i>=0;i--){
        cnt+=query(v[i]-1);
        cnt%=hell;
        update(v[i]);
    }
    int ans=cnt,left=0,right=n-sz(v),d=expo(left+right,hell-2,hell);
    rep(i,1,n+1){
        if(p[i]==-1) left++,right--;
        else{
            int small=p[i]-1-query(p[i]-1);
            int big=n-p[i]-(sz(v)-query(p[i]));
            ans=(ans+small*right%hell*d%hell)%hell;
            ans=(ans+big*left%hell*d%hell)%hell;
        }
    }
    ans=(ans+f(n-sz(v)))%hell;
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