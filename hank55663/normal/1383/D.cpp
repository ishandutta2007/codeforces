#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
int r[255],c[255];
int used[100000];;
int Maxr[255],Maxc[255];
pii loc[100005];
vector<pii> v[255][255];
int degree[255][255];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[255][255];
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            scanf("%d",&a[i][j]);
            r[i]=max(r[i],a[i][j]);
            c[j]=max(c[j],a[i][j]);
        }
    }
    vector<pii> vr,vc;
    for(int i = 0;i<n;i++)vr.pb(mp(r[i],i)),used[r[i]]=1;
    for(int i = 0;i<m;i++)vc.pb(mp(c[i],i)),used[c[i]]=1;
    sort(vr.begin(),vr.end());
    sort(vc.begin(),vc.end());
   // printf("%d %d\n",vr.back().y,vc.back().y);
    int ans[255][255];
    MEM(ans);
    int x=n-1,y=m-1;
    ans[x][y]=n*m;
    Maxr[x]=y;
    Maxc[y]=x;
    loc[ans[x][y]]=mp(x,y);
    while(x!=0||y!=0){
        if(x==0)y--,ans[x][y]=vc[y].x,Maxc[y]=x;//,loc[vc[y].x]=mp(x,y);
        else if(y==0)x--,ans[x][y]=vr[x].x,Maxr[x]=y;//,loc[vr[x].x]=mp(x,y);
        else if(vc[y-1].x==vr[x-1].x){
            x--,y--;
            ans[x][y]=vc[y].x;
            Maxr[x]=y;
            Maxc[y]=x;
       //     loc[ans[x][y]]=mp(x,y);
        }
        else if(vc[y-1].x>vr[x-1].x){
            y--;
            ans[x][y]=vc[y].x;
            Maxc[y]=x;
         //   loc[ans[x][y]]
        }
        else{
            x--;
            ans[x][y]=vr[x].x;
            Maxr[x]=y;//max(Maxr[x],y);
        }
        loc[ans[x][y]]=mp(x,y);
      //  printf("%d %d %d\n",x,y,ans[x][y]);
    }
    /*  for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }*/
  /*  for(int i =0;i<n;i++)printf("%d ",Maxr[i]);
    printf("\n");
    for(int i = 0;i<m;i++)printf("%d ",Maxc[i]);
    printf("\n");*/
    /*for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[vr[i].y][vc[j].y]==vr[i].x)Maxr[i]=j;
            if(a[vr[i].y][vc[j].y]==vc[j].x)Maxc[j]=i;
        }
    }*/
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            int x=i,y=j;
            if(Maxr[x]<=y&&y!=m-1&&ans[x][y+1]==0){
                v[x][y].pb(mp(x,y+1));
                degree[x][y+1]++;
            }
            if(Maxr[x]>=y&&y!=0&&ans[x][y-1]==0){
                v[x][y].pb(mp(x,y-1));
                degree[x][y-1]++;
            }
            if(Maxc[y]<=x&&x!=n-1&&ans[x+1][y]==0){
                v[x][y].pb(mp(x+1,y));
                degree[x+1][y]++;
            }
            if(Maxc[y]>=x&&x!=0&&ans[x-1][y]==0){
                v[x][y].pb(mp(x-1,y));
                degree[x-1][y]++;
            }
        }
    }
    queue<pii> q;
    for(int i = n*m;i>=1;i--){
        if(used[i]){
            int x,y;
            tie(x,y)=loc[i];
            for(auto it:v[x][y]){
                if(--degree[it.x][it.y]==0)q.push(it);
            }
        }
        else{
            int x,y;
            tie(x,y)=q.front();
            q.pop();
            ans[x][y]=i;
            for(auto it:v[x][y]){
                if(--degree[it.x][it.y]==0)q.push(it);
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}