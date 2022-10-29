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
int n;
mi f;
vi v;
void solve(){
    f.clear();
    v.clear();
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        f[x]++;
    }
    pii ans={hell,1},res;
    for(auto i:f){
        if(i.y>=4){
            cout<<i.x<<" "<<i.x<<" "<<i.x<<" "<<i.x<<endl;
            return;
        }
        if(i.y>=2){
            v.pb(i.x);
        }
    }
    rep(i,1,sz(v)){
        int l=v[i],b=v[i-1];
        if((l*l+b*b)*ans.y<l*b*ans.x){
            ans={l*l+b*b,l*b};
            res={l,b};
        }
    }
    cout<<res.x<<" "<<res.x<<" "<<res.y<<" "<<res.y<<endl;
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