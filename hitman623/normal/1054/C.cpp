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
int n,vis[1001],l[1001],r[1001],ans[1001];
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>l[i];
    }
    rep(i,1,n+1){
        cin>>r[i];
    }
    for(int val=n;val>0;val--){
        vi v;
        bool f=0;
        rep(i,1,n+1){
            if(vis[i]) continue;
            f=1;
            if(l[i]==0 and r[i]==0) v.pb(i),vis[i]=1;
        }
        if(f==1 and sz(v)==0){
            cout<<"NO"<<endl;
            return;
        }
        for(auto i:v){
            rep(j,1,i){
                if(vis[j]) continue;
                r[j]--;
                if(r[j]<0){
                    cout<<"NO"<<endl;
                    return;
                }
            }
            rep(j,i+1,n+1){
                if(vis[j]) continue;
                l[j]--;
                if(l[j]<0){
                    cout<<"NO"<<endl;
                    return;                    
                }
            }
        }
        for(auto i:v) ans[i]=val;
    }
    cout<<"YES"<<endl;
    rep(i,1,n+1) cout<<ans[i]<<" ";
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