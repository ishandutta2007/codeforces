#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int dis[1005][1005][4];
char c[1005][1005];
int X[4]={0,-1,0,1};
int Y[4]={-1,0,1,0};
int ok[1005][1005][4];
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    memset(dis,-1,sizeof(dis));
    for(int i = 1;i<=n;i++){
        scanf("%s",c[i]+1);
        for(int j = 1;j<=m;j++){
            if(c[i][j]=='+')ok[i][j][0]=ok[i][j][1]=ok[i][j][2]=ok[i][j][3]=1;
            if(c[i][j]=='-')ok[i][j][0]=ok[i][j][2]=1;
            if(c[i][j]=='|')ok[i][j][1]=ok[i][j][3]=1;
            if(c[i][j]=='^')ok[i][j][1]=1;
            if(c[i][j]=='>')ok[i][j][2]=1;
            if(c[i][j]=='<')ok[i][j][0]=1;
            if(c[i][j]=='v')ok[i][j][3]=1;
            if(c[i][j]=='L')ok[i][j][1]=ok[i][j][2]=ok[i][j][3]=1;
            if(c[i][j]=='R')ok[i][j][0]=ok[i][j][1]=ok[i][j][3]=1;
            if(c[i][j]=='U')ok[i][j][0]=ok[i][j][2]=ok[i][j][3]=1;
            if(c[i][j]=='D')ok[i][j][0]=ok[i][j][1]=ok[i][j][2]=1;
        }
    }
    int sx,sy,tx,ty;
    scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
    queue<pair<pii,int> > q;
    q.push(mp(mp(sx,sy),0));
    dis[sx][sy][0]=0;
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        int x=p.x.x,y=p.x.y;
        int t=p.y;
      //  printf("%d %d %d %d\n",x,y,t,dis[x][y][t]);
        if(dis[x][y][(t+1)%4]==-1){
            dis[x][y][(t+1)%4]=dis[x][y][t]+1;
            q.push(mp(mp(x,y),(t+1)%4));
        }
        for(int i = 0;i<4;i++){
            int tx=x+X[i],ty=y+Y[i];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m){
                if(dis[tx][ty][t]==-1&&ok[x][y][(i-t+4)%4]&&ok[tx][ty][((i-t+4)%4)^2]){
                    q.push(mp(mp(tx,ty),t));
                    dis[tx][ty][t]=dis[x][y][t]+1;
                }
            }
        }
    }
    printf("%d\n",min(min(dis[tx][ty][0],dis[tx][ty][1]),min(dis[tx][ty][2],dis[tx][ty][3])));
    return true;
}
int main(){
    int t=1;;//  scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}