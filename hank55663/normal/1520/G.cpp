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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
int dis[2005][2005];
int dis2[2005][2005];
int a[2005][2005];
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
void solve(){
    int n,m,w;
    scanf("%d %d %d",&n,&m,&w);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    MEMS(dis);
    dis[0][0]=0;
    queue<pii> q;
    q.push(mp(0,0));
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        for(int i =0;i<4;i++){
            int x=p.x+X[i],y=p.y+Y[i];
            if(x>=0&&x<n&&y>=0&&y<m&&dis[x][y]==-1&&a[x][y]!=-1){
                q.push(mp(x,y));
                dis[x][y]=dis[p.x][p.y]+1;
            }
        }
    }
    MEMS(dis2);
    q.push(mp(n-1,m-1));
    dis2[n-1][m-1]=0;
     while(!q.empty()){
        pii p=q.front();
        q.pop();
    
        for(int i =0;i<4;i++){
            int x=p.x+X[i],y=p.y+Y[i];
            if(x>=0&&x<n&&y>=0&&y<m&&dis2[x][y]==-1&&a[x][y]!=-1){
                q.push(mp(x,y));
                dis2[x][y]=dis2[p.x][p.y]+1;
            }
        }
    }
    LL ans=1e18;
    if(dis[n-1][m-1]!=-1){
        ans=dis[n-1][m-1]*1ll*w;
    }
    //printf("%lld\n",ans);
    LL Mina=1e18,Minb=1e18;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(dis[i][j]!=-1&&a[i][j]>0){
                Mina=min(Mina,dis[i][j]*1ll*w+a[i][j]);
            }
            if(dis2[i][j]!=-1&&a[i][j]>0){
                Minb=min(Minb,dis2[i][j]*1ll*w+a[i][j]);
            }
        }
    }
  //  printf("%d %d\n",Mina,Minb);
    ans=min(ans,Mina+Minb);
    if(ans==1e18)printf("-1\n");
    else printf("%lld\n",ans);
}
int main(){
  //  for(int i = 1;i*i<=1e9;i++)s.insert(i*i);
    int t=1;00000;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
36
6x+s=ty
x x<<13  x>>7  x<<13>>7
x<<17  x<<30 x>>7<<17 x<<23

*/