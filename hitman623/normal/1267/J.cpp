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
int n,f[2000005];
void solve(){
    vi v;
    cin>>n;
    rep(i,1,n+1) f[i]=0;
    rep(i,0,n){
        int x;
        cin>>x;
        f[x]++;
    }
    rep(i,1,n+1){
        if(f[i]==0) continue;
        v.pb(f[i]);
    }
    sort(all(v));
    int ans=hell;
    rep(s,1,v[0]+2){
        int cnt=0,g=1;
        rep(i,0,sz(v)){
            cnt+=v[i]/s;
            if(v[i]%s and (v[i]%s+v[i]/s)>=s-1) cnt++;
            else if(v[i]%s){
                g=0;
                break;
            }
        }
        if(g) ans=min(ans,cnt);
    }
    cout<<ans<<endl;
}

signed main(){
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