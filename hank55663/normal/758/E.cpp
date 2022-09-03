#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define less Less
pair<pll,pll> p[200005];
vector<pll> v[200005];
LL dp[200005];
LL use[200005];
LL Size[200005];
void dfs(int x,int f,bool &res){
    Size[x]=0;
    dp[x]=0;
    use[x]=0;
    for(auto it:v[x]){
        if(it.x!=f){
            dfs(it.x,x,res);
            if(Size[it.x]>p[it.y].y.y){
                if(dp[it.x]<Size[it.x]-p[it.y].y.y)
                    res=false;
                else{
                    use[it.x]=Size[it.x]-p[it.y].y.y;
                    dp[x]+=dp[it.x]-use[it.x]+min(dp[it.x]-use[it.x],p[it.y].y.x-1);
                    Size[x]+=p[it.y].y.y+p[it.y].y.x;
                }
            }
            else{
                dp[x]+=dp[it.x]+min(dp[it.x]+p[it.y].y.y-Size[it.x],p[it.y].y.x-1);
                Size[x]+=Size[it.x]+p[it.y].y.x;
            }
        }
    }
}
void dfs2(int x,int f){
   // printf("%d %d\n",x,use[x]);
    for(auto it:v[x]){
        if(it.x!=f){
            if(Size[it.x]<=p[it.y].y.y){
                LL val=min(min(p[it.y].y.y-Size[it.x],p[it.y].y.x-1),use[x]);
                p[it.y].y.y-=val;
                p[it.y].y.x-=val;
                use[x]-=val;
               // printf("%d %lld %lld %lld\n",x,it.x,val,use[x]);
            }
            LL val=min(min(p[it.y].y.x-1,dp[it.x]-use[it.x]),use[x]/2);
            p[it.y].y.x-=val;
            p[it.y].y.y-=val;
            use[it.x]+=val;
            use[x]-=val*2;
           // printf("%lld\n",val);
           // printf("!\n");
        }
    }
    for(auto it:v[x]){
        if(it.x!=f){
            LL val=min(dp[it.x]-use[it.x],use[x]);
            use[it.x]+=val;
            use[x]-=val;
            dfs2(it.x,x);
        }
    }
   // printf("%d %d\n",x,use[x]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y,w,P;
        scanf("%d %d %d %d",&x,&y,&w,&P);
        v[x].pb(mp(y,i));
        v[y].pb(mp(x,i));
        p[i]=mp(mp(x,y),mp(w,P));
    }
    bool res=true;
    dfs(1,0,res);
    if(!res){
        printf("-1\n");
    }
    else{
        dfs2(1,0);
        printf("%d\n",n);
        for(int i = 1;i<n;i++){
            printf("%lld %lld %lld %lld\n",p[i].x.x,p[i].x.y,p[i].y.x,p[i].y.y);
        }
    }
    return 0;
}
/*
1 
2 6 
3 5 
4
*/