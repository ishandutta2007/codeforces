#include <bits/stdc++.h>

#define ll          long long
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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,vis[1001];
vi v[1001];
int query(int l,int r){
    vi ids;
    rep(i,l,r+1){
        for(auto j:v[i]){
            ids.pb(j);
        }
    }
    cout<<"? "<<sz(ids)<<" ";
    for(auto i:ids) cout<<i<<" ";
    cout<<endl;
    cin>>l;
    return l;
}
void solve(){
    cin>>n>>k;
    rep(i,0,n+1){
        v[i].clear();
        vis[i]=0;
    }
    rep(i,0,k){
        int w;
        cin>>w;
        rep(j,0,w){
            int x;
            cin>>x;
            v[i].pb(x);
        }
    }
    int MX;
    cout<<"? "<<n<<" ";
    rep(i,1,n+1) cout<<i<<" ";
    cout<<endl;
    cin>>MX;
    int lo=0,hi=k-1;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(query(lo,mid)==MX){
            hi=mid;
        }
        else lo=mid+1;
    }
    if(lo!=hi){
        if(query(lo,lo)==MX);
        else lo=hi;
    }
    rep(i,1,n+1) vis[i]=1;
    for(auto i:v[lo]) vis[i]=0;
    cout<<"? "<<n-sz(v[lo])<<" ";
    rep(i,1,n+1){
        if(vis[i]) cout<<i<<" ";
    }
    cout<<endl;
    int w;
    cin>>w;
    cout<<"! ";
    rep(i,0,k){
        if(i==lo) cout<<w<<" ";
        else cout<<MX<<" ";
    }
    cout<<endl;
    string res;
    cin>>res;
    assert(res=="Correct");
}

signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}