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
vector<pii> v[200005];
int dep[200005];
void dfs(int x,int f){
    dep[x]=0;
    for(auto& it:v[x]){
        if(it.y!=f){
            dfs(it.y,x);
            dep[x]=max(dep[x],dep[it.y]+1);
            it.x=dep[it.y]+1;
        }
    }
   // dep[x]++;
    sort(v[x].begin(),v[x].end());
    reverse(v[x].begin(),v[x].end());
}
bool dfs(int x,int f,int k,int sum){
    if(v[x].back().x==-1){
        v[x].back().x=sum;
    }
    for(auto it:v[x]){
        if(it.y!=f){
            if(it.y==v[x][0].y){
                if(v[x].size()>=2){
                    if(!dfs(it.y,x,k,max(sum,v[x][1].x)+1))return false;
                }
                else{
                    if(!dfs(it.y,x,k,sum+1))return false;
                }
            }
            else{
                if(!dfs(it.y,x,k,max(sum,v[x][0].x)+1))return false;
            }
        }
    }
    sort(v[x].begin(),v[x].end());
    reverse(v[x].begin(),v[x].end());
    //if(v[x].size()>2)
    //printf("%d %d %d\n",x,v[x][1].x,v[x][2].x);
    if(v[x].size()>2&&v[x][1].x+v[x][2].x+1>=k){
        return false;
    }
    return true;
}
int ans[200005];
void dfs2(int x,int f,int k,int color,int add){
    ans[x]=color;
  //  printf("%d %d %d\n",x,v[x][0].y,v[x][0].x);
    if(v[x][0].y==f){
        for(auto it:v[x]){
            if(it.y!=f){
                dfs2(it.y,x,k,(color+add)%k,add);
            }
        }
    }
    else{
        for(auto it:v[x]){
            if(it.y!=f){
                if(it.y==v[x][0].y){
                 //    printf("?%d %d\n",x,it.y);
                    dfs2(it.y,x,k,(color+add)%k,add);
                }
                else{
                   // printf("%d %d\n",x,it.y);
                    dfs2(it.y,x,k,(color-add+k)%k,(k-add)%k);
                }
            }
        }
    }
}
void go(int x,int f,int color){
    ans[x]=color;
    for(auto it:v[x]){
        if(it.y!=f){
            go(it.y,x,color^1);
        }
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(mp(-1,y));
        v[y].pb(mp(-1,x));
    }
    if(k==2){
        go(1,0,0);
        printf("Yes\n");
        for(int i = 1;i<=n;i++){
            printf("%d ",ans[i]+1);
        }
        printf("\n");
        return 0;
    }
    dfs(1,0);
    if(!dfs(1,0,k,0)){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    dfs2(1,0,k,0,1);
    for(int i = 1;i<=n;i++)
        printf("%d ",ans[i]+1);
    printf("\n");
}