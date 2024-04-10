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
int m,a,b,cur,vis[200005],f[200005],ans,mx;
vi v;
void solve(){
    cin>>m>>a>>b;
    while(!vis[cur]){
        vis[cur]=1;
        v.pb(cur);
        if(cur>=b) cur-=b;
        else cur=cur+a;
        mx=max(mx,cur);
    }
    mx++;
    rep(i,1,sz(v)) v[i]=max(v[i-1],v[i]);
    rep(i,0,sz(v)) f[v[i]]++;
    rep(i,1,mx) f[i]+=f[i-1];
    if(m>=mx-1){
        rep(i,0,mx) ans+=f[i];
        int g=__gcd(a,b);
        int res=m*(m+1)/2-mx*(mx-1)/2+g*(m-mx+1);
        rep(i,0,g) res-=((m-i)/g-(mx-1-i)/g)*i;
        ans+=res/g;
    }
    else rep(i,0,m+1) ans+=f[i];
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