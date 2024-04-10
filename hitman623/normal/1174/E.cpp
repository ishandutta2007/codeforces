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
#define N           1000006
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,ff,sp[N];
vi p[N];
mi dp[N];
int go(int g,int x){
    if(x==n) return 1;
    if(dp[x].count(g)) return dp[x][g];
    int res=0;
    if(n/g-x>0) res=1LL*go(g,x+1)*(n/g-x)%hell;
    else res=0;
    for(auto i:p[g]){
        res=(res+1LL*go(g/i,x+1)*(n/(g/i)-n/g))%hell;
    }
    return dp[x][g]=res;
}
void solve(){
    cin>>n;
    int m=n;
    while(m) ff++,m/=2;
    rep(i,1,n+1) sp[i]=i;
    rep(i,2,n+1){
        if(sp[i]!=i) continue;
        for(int j=i;j<=n;j+=i){
            if(sp[j]==j){
                sp[j]=i;
            }
            p[j].pb(i);
        }
    }
    int ans=0;
    rep(i,1,n+1){
        int m=i,cnt=1;
        while(m!=1) cnt++,m/=sp[m];
        if(cnt==ff){
            rep(_,1,n+1) dp[_].clear();
            ans=(ans+go(i,1))%hell;
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