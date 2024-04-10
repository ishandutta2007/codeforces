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
int n,f[10];
void solve(){
    memset(f,1,sizeof f);
    f[0]=0;
    cin>>n;
    rep(i,0,n){
        int c,d=0;
        string s;
        cin>>c>>s;
        for(auto j:s){
            if(j=='A') d|=1;
            if(j=='B') d|=2;
            if(j=='C') d|=4;
        }
        f[d]=min(f[d],c);
    }
    int ans=LLONG_MAX;
    rep(i,0,8){
        rep(j,0,8){
            rep(k,0,8){
                if((i|j|k)==7) ans=min(ans,f[i]+f[j]+f[k]);
            }
        }
    }
    if(ans<hell) cout<<ans<<endl;
    else cout<<-1<<endl;
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