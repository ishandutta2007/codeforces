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
int n,k,a[300005],f[1000001],ans;
int get(int l,int r){
    r=min(r,1000000);
    return f[r]-f[l-1];
}
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>a[i];
        f[a[i]]++;
    }
    rep(i,1,1000001) f[i]+=f[i-1];
    rep(i,1,1000001){
        int cnt=0;
        for(int j=i;j<=1000000;j+=i){
            cnt+=get(j,min(j+k,j+i-1));
        }
        if(cnt==n) ans=i;
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