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
vi divs[200001];
void process_seive(int n){
    rep(i,1,n+1){
        for(int j=i;j<=n;j+=i){
            divs[j].pb(i);
        }
    }
}
int n,p[200005],c[200005],vis[200005];
void solve(){
    int ans=hell;
    cin>>n;
    rep(i,1,n+1) vis[i]=0;
    rep(i,1,n+1) cin>>p[i];
    rep(i,1,n+1) cin>>c[i];
    rep(i,1,n+1){
        if(vis[i]) continue;
        vi v;
        int cur=i;
        while(vis[cur]==0){
            v.pb(cur);
            vis[cur]=1;
            cur=p[cur];
        }
        int d=sz(v);
        for(auto k:divs[d]){
            int g=0;
            rep(l,0,k){
                int cur=l,b=c[v[l]],f=1;
                rep(w,0,d/k){
                    if(c[v[cur]]!=b){
                        f=0;
                        break;
                    }
                    cur=cur+k;
                }
                if(f) g=1;
            }
            if(g){
                ans=min(ans,k);
                break;
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    process_seive(200000);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}