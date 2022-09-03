#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<pii> v[1005];
int dis[1005][1005];
int inq[1005];
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    vector<pii> e;
    for(int i = 0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        v[x].pb(mp(y,w));
        v[y].pb(mp(x,w));
        e.pb(mp(x,y));
    }
    for(int i = 1;i<=n;i++){
        queue<int> q;
        for(int j = 1;j<=n;j++){
            dis[i][j]=1e9;
        }
        dis[i][i]=0;
        q.push(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            inq[x]=0;
            for(auto it:v[x]){
                if(dis[i][it.x]>dis[i][x]+it.y){
                    dis[i][it.x]=dis[i][x]+it.y;
                    if(!inq[it.x]){
                        inq[it.x]=1;
                        q.push(it.x);
                    }
                }
            }
        }
    }
    pii q[1005];
    for(int i=0;i<k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        q[i]=mp(x,y);
    }
    LL ans=1e18;
    for(auto it:e){
        LL sum=0;
        for(int i =0;i<k;i++){
            sum+=min(dis[q[i].x][q[i].y],min(dis[q[i].x][it.x]+dis[it.y][q[i].y],dis[q[i].y][it.x]+dis[it.y][q[i].x]));
        }
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    int n;
    while(t--){
        solve();
    }
}
/*
32 16 15 20 13 2 1
16 8 25 30 10 0 0
5 6 30 24 16 1 1
18 21 39 12 30 1 1
10 8 29 13 36 1 1
24 25 30 31 3 0 0
21 22 10 27 33 0 0
*/