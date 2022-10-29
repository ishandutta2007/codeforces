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
int n,a[200005],f[200005];
void solve(){
    int ans=hell;
    cin>>n;
    rep(i,0,n+1) f[i]=0;
    rep(i,1,n+1) cin>>a[i];
    int pos=1;
    rep(i,1,n+1){
        while(pos<=n and f[a[pos]]==0){
            f[a[pos]]++;
            pos++;
        }
        if(pos<=n and pos-i>0)ans=min(ans,pos-i+1);
        f[a[i]]--;
    }
    if(ans<hell) cout<<ans<<endl;
    else cout<<-1<<endl;
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