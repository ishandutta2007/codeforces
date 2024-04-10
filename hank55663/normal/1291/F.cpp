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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
#define N 6000005
#define rank Rank
#define index Index
vector<pii> v[51024];
int now[51024];
vector<int> num[51024];
int ok[51024];
pii p[5100005];
int index;
int vis[5100005];
vector<int> stk;
void dfs(int x){
  //  printf("%d %d %d\n",x,now[x],v[x].size());
    while(now[x]!=v[x].size()){
        now[x]++;
        if(vis[v[x][now[x]-1].x])continue;
        vis[v[x][now[x]-1].x]=1;
        dfs(v[x][now[x]-1].y);
    }
    stk.pb(x);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);  
    fill(ok,ok+n+1,1);
    if(k==1){
        for(int i = 1;i<=n;i++){
            if(ok[i])
            for(int j=i+1;j<=n;j++){
                printf("? %d\n",i);
                fflush(stdout);
                char c;
                scanf(" %c",&c);
                printf("? %d\n",j);
                fflush(stdout);
                scanf(" %c",&c);
                if(c=='Y'){
                    ok[j]=0;
                }
            }
        }
        int ans=0;
        for(int i = 1;i<=n;i++)if(ok[i])ans++;
        printf("! %d\n",ans);
        fflush(stdout);
    }
    else{
        int node=n/k*2;
    //    printf("%d\n",node);
        for(int i = 0;i<node;i++){
            for(int j=i+1;j<node;j++){
                p[index]=mp(i,j);
                v[i].pb(mp(index,j));
                v[j].pb(mp(index,i));
                index++;
            }
            if((i&1)&&i!=1){
                p[index]=mp(i-1,i);
                v[i].pb(mp(index,i-1));
                v[i-1].pb(mp(index,i));
                index++;
            }
        }
        for(int i = 1;i<=n;i++){
            num[i%node].pb(i);
        }
        dfs(1);
        vector<vector<int> > tt;
        int last=0;
        int vis[1024];
        MEM(vis);
        vector<int> tmp;
        for(auto it:stk){
          //  printf("%d ",it);
            if(vis[it]){
                tt.pb(tmp);
                tmp.clear();
                MEM(vis);
                tmp.pb(last);
             //   tmp.pb(it);
                vis[last]=1;
             //   vis[it]=1;
            }
            tmp.pb(it);
            vis[it]=1;
            last=it;
        }
       // printf("\n");
        tt.pb(tmp);
       // int tot=0;
        for(auto it:tt){
            for(auto it2:it){
          //      printf("! %d\n",it2);
                for(auto  it3:num[it2]){
                    if(ok[it3]){
                        printf("? %d\n",it3);
                        fflush(stdout);
                        char c;
                        scanf(" %c",&c);
                        if(c=='Y'){
                            ok[it3]=0;
                        }
                    }
                }
           //     printf("%d ",it2);
            //    tot+=k/2;
            }
            printf("R\n");
            fflush(stdout);
         //   printf("\n");
        }
      //  printf("\n");
      int ans=0;
      for(int i = 1;i<=n;i++)ans+=ok[i];
      printf("! %d\n",ans);
    }
 /*   for(int n=1;n<=1024;n<<=1){
        for(int k=2;k<=n;k<<=1){
            int node=n/k*2;
            int edge=(node*(node-1))/2;
            
            printf("%d %d %d %d %d %d\n",n,k,node,edge,k,3*n*n/(2*k));
            assert(edge*k<=3*n*n/(2*k)||(node-1)*n<=3*n*n/(2*k));
        }
    }*/

}