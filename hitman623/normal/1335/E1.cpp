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
int n,a[200005],pre[200005];
void solve(){
    vector<pair<pii,int>> v;
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,201){
        int l=0,r=n+1,cnt=0;
        while(1){
            l++;
            r--;
            while(l<=n and a[l]!=i) l++;
            while(r>=1 and a[r]!=i) r--;
            if(l>=r) break;
            cnt+=2;
            v.pb({{l,r},cnt});
        }
    }
    int ans=1;
    rep(i,1,201){
        rep(j,1,n+1){
            if(a[j]==i) pre[j]=1;
            pre[j]+=pre[j-1];
        }
        for(auto j:v){
            ans=max(ans,j.y+pre[j.x.y-1]-pre[j.x.x]);
        }
        rep(j,1,n+1) pre[j]=0;
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