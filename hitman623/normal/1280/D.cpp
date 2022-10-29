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
int n,m,val[3003],s[3003];
pii dp[3003][3003];
pii temp[3003][3003];
vi a[3003];
void pre(int node,int par){
    s[node]=1;
    for(auto i:a[node]){
        if(i!=par){
            pre(i,node);
            s[node]+=s[i];
        }
    }
}
void dfs(int node,int par){
    dp[node][0]={0,0};
    int cur=1;
    for(auto i:a[node]){
        if(i!=par){
            dfs(i,node);
            rep(k,0,s[node]+1) temp[node][k]={-1,hell};
            rep(k,0,cur+1){
                rep(j,0,s[i]+1){
                    pii w={dp[node][k].x+dp[i][j].x,dp[node][k].y+dp[i][j].y};
                    temp[node][k+j]=max(temp[node][k+j],w);
                }
            }
            rep(k,0,s[node]+1) dp[node][k]=temp[node][k];
            cur+=s[i];
        }
    }
    rep(k,0,s[node]) dp[node][k].y+=val[node];
    rep(k,0,s[node]) dp[node][k+1]=max(dp[node][k+1],make_pair(dp[node][k].x+(dp[node][k].y>0),0LL));
}
void solve(){
    cin>>n>>m;
    rep(i,1,n+1){
        val[i]=0;
        a[i].clear();
        s[i]=0;
    }
    rep(i,1,n+1){
        int x;
        cin>>x;
        val[i]-=x;
    }
    rep(i,1,n+1){
        int x;
        cin>>x;
        val[i]+=x;
    }
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    rep(i,1,n+1){
        rep(j,0,m+1){
            dp[i][j]={-1,-hell};
        }
    }
    pre(1,-1);
    dfs(1,-1);
    // rep(i,1,n+1){
    //     rep(j,0,m+1){
    //         cout<<dp[i][j].x<<" : "<<dp[i][j].y<<"     ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[1][m-1].x+(dp[1][m-1].y>0)<<endl;
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