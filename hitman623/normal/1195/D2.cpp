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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,ans,pows[22];
vi v[11];
mi val;
int get(int x){
    if(val.count(x)) return val[x];
    string s=to_string(x);
    int w=0;
    rep(i,0,sz(s)){
        w=w*100+(s[i]-'0')*11;
        w=w%hell;
    }
    return val[x]=w;
}
void solve(){
    pows[0]=1;
    rep(i,1,22) pows[i]=10*pows[i-1];
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        v[sz(to_string(x))].pb(x);
    }
    rep(i,1,11){
        rep(j,i,11){
            if(i==j){
                for(auto k:v[i]){
                    ans=(ans+get(k)*sz(v[j]))%hell;
                }
            }
            else{
                for(auto k:v[i]){
                    ans=(ans+get(k)*sz(v[j]))%hell;
                }
                for(auto k:v[j]){
                    ans=(ans+(get(k%pows[i])+2*(k/pows[i])*pows[2*i])%hell*sz(v[i])%hell)%hell;
                }
            }
        }
    }
    cout<<ans<<endl;
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