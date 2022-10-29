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
int n,k,a[200005],f[400005];
void solve(){
    cin>>n>>k;
    rep(i,0,2*k+1) f[i]=0;
    rep(i,0,n) cin>>a[i];
    rep(i,0,n/2){
        int s=a[i]+a[n-i-1];
        int l=s-max(a[i],a[n-i-1])+1;
        int r=s+max(k-a[i],k-a[n-i-1]);
        if(2<=l-1) f[2]+=2,f[l]-=2;
        f[l]++;
        f[s]--;
        f[s+1]++;
        f[r+1]--;
        f[r+1]+=2;
    }
    int cur=0,ans=hell;
    rep(i,2,2*k+1){
        cur+=f[i];
        ans=min(ans,cur);
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