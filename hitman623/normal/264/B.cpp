#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          unordered_map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[100005],res;
mi b;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        vi p;
        int ans=0;
        for(int j=2;j*j<=a[i];++j){
            if(a[i]%j==0){
                p.pb(j);
                while(a[i]%j==0){
                    a[i]/=j;
                }
            }
        }
        if(a[i]>1){
            p.pb(a[i]);
        }
        rep(j,0,sz(p)){
            ans=max(ans,1+b[p[j]]);
        }
        rep(j,0,sz(p)){
            b[p[j]]=max(b[p[j]],ans);
        }
    }
    for(auto i:b){
        res=max(res,i.y);
    }
    cout<<max(res,1)<<endl;
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