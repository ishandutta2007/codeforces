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
#define last Last
#define MXN 200005
vector<int> v[1000005];
int level[1000005];
vector<int> ans;
void dfs(int i){
    if(i==0){
        ans.pb(0);
        return;
    }
    queue<int> q;
    int a=level[0]+2,b=level[0]+1;
    for(auto it:v[0]){
        if(level[it]==level[0]){
            q.push(0);
            q.push(it);
            level[0]=a;
            level[it]=b;
            break;
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
       // printf("%d %d\n",x,level[x]);
        for(auto it:v[x]){
            if(level[it]==a-2){
                level[it]=level[x];
                q.push(it);
            }
        }
    }
  //  printf("\n");
    dfs(i-1);
    int tmp=ans.size();
    for(int i = 0;i<tmp;i++){
        for(auto it:v[ans[i]]){
            if(level[it]==b){ans.pb(it);/*printf("??%d %d\n",ans[i],it)*/;break;}
        }
    }
    //printf("\n");
}
void solve(){
    int n;
    scanf("%d",&n);
    int totn=1<<n;
    int totm=(1<<(n-1))*n;
    for(int i = 0;i<totm;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(n);
    for(auto it:ans)printf("%d ",it);
    printf("\n");
    for(int i = 0;i<totn;i++)v[i].clear();
    fill(level,level+totn,0);
    if(n!=1&&n!=2&&n!=4&&n!=8&&n!=16)printf("-1\n");
    else{
        int aans[1000000];
        fill(aans,aans+totn,0);
        for(int i=1;i<totn;i++){
            int lowbit=i&(-i);
            int cnt=__builtin_popcount(lowbit-1);
            aans[ans[i]]=aans[ans[i-lowbit]]^cnt;
        }
        for(int i = 0;i<totn;i++)printf("%d ",aans[i]);
        printf("\n");
        /*for(int i = 0;i<totn;i++){
            int vis[16];
            fill(vis,vis+n+1,0);
            for(auto it:v[i]){
                assert(vis[aans[it]]==0);
                vis[aans[it]]=1;
            }
        }*/
    }
     ans.clear();
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}