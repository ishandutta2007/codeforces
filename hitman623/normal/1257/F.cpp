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
int n,a[101],ans=hell;
map<vi,int> mp;
vi f;
void solve(){
    cin>>n;
    f.resize(n);
    rep(i,0,n) cin>>a[i];
    rep(i,0,1<<15){
        rep(j,0,n) f[j]=__builtin_popcount((a[j]>>15)^i)-(j?f[0]:0);
        f[0]=0;
        if(mp.count(f)==0) mp[f]=i;
    }
    rep(i,0,1<<15){
        rep(j,0,n) f[j]=-__builtin_popcount(((a[j]&((1<<15)-1)))^i)-(j?f[0]:0);
        f[0]=0;
        if(mp.count(f)){
            cout<<(mp[f]<<15)+i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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