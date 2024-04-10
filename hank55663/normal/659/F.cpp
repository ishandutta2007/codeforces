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
#define N 1000000
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
pii f[1005][1005];
int Size[1005][1005];
int vis[1005][1005];
pii Find(int x,int y){
    if(f[x][y]==mp(x,y))return mp(x,y);
    return f[x][y]=Find(f[x][y].x,f[x][y].y);
}
int a[1005][1005];
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
int ok[1005][1005];
int cnt=0;
void dfs(int tx,int ty,int v,int need){
    if(ok[tx][ty])return;
    if(cnt==need)return;
    cnt++;
    ok[tx][ty]=1;
    for(int i = 0;i<4;i++){
        int x=tx+X[i],y=ty+Y[i];
        if(vis[x][y]){
            dfs(x,y,v,need);
        }
    }
}
bool solve(){
    int n,m;
    LL k;
    scanf("%d %d %lld",&n,&m,&k);
    vector<pair<int,pii> > v;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf("%d",&a[i][j]);
            v.pb(mp(a[i][j],mp(i,j)));
            f[i][j]=mp(i,j);
            Size[i][j]=1;
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(auto it:v){
        int tx=it.y.x;
        int ty=it.y.y;
        vis[tx][ty]=1;
        for(int i = 0;i<4;i++){
            int x=tx+X[i],y=ty+Y[i];
            if(vis[x][y]){
                pii a=Find(x,y),b=Find(tx,ty);
                if(a!=b){
                    Size[b.x][b.y]+=Size[a.x][a.y];
                    f[a.x][a.y]=b;
                }
            }
        }
        pii b=Find(tx,ty);
        if(k%it.x==0&&Size[b.x][b.y]>=k/it.x){
            printf("YES\n");
            dfs(tx,ty,it.x,k/it.x);
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=m;j++){
                    if(ok[i][j])printf("%d ",it.x);
                    else printf("0 ");
                }
                printf("\n");
            }
            return true;
        }
    }
    printf("NO\n");
    return true;
}
int main(){
    int t=1;
    while(t--)solve();
}