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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
vector<int> v[200005];
int Sum[200005];
int color[200005];
void dfs(int x,int f){
    Sum[x]+=color[x];
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Sum[x]+=max(Sum[it],0);
        }
    }
}
int ans[200005];
void dfs2(int x,int f,int sum){
   // printf("!%d %d %d\n",sum,x,Sum[x]);
    ans[x]=max(ans[x],Sum[x]+sum);
    sum+=Sum[x];
    for(auto it:v[x]){
        if(it!=f){
            dfs2(it,x,max(sum-max(Sum[it],0),0));
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&color[i]);
        if(color[i]==0)color[i]=-1;
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    fill(ans,ans+n+1,-10);
   // for(int t=0;t<2;t++){
        dfs(1,0);
        dfs2(1,0,0);
        //for(int i = 1;i<=n;i++)color[i]*=-1;
        for(int i = 1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
   // }
   // for(int i = 1;i<=n;i++)printf("%d ",ans[i]);
   // printf("\n");
}
/*
4+3+3+4+3+2+2+1
*/