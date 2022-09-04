
#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
char c[2005][2005];
int ok[2005][2005];
int dis[2005][2005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int x,y;
    scanf("%d %d",&x,&y);
    int l,r;
    scanf("%d %d",&l,&r);
    for(int i=1;i<=n;i++)
        scanf("%s",c[i]+1);
    queue<pii> q,q2;
    q.push(mp(x,y));
    ok[x][y]=1;
    dis[x][y]=0;
    while(!q.empty()){
        while(!q.empty()){
            pii p=q.front();
            q.pop();
            q2.push(p);
            int x=p.x+1,y=p.y;
            if(!ok[x][y]&&c[x][y]=='.'){
                ok[x][y]=1;
                q.push(mp(x,y));
                dis[x][y]=dis[p.x][p.y];
            }
            x=p.x-1,y=p.y;
            if(!ok[x][y]&&c[x][y]=='.'){
                ok[x][y]=1;
                q.push(mp(x,y));
                dis[x][y]=dis[p.x][p.y];
            }
        }
        while(!q2.empty()){
            pii p=q2.front();
            q2.pop();
            int x=p.x,y=p.y+1;
            if(!ok[x][y]&&c[x][y]=='.'){
                ok[x][y]=1;
                q.push(mp(x,y));
                dis[x][y]=dis[p.x][p.y]+1;
            }
            x=p.x,y=p.y-1;
            if(!ok[x][y]&&c[x][y]=='.'){
                ok[x][y]=1;
                q.push(mp(x,y));
                dis[x][y]=dis[p.x][p.y]+1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!ok[i][j]){
             //   printf("0");
                continue;
            }
            int d=dis[i][j];
            int ll=0,rr=0;
            if(y>j){
                ll+=y-j;
                int xx=(d-ll)/2;
                ll+=xx;
                rr+=xx;
            }
            if(y<=j){
                rr+=j-y;
                int xx=(d-rr)/2;
                ll+=xx;
                rr+=xx;
            }
            if(ll<=l&&rr<=r){
               // printf("%d %d %d %d %d\n",d,ll,rr,l,r);
                ans++;
            }
            else{
               // printf("0");
            }
           // printf("%d",ok[i][j]);
        }
    }
    printf("%d\n",ans);
}