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
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,dx,dy,p[1000005],vis[1000006],ans,in;
void solve(){
    cin>>n>>m>>dx>>dy;
    int cur=0;
    rep(i,0,n){
        p[cur]=i;
        cur=(cur+dx)%n;
    }
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        int g=(y-1LL*p[x]*dy)%n;
        g=(g+n)%n;
        vis[g]++;
    }
    rep(i,0,n){
        if(ans<vis[i]){
            ans=vis[i];
            in=i;
        }
    }
    cout<<0<<" "<<in<<endl;
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