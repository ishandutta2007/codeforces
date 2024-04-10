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
int n,m,a[100005];
vi pos,neg;
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        int u,v,d;
        cin>>u>>v>>d;
        a[u]-=d;
        a[v]+=d;
    }
    rep(i,1,n+1){
        if(a[i]>0) pos.pb(i);
        else if(a[i]<0) neg.pb(i);
        a[i]=abs(a[i]);
    }
    vector<pair<pii,int>> v;
    int j=0;
    rep(i,0,sz(pos)){
        if(a[neg[j]]<=a[pos[i]]){
            v.pb({{neg[j],pos[i]},a[neg[j]]});
            a[pos[i]]-=a[neg[j]];
            a[neg[j]]=0;
            j++;
        }
        else{
            v.pb({{neg[j],pos[i]},a[pos[i]]});
            a[neg[j]]-=a[pos[i]];
            a[pos[i]]=0;
        }
        if(a[pos[i]]!=0) i--;
    }
    cout<<sz(v)<<endl;
    for(auto i:v) cout<<i.x.x<<" "<<i.x.y<<" "<<i.y<<endl;
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