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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int vis[1005][1005];
pii from[1005][1005];
int vis2[1005][1005];
pii from2[1005][1005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int x1,y1,x2,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    int X[8]={1,1,-1,-1,2,2,-2,-2};
    int Y[8]={2,-2,2,-2,1,-1,1,-1};
    MEMS(vis);
    queue<pii> q;
    q.push(mp(x1,y1));
    vis[x1][y1]=0;
    while(!q.empty()){
        pii p =q.front();
        q.pop();
        for(int i = 0;i<8;i++){
            int x=p.x+X[i],y=p.y+Y[i];
            if(x>=1&&x<=n&&y>=1&&y<=m&&vis[x][y]==-1){
                vis[x][y]=vis[p.x][p.y]+1;
                from[x][y]=mp(p.x,p.y);
                q.push(mp(x,y));
            }
        }
    }
    MEMS(vis2);
    vis2[x2][y2]=0;
    q.push(mp(x2,y2));
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        for(int i = 0;i<8;i++){
            int x=p.x+X[i],y=p.y+Y[i];
            if(x>=1&&x<=n&&y>=1&&y<=m&&vis2[x][y]==-1){
                vis2[x][y]=vis2[p.x][p.y]+1;
                from2[x][y]=mp(p.x,p.y);
                q.push(mp(x,y));
            }
        }
    }
    int opx=x2,opy=y2;
    if((x1+y1)%2==(x2+y2)%2){
        if(vis2[n/2+1][m/2]<vis[n/2][m/2]){
            printf("BLACK\n");
            fflush(stdout);
            if(x2==n/2+1&&y2==m/2)return 0;
            scanf("%d %d",&opx,&opy);
            vector<pii> v;
            int x=n/2+1,y=m/2;
            while(x!=x2||y!=y2){
                v.pb(mp(x,y));
                tie(x,y)=from2[x][y];
            }
            reverse(v.begin(),v.end());
            int lastx=x2,lasty=y2;
            for(auto it:v){
                if(abs(lastx-opx)<=2&&abs(lasty-opy)<=2&&abs(lastx-opx)+abs(lasty-opy)==3){
                    printf("%d %d\n",opx,opy);
                    fflush(stdout);
                    return 0;
                }tie(lastx,lasty)=it;
                printf("%d %d\n",it.x,it.y);
                fflush(stdout);
                if(it.x==opx&&it.y==opy)return 0;
                scanf("%d %d",&opx,&opy);
            }
        }
        else if(vis2[n/2][m/2]<=vis[n/2][m/2]){
            printf("BLACK\n");
            fflush(stdout);
            scanf("%d %d",&opx,&opy);
            vector<pii> v;
            int x=n/2,y=m/2;
            while(x!=x2||y!=y2){
                v.pb(mp(x,y));
                tie(x,y)=from2[x][y];
            }
            reverse(v.begin(),v.end());
            v.pb(mp(n/2+1,m/2+2));
            v.pb(mp(n/2-1,m/2+1));
            v.pb(mp(n/2+1,m/2));
            int lastx=x2,lasty=y2;
            for(auto it:v){
                if(abs(lastx-opx)<=2&&abs(lasty-opy)<=2&&abs(lastx-opx)+abs(lasty-opy)==3){
                    printf("%d %d\n",opx,opy);
                    fflush(stdout);
                    return 0;
                }
                tie(lastx,lasty)=it;
                printf("%d %d\n",it.x,it.y);
                fflush(stdout);
                if(it.x==opx&&it.y==opy)return 0;
                scanf("%d %d",&opx,&opy);
            }
        }
        else{
            printf("WHITE\n");
            fflush(stdout);
            vector<pii> v;
            int x=n/2,y=m/2;
            while(x!=x1||y!=y1){
                v.pb(mp(x,y));
                tie(x,y)=from[x][y];
            }
            reverse(v.begin(),v.end());
            for(auto it:v){
                printf("%d %d\n",it.x,it.y);
                fflush(stdout);
            }
        }
    }
    else{
        if(vis[n/2][m/2]<=vis2[n/2+1][m/2]){
            printf("WHITE\n");
            fflush(stdout);
            vector<pii> v;
            int x=n/2,y=m/2;
            while(x!=x1||y!=y1){
                v.pb(mp(x,y));
                tie(x,y)=from[x][y];
            }
            reverse(v.begin(),v.end());
            int lastx=x1,lasty=y1;
            for(auto it:v){
                if(abs(lastx-opx)<=2&&abs(lasty-opy)<=2&&abs(lastx-opx)+abs(lasty-opy)==3){
                    printf("%d %d\n",opx,opy);
                    fflush(stdout);
                    return 0;
                }
                tie(lastx,lasty)=it;
                printf("%d %d\n",it.x,it.y);
                fflush(stdout);
                if(it.x==opx&&it.y==opy)return 0;
                scanf("%d %d",&opx,&opy);
            }
        }
        else if(vis[n/2+1][m/2]<=vis2[n/2+1][m/2]+1){
            printf("WHITE\n");
            fflush(stdout);
            vector<pii> v;
            int x=n/2+1,y=m/2;
            while(x!=x1||y!=y1){
                v.pb(mp(x,y));
                tie(x,y)=from[x][y];
            }
            reverse(v.begin(),v.end());
            v.pb(mp(n/2-1,m/2-1));
            v.pb(mp(n/2+1,m/2-2));
            v.pb(mp(n/2,m/2));
            int lastx=x1,lasty=y1;
            for(auto it:v){
                if(abs(lastx-opx)<=2&&abs(lasty-opy)<=2&&abs(lastx-opx)+abs(lasty-opy)==3){
                    printf("%d %d\n",opx,opy);
                    fflush(stdout);
                    return 0;
                }
                tie(lastx,lasty)=it;
                printf("%d %d\n",it.x,it.y);
                fflush(stdout);
                if(it.x==opx&&it.y==opy)return 0;
                scanf("%d %d",&opx,&opy);
            }
        }
        else{
            printf("BLACK\n");
            fflush(stdout);
            vector<pii> v;
            int x=n/2+1,y=m/2;
            while(x!=x2||y!=y2){
                v.pb(mp(x,y));
                tie(x,y)=from2[x][y];
            }
            reverse(v.begin(),v.end());
            for(auto it:v){
                printf("%d %d\n",it.x,it.y);
                fflush(stdout);
            }
        }
    }
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000

 */