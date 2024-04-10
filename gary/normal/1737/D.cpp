/**
 *    author:  gary
 *    created: 07.10.2022 22:15:21
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int d[505][505];
void solve(){
    int n,m;
    cin>>n>>m;
    rb(i,1,n) rb(j,1,n) d[i][j]=INF;
    rb(i,1,n) d[i][i]=0;
    vector<pair<mp,int> > edges;
    rb(i,1,m){
        int u,v;
        LL w;
        cin>>u>>v>>w;
        check_min(d[u][v],1);
        swap(u,v);
        check_min(d[u][v],1);
        edges.emplace_back(II(u,v),w);
    }
    rb(k,1,n){
        rb(i,1,n){
            rb(j,1,n){
                check_min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    LL ans=1e18;
    for(auto it:edges){
        int d_=min(1+d[1][it.first.first]+d[it.first.second][n],1+d[n][it.first.first]+d[it.first.second][1]);
        rb(i,1,n){
            check_min(d_,d[1][i]+d[i][n]+d[i][it.first.first]+2);
            check_min(d_,d[1][i]+d[i][n]+d[i][it.first.second]+2);
        }
        check_min(ans,1ll*it.second*d_);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}