#include<bits/stdc++.h>
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
using namespace std;
vector<pii> v[200005];
vector<pii> in[200005];
LL go[10][10][10][10];
int pre[200005][10][10];
int suf[200005][10][10];
LL ans=0;
LL ok[10][10];
vector<int> res;
void dfs(int x){
    if(x==0){
        ans++;
     /*   printf("?\n");
        for(auto it:res)printf("%d ",it);
        printf("\n");*/
        return;
    }
    for(int i = 0;i<x;i++){
        for(int a=0;a<10;a++){
            for(int b=0;b<10;b++){
                ok[a][b]-=go[x][i][a][b];
            }
        }
        if(ok[x][i]==1){
         //   res.pb(i);
            dfs(x-1);
           // res.pop_back();
        }
         for(int a=0;a<10;a++){
            for(int b=0;b<10;b++){
                ok[a][b]+=go[x][i][a][b];
            }
        }
    }
}
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i<10;i++){
        for(int j=0;j<10;j++)ok[i][j]=1;
    }
    for(int i = 0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        v[x].pb(mp(w,y));
    }
    for(int i = 1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
        for(int j=0;j<v[i].size();j++){
            in[v[i][j].y].pb(mp(v[i].size(),j));
          //  printf("??%d %d %d\n",i,v[i][j].y,j);
        }
    }
    for(int i = 1;i<=n;i++){

        MEM(pre[0]);
        for(int j = 0;j<in[i].size();j++){
            for(int a = 0;a<10;a++){
                for(int b=0;b<10;b++){
                    pre[j+1][a][b]=pre[j][a][b];
                }
            }
            pre[j+1][in[i][j].x][in[i][j].y]=1;
        }
        MEM(suf[in[i].size()]);
        for(int j = in[i].size()-1;j>=0;j--){
            for(int a = 0;a<10;a++){
                for(int b=0;b<10;b++){
                    suf[j][a][b]=suf[j+1][a][b];
                }
            }
            suf[j][in[i][j].x][in[i][j].y]=1;
        }
        for(int j = 0;j<in[i].size();j++){
        //    LL mask[9][9];
         //   printf("%d %d %d?\n",i,in[i][j].x,in[i][j].y);
            for(int a=0;a<10;a++){
                for(int b=0;b<10;b++){
                    go[in[i][j].x][in[i][j].y][a][b]|=pre[j][a][b]|suf[j+1][a][b]; 
                }
            }
        }
    }
  //  printf("%d %d\n",go)
    dfs(k);
    printf("%lld\n",ans);
}
int main(){
    int t=1;
   // scanf("%d",&t);
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