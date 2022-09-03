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
#define index Index
#define MXN 1000000
char c[105][105][105];
vector<int> v[105];
int dis[105][105];
void dfs(int x,int f,int d,int st){
    dis[st][x]=d;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x,d+1,st);
        }
    }
}
int vis[105];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            scanf("%s",c[i][j]);
            dis[i][j]=-1;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            for(int k = 0;k<n;k++){
                c[i][j][k]=c[j][i][k];
            }
        }
    }
    for(int t=1;t<n;t++){
        int ok=1;
        for(int i = 0;i<n;i++){
            if(c[0][t][i]=='1')ok=0;
            vis[i]=0;
            v[i].clear();
        }
        if(!ok)continue;
      //  printf("%d\n",t);
        queue<pii> q;
        vis[0]=vis[t]=1;
        q.push(mp(0,t));
        q.push(mp(t,0));
        vector<pii> edge;
        edge.pb(mp(0,t));
        while(!q.empty()){
            pii p=q.front();
            q.pop();
         //   printf("? %d %d\n",p.x,p.y);
            for(int i = 0;i<n;i++){
              //  printf("i:%d %d\n",i,vis[i]);
                if(!vis[i]){
                    if(c[p.x][i][p.y]=='1'){
                        edge.pb(mp(p.y,i));
                        vis[i]=1;
                        q.push(mp(p.y,i));
                       // printf("%d %d\n",p.y,i);
                    }
                }
            }
        }
        if(edge.size()!=n-1)continue;
     //   printf("?\n");
        for(auto it:edge){
            v[it.x].pb(it.y);
            v[it.y].pb(it.x);
        //    printf("%d %d\n",it.x,it.y);
        }
        for(int i = 0;i<n;i++){
            dfs(i,i,0,i);
        }
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(dis[i][j]==-1)assert(0);
                for(int k = 0;k<n;k++){
                    if(dis[i][k]==dis[j][k]){
                        if(c[i][j][k]=='0'){
                            ok=0;
                           // printf("%d %d %d %d %d\n",i,j,k,dis[i][k],dis[j][k]);
                //           printf("No\n");
                         //   return;
                        }
                    }
                    else{
                        if(c[i][j][k]=='1'){
                            ok=0;
                            //      printf("%d %d %d\n",i,j,k);
                            //printf("No\n");
                       //     return;
                        }
                    }
                }
            }
        }
        if(ok){
            printf("Yes\n");
            for(int i = 0;i<n;i++){
                for(auto it:v[i]){
                    if(it>i){
                        printf("%d %d\n",i+1,it+1);
                    }
                }
            }
            return;
        }
    }
    printf("No\n");
}
int main(){
 //   srand(time(NULL));
    int t=1;00000;
    scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}