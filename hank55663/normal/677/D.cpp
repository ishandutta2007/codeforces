#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
vector<pii> v[90005];
int a[305][305];
int dp[305][305];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            v[a[i][j]].pb(mp(i,j));
            dp[i][j]=1e9;
        }
    }
    for(auto it:v[1]){
        dp[it.x][it.y]=(it.x-1)+(it.y-1);
    }
   /*  for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    for(int i=2;i<=k;i++){
        if((v[i].size()*v[i-1].size())*(k-1)<100000000){
            for(auto it:v[i]){
                for(auto it2:v[i-1]){
                    dp[it.x][it.y]=min(dp[it.x][it.y],dp[it2.x][it2.y]+abs(it.x-it2.x)+abs(it.y-it2.y));
                }
            }
        }
        else{
            priority_queue<pair<int,pii>,vector<pair<int,pii> >, greater<pair<int,pii> > > pq;
            int dis[305][305];
            for(int i = 1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    dis[i][j]=1e9;
                }
            }
            for(auto it:v[i-1]){
                pq.push(mp(dp[it.x][it.y],it));
            }
            while(!pq.empty()){
                auto p=pq.top();
                pq.pop();
                if(dis[p.y.x][p.y.y]!=1e9)continue;
                dis[p.y.x][p.y.y]=p.x;
                int X[4]={0,0,1,-1};
                int Y[4]={1,-1,0,0};
                for(int j=0;j<4;j++){
                    int x=p.y.x+X[j],y=p.y.y+Y[j];
                    if(x>=1&&x<=n&&y>=1&&y<=m){
                        if(dis[x][y]==1e9){
                            pq.push(mp(p.x+1,mp(x,y)));
                        }
                    }
                }
            }
            for(auto it:v[i]){
                dp[it.x][it.y]=dis[it.x][it.y];
            }
        }
        /*for(int i = 1;i<=n;i++){
            for(int j=1;j<=m;j++){
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }*/
    }
   /* for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n",dp[v[k][0].x][v[k][0].y]);
}
/*
4+3+3+4+3+2+2+1
*/