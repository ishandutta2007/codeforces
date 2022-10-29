#include <bits/stdc++.h>

#define ll          long long
#define pb          emplace_back
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
vi v1,v2,v;
int vis[100005];
int sol(int a,int b){
    memset(vis,0,sizeof vis);
    v1.clear();
    v2.clear();
    for(int i=sz(v)-1;i>=0;i--){
        if(a>=v[i]) a-=v[i],v1.pb(v[i]),vis[i]=1;
    }
    rep(i,0,sz(v)){
        if(vis[i]==0 and b-v[i]>=0){
            b-=v[i];
            v2.pb(v[i]);
        }
    }
    return sz(v1)+sz(v2);
}
void solve(){
    int a,b;
    ll s=0;
    cin>>a>>b;
    rep(i,1,a+b+1){
        s+=i;
        if(s<=a+b) v.pb(i);
        else break;
    }
    if(sol(a,b)>sol(b,a)){
        sol(a,b);
    }
    else swap(v1,v2);
    cout<<sz(v1)<<endl;
    for(auto i:v1) cout<<i<<" ";
        cout<<endl;       
    cout<<sz(v2)<<endl;
    for(auto i:v2) cout<<i<<" ";
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