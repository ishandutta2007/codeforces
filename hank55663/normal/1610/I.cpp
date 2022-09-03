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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<pair<pii,int> > v[300005];
int val[300005];
int sg[300005];
int p[300005];
int vis[300005];
int ans;
int dfs(int x,int f){
    p[x]=f;
    for(auto &it:v[x]){
        if(it.x.x!=f){
            it.y=dfs(it.x.x,x);
            val[x]^=it.y;
        }
    }
   // printf("sg[%d] %d\n",x,val[x]+1);
    sg[x]=val[x]+1;
    return val[x]+1;
}
void solve(){
    int n;
    scanf("%d",&n);
    /*for(int i = 1;i<=n;i++){
        int vis[105];
        fill(vis,vis+105,0);
        for(int j =0;j<i;j++){
            vis[j^(i-j-1)]=1;
        }
        for(int j = 0;j<=i;j++){
            if(!vis[j]){
                printf("%d %d\n",i,j);
                break;
            }
        }
    }*/
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(mp(mp(y,i),-1));
        v[y].pb(mp(mp(x,i),-1));
    }
    ans=dfs(1,1)-1;
    if(ans)printf("1");
    else printf("2");
    vis[1]=1;
   // printf("1 %d\n",ans);
    for(int i = 2;i<=n;i++){
        int x=i;
        if(!vis[i]){
            ans^=val[i];
          //  printf("sg %d\n",val[i]);
            while(!vis[x]){
                if(vis[p[x]])
                ans^=val[p[x]];
                ans^=val[p[x]]^sg[x];
              
           //     printf("sg %d sg[%d]:%d 1 %d\n",val[p[x]],x,sg[x],p[x]);
                  val[p[x]]^=sg[x];
                vis[x]=1;
                ans^=1;
                x=p[x];
            }
        }
       //  printf("%d %d\n",i,ans);
         if(ans)printf("1");
    else printf("2");
    }
    printf("\n");
}

int main(){

    int t=1;0000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/