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
int n,vis[200005],used[200005];
vii edges;
void solve(){
    cin>>n;
    used[n]=1;
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        if(b!=n){
            cout<<"NO"<<endl;
            return;
        }
        vis[a]++;
        used[a]=1;
    }
    int cur=n;
    for(int i=n-1;i>=1;i--){
        int g=i;
        if(vis[i]==0) continue;
        vis[i]--;
        while(vis[i]){
            while(cur and used[cur]) cur--;
            if(cur>g or cur==0){
                cout<<"NO"<<endl;
                return;
            }
            used[cur]=1;
            edges.pb({g,cur});
            g=cur;
            vis[i]--;
        }
        edges.pb({g,n});
    }
    cout<<"YES"<<endl;
    for(auto i:edges) cout<<i.x<<" "<<i.y<<endl;
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