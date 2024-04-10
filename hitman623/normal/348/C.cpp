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
#define B           316
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,q,big[100005],sum[100005],val[100005],extra[100005];
vi a[100005],s[100005];
mi affects[100005];
void solve(){
    cin>>n>>m>>q;
    rep(i,1,n+1) cin>>val[i];
    rep(i,1,m+1){
        int k;
        cin>>k;
        rep(j,0,k){
            int x;
            cin>>x;
            s[i].pb(x);
        }
        if(k>=B){
            big[i]=1;
            for(auto x:s[i]) a[x].pb(i),sum[i]+=val[x];
        }
    }
    rep(i,1,m+1){
        for(auto j:s[i]){
            for(auto k:a[j]){
                affects[i][k]++;
            }
        }
    }
    while(q--){
        char type;
        cin>>type;
        if(type=='?'){
            int k,ans=0;
            cin>>k;
            if(!big[k]){
                for(auto i:s[k]) ans+=val[i];
                for(auto i:affects[k]) ans+=i.y*extra[i.x];
            }
            else ans=sum[k];
            cout<<ans<<endl;
        }
        else{
            int k,x;
            cin>>k>>x;
            if(!big[k]) for(auto i:s[k]) val[i]+=x;
            else extra[k]+=x;
            for(auto i:affects[k]) sum[i.x]+=i.y*x;
        }
    }
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