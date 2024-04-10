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
#define hell        100000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,x,t[20004],a[5005],dp[5005][5005];
void modify(int p,int val){
    for(t[p+=n+1]=val;p>1;p>>=1) t[p>>1]=max(t[p],t[p^1]);
}
int query(int l,int r){
    int res=-hell;
    for(l+=n+1,r+=n+2;l<r;l>>=1,r>>=1){
        if(l&1) res=max(res,t[l++]);
        if(r&1) res=max(res,t[--r]);
    }
    return res;
}
void solve(){
    cin>>n>>k>>x;
    rep(i,1,n+1){
        cin>>a[i];
    }
    memset(t,-127,sizeof t);
    rep(j,n-k+2,n+2){
        modify(j,a[j-1]);
    }
    rep(i,1,x+1){
        for(int j=n+1;j>=1;j--){
            int r=min(j+k,n+1);
            dp[i][j]=query(j+1,r);
        }
        memset(t,-127,sizeof t);
        rep(j,2,n+2){
            modify(j,dp[i][j]+a[j-1]);
        }
    }
    if(dp[x][1]>=0) cout<<dp[x][1]<<endl;
    else cout<<-1<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}