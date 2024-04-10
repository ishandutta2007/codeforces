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
struct state{
    int a,b,c,d;
};
int X[8]={-2,-2,-1,-1,1,1,2,2};
int Y[8]={1,-1,2,-2,2,-2,1,-1};
pii dis[15][15][105][3];
bool cmp(const state &a,const state &b){
    return dis[a.a][a.b][a.c][a.d]<dis[b.a][b.b][b.c][b.d];
}
int main(){
    int n;
    scanf("%d",&n);
    int a[15][15];
    pii p[105];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            p[a[i][j]]=mp(i,j);
        }
    MEMS(dis);
    dis[p[1].x][p[1].y][1][0]=dis[p[1].x][p[1].y][1][1]=dis[p[1].x][p[1].y][1][2]=mp(0,0);
    queue<state> q;
    vector<state> v;
    for(int i=0;i<3;i++)
    q.push({p[1].x,p[1].y,1,i});
    pii ans=mp(1e9,1e9);
    while(!q.empty()){
        while(!q.empty()){
            state s=q.front();
            q.pop();
            int x=s.a;
            int y=s.b;
            int num=s.c;
            int type=s.d;
        // printf("%d %d %d %d\n",x,y,num,type);
            if(num==n*n){
                ans=min(ans,dis[x][y][num][type]);
            }
            if(type==0){
                for(int k=0;k<8;k++){
                    int xx=X[k]+x;
                    int yy=Y[k]+y;
                    int nn=num;
                    if(xx>=0&&xx<n&&yy>=0&&yy<n){
                        if(a[xx][yy]==num+1)
                            nn++;
                        pii p=dis[x][y][num][type];
                        p.x++;
                        if(dis[xx][yy][nn][type]==mp(-1,-1)){
                            v.pb({xx,yy,nn,type});
                            dis[xx][yy][nn][type]=p;
                        }
                        dis[xx][yy][nn][type]=min(p,dis[xx][yy][nn][type]);
                    }
                }
            }
            else if(type==1){
                for(int i=0;i<n;i++){
                    int xx=x;
                    int yy=i;
                    int nn=num;
                    if(xx>=0&&xx<n&&yy>=0&&yy<n){
                        if(a[xx][yy]==num+1)
                            nn++;
                        pii p=dis[x][y][num][type];
                        p.x++;
                        if(dis[xx][yy][nn][type]==mp(-1,-1)){
                            v.pb({xx,yy,nn,type});
                            dis[xx][yy][nn][type]=p;
                        }
                        dis[xx][yy][nn][type]=min(p,dis[xx][yy][nn][type]);
                    }
                }
                for(int i=0;i<n;i++){
                    int xx=i;
                    int yy=y;
                    int nn=num;
                    if(xx>=0&&xx<n&&yy>=0&&yy<n){
                        if(a[xx][yy]==num+1)
                            nn++;
                        pii p=dis[x][y][num][type];
                        p.x++;
                        if(dis[xx][yy][nn][type]==mp(-1,-1)){
                            v.pb({xx,yy,nn,type});
                            dis[xx][yy][nn][type]=p;
                        }
                        dis[xx][yy][nn][type]=min(p,dis[xx][yy][nn][type]);
                    }
                }
            }
            else{
                for(int i=0;i<n;i++){
                    int xx=x+i;
                    int yy=y+i;
                    int nn=num;
                    if(xx>=0&&xx<n&&yy>=0&&yy<n){
                        if(a[xx][yy]==num+1)
                            nn++;
                        pii p=dis[x][y][num][type];
                        p.x++;
                        if(dis[xx][yy][nn][type]==mp(-1,-1)){
                            v.pb({xx,yy,nn,type});
                            dis[xx][yy][nn][type]=p;
                        }
                        dis[xx][yy][nn][type]=min(p,dis[xx][yy][nn][type]);
                    }
                }
                for(int i=0;i<n;i++){
                    int xx=x-i;
                    int yy=y+i;
                    int nn=num;
                    if(xx>=0&&xx<n&&yy>=0&&yy<n){
                        if(a[xx][yy]==num+1)
                            nn++;
                        pii p=dis[x][y][num][type];
                        p.x++;
                        if(dis[xx][yy][nn][type]==mp(-1,-1)){
                            v.pb({xx,yy,nn,type});
                            dis[xx][yy][nn][type]=p;
                        }
                        dis[xx][yy][nn][type]=min(p,dis[xx][yy][nn][type]);
                    }
                }
                for(int i=0;i<n;i++){
                    int xx=x+i;
                    int yy=y-i;
                    int nn=num;
                    if(xx>=0&&xx<n&&yy>=0&&yy<n){
                        if(a[xx][yy]==num+1)
                            nn++;
                        pii p=dis[x][y][num][type];
                        p.x++;
                        if(dis[xx][yy][nn][type]==mp(-1,-1)){
                            v.pb({xx,yy,nn,type});
                            dis[xx][yy][nn][type]=p;
                        }
                        dis[xx][yy][nn][type]=min(p,dis[xx][yy][nn][type]);
                    }
                }
                for(int i=0;i<n;i++){
                    int xx=x-i;
                    int yy=y-i;
                    int nn=num;
                    if(xx>=0&&xx<n&&yy>=0&&yy<n){
                        if(a[xx][yy]==num+1)
                            nn++;
                        pii p=dis[x][y][num][type];
                        p.x++;
                        if(dis[xx][yy][nn][type]==mp(-1,-1)){
                            v.pb({xx,yy,nn,type});
                            dis[xx][yy][nn][type]=p;
                        }
                        dis[xx][yy][nn][type]=min(p,dis[xx][yy][nn][type]);
                    }
                }
            }
            for(int i=0;i<3;i++){
                pii p=dis[x][y][num][type];
                p.x++;
                p.y++;
                if(dis[x][y][num][i]==mp(-1,-1)){
                    v.pb({x,y,num,i});
                    dis[x][y][num][i]=p;
                }
                dis[x][y][num][i]=min(dis[x][y][num][i],p);
            }
        }
        sort(v.begin(),v.end(),cmp);
        for(auto it:v)
        q.push(it);
        v.clear();
    }
    printf("%d %d\n",ans.x,ans.y);
}