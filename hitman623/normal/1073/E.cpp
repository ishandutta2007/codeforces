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
string l,r;
int k,n,p[30];
pii dp[20][2][2][2][1<<10];
pii sol(int in,int fl,int fr,int f,int mask){
    if(in==sz(r)){
        return {__builtin_popcount(mask)<=k,0};
    }
    if(dp[in][fl][fr][f][mask]!=make_pair(-1LL,-1LL)) return dp[in][fl][fr][f][mask];
    pii ans={0,0};
    rep(i,!f,10){
        if(fl==0 and fr==0){
            if(i<l[in]-'0') continue;
            if(i>r[in]-'0') continue;
            int g=p[n-in-1]*i%hell;
            pii h=sol(in+1,i>l[in]-'0',i<r[in]-'0',1,mask|(1<<i));
            ans.x=(ans.x+h.x)%hell;
            ans.y=(ans.y+h.y+h.x*g)%hell;
        }
        else if(fl==0){
            if(i<l[in]-'0') continue;
            int g=p[n-in-1]*i%hell;
            pii h=sol(in+1,i>l[in]-'0',1,1,mask|(1<<i));
            ans.x=(ans.x+h.x)%hell;
            ans.y=(ans.y+h.y+h.x*g)%hell;
        }
        else if(fr==0){
            if(i>r[in]-'0') continue;
            int g=p[n-in-1]*i%hell;
            pii h=sol(in+1,1,i<r[in]-'0',1,mask|(1<<i));
            ans.x=(ans.x+h.x)%hell;
            ans.y=(ans.y+h.y+h.x*g)%hell;
        }
        else{
            int g=p[n-in-1]*i%hell;
            pii h=sol(in+1,1,1,1,mask|(1<<i));
            ans.x=(ans.x+h.x)%hell;
            ans.y=(ans.y+h.y+h.x*g)%hell;
        }
    }
    if(f==0 and l[in]-'0'==0){
        pii h=sol(in+1,fl,fr|(r[in]>'0'),0,mask);
        ans.x=(ans.x+h.x)%hell;
        ans.y=(ans.y+h.y)%hell;
    }
    return dp[in][fl][fr][f][mask]=ans;
}
void solve(){
    memset(dp,-1,sizeof dp);
    cin>>l>>r>>k;
    reverse(all(l));
    while(sz(l)!=sz(r)) l+='0';
    reverse(all(l));
    n=sz(r);
    p[0]=1;
    rep(i,1,30) p[i]=(p[i-1]*10)%hell;
    cout<<sol(0,0,0,0,0).y<<endl;
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