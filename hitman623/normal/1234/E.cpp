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
int n,m,x[200005];
mi v;
void add(int i){
    v[1]+=x[i];
    v[x[i]]-=x[i];
    v[x[i]]+=1;
    v[x[i]+1]-=1;
    v[x[i]+1]+=x[i]+1;
    v[n+1]-=x[i]+1;
}
void rem(int i){
    v[1]-=x[i];
    v[x[i]]+=x[i];
    v[x[i]]-=1;
    v[x[i]+1]+=1;
    v[x[i]+1]-=x[i]+1;
    v[n+1]+=x[i]+1;
}
int ans[200005];
void solve(){
    cin>>n>>m;
    rep(i,0,m) cin>>x[i];
    rep(i,0,m-1){
        v.clear();
        add(i);
        rem(i+1);
        vii vv(all(v));
        int cur=0;
        rep(j,0,sz(vv)-1){
            cur+=vv[j].y;
            ans[vv[j].x]+=abs(cur);
            ans[vv[j+1].x]-=abs(cur);
        }
    }
    rep(i,1,n+1){
        ans[i]+=ans[i-1];
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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