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
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<pii> vx[1005],vy[1005];
int f[1005];
int Size[1005];
int close[1005][1005][4];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int valx[1005],valy[1005];
void solve(){
    int n;
    scanf("%d",&n);
    pii p[1005];
    pii newp[1005];
    map<int,int> X,Y;
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        X[x];
        Y[y];
    }
    int indexx=0,indexy=0;
    for(auto &it:X){
        it.y=++indexx;
        valx[indexx]=it.x;
    }
    for(auto &it:Y){
        it.y=++indexy;
        valy[indexy]=it.x;
    }
    for(int i = 0;i<n;i++){
        newp[i]=mp(X[p[i].x],Y[p[i].y]);
        vx[newp[i].x].pb(mp(p[i].y,i));
        vy[newp[i].y].pb(mp(p[i].x,i));
    }
    for(int i = 1;i<=indexx;i++)sort(vx[i].begin(),vx[i].end());
    for(int i = 1;i<=indexy;i++)sort(vy[i].begin(),vy[i].end());
   // }
    for(int i = 1;i<=indexx;i++){
        int now=0;
        for(int j = 1;j<=indexy;j++){
            while(now!=vx[i].size()&&Y[vx[i][now].x]<=j)now++;
            if(now!=0)
            close[i][j][0]=vx[i][now-1].y;
            else
            close[i][j][0]=-1;
            if(now!=vx[i].size()){
                close[i][j][1]=vx[i][now].y;
            }
            else{
                close[i][j][1]=-1;
            }
        }
    }
   
    for(int i = 1;i<=indexy;i++){
        int now=0;
        for(int j = 1;j<=indexx;j++){
            while(now!=vy[i].size()&&X[vy[i][now].x]<=j)now++;
            if(now!=0)close[j][i][2]=vy[i][now-1].y;
            else
            close[j][i][2]=-1;
            if(now!=vy[i].size()){
                close[j][i][3]=vy[i][now].y;
            }
            else{
                close[j][i][3]=-1;
            }
        }
    }
    /*for(int i = 1;i<=indexx;i++){
        for(int j =1;j<=indexy;j++){
            printf("%d %d %d %d %d %d\n",i,j,close[i][j][0],close[i][j][1],close[i][j][2],close[i][j][3]);
        }
    }*/
    LL Max=2e9+1007,Min=0;
    while(Max>Min+1){
        LL mid=(Max+Min)/2;
        //printf("%lld\n",mid);
        for(int i = 0;i<n;i++){
            f[i]=i;
            Size[i]=1;
        }
        for(int i = 1;i<=indexx;i++){
            for(int j=0;j<vx[i].size()-1;j++){
                if(vx[i][j+1].x-vx[i][j].x<=mid){
                    int x=Find(vx[i][j].y),y=Find(vx[i][j+1].y);
                    if(x!=y){
                    f[x]=y;
                    Size[y]+=Size[x];
                    }
                }
            }
        }
        for(int i = 1;i<=indexy;i++){
             for(int j=0;j<vy[i].size()-1;j++){
                if(vy[i][j+1].x-vy[i][j].x<=mid){
                    int x=Find(vy[i][j].y),y=Find(vy[i][j+1].y);
                    if(x!=y){
                    f[x]=y;
                    Size[y]+=Size[x];
                    }
                }
            }
        }
        int ok=0;
        if(Size[Find(0)]==n)ok=1;
      //  printf("%d\n",Size[Find(0)]);
        for(int i = 1;i<=indexx;i++){
            for(int j=0;j<vx[i].size()-1;j++){
                if(vx[i][j+1].x-vx[i][j].x<=mid*2){
                    int x=Find(vx[i][j].y),y=Find(vx[i][j+1].y);
                    if(x!=y&&Size[x]+Size[y]==n)ok=1;
                }
            }
        }
        for(int i = 1;i<=indexy;i++){
             for(int j=0;j<vy[i].size()-1;j++){
                if(vy[i][j+1].x-vy[i][j].x<=mid*2){
                    int x=Find(vy[i][j].y),y=Find(vy[i][j+1].y);
                    if(x!=y&&Size[x]+Size[y]==n)ok=1;
                }
            }
        }
        for(int i = 1;i<=indexx;i++){
            for(int j = 1;j<=indexy;j++){
                vector<pii> v;
                v.reserve(4);
                for(int k=0;k<4;k++){
                    if(close[i][j][k]!=-1){
                        int x=close[i][j][k];
                        int dis=abs(p[x].x-valx[i])+abs(p[x].y-valy[j]);
                      /*  if(i==2&&j==2){
                            printf("%d %d %d %d %d %d\n",x,dis,p[x].x,p[x].y,valx[i],valy[j]);
                        }*/
                        if(dis<=mid){
                           // printf("%d %d\n",Find(x),Size[Find(x)]);
                            v.pb(mp(Find(x),Size[Find(x)]));
                        }
                    }
                }
               
                sort(v.begin(),v.end());
                int tot=0;
                int last=-1;
                for(auto it:v){
                    if(last!=it.x)tot+=it.y;
                    last=it.x;
                }
                if(tot==n)ok=1;
            }
        }
        if(ok){
            Max=mid;
        }
        else{
            Min=mid;
        }
    }
    if(Min>2e9+7){
        printf("-1\n");
    }
    else{
        printf("%lld\n",Max);
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/