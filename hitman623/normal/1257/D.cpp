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
int n,m,a[200005],f[200005];
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        f[i]=0;
    }
    cin>>m;
    rep(i,1,m+1){
        int x,y;
        cin>>x>>y;
        f[y]=max(f[y],x);
    }
    for(int i=n-1;i>=0;i--) f[i]=max(f[i],f[i+1]);
    int cur=0,last=0,mx=0,ans=0;
    while(cur<n){
        while(cur+1<=n and f[cur+1-last]>=max(mx,a[cur+1])){
            mx=max(mx,a[cur+1]);
            cur++;
        }
        mx=0;
        if(last==cur){
            cout<<-1<<endl;
            return;
        }
        last=cur;
        ans++;
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