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
#define N 200005
#define rank Rank
#define index Index
LL val[1005];
vector<int> v[1005];
LL ans=0;
LL vis[1005];
void dfs(int i,int dep){
    if(dep&1){
        ans-=val[i];
    }
    else{
        ans+=val[i];
    }
    vis[i]=1;
    LL tot=0;
    for(auto it:v[i]){
        if(!vis[it]){
          //  printf("%d %d\n",i,it);
            dfs(it,dep+1);
            tot+=val[it];
        }
    }
    if(dep&1){
        if(val[i]-tot>tot-val[i]){
            ans+=2*(val[i]-tot);
        }
    }
}
bool cmp(const pair<pll,LL> &p,const pair<pll,LL> &q){
    return p.y>q.y;
}
int main(){
    int n;
    scanf("%d",&n);
    pair<pll,LL> p[1005];
    for(int i = 1;i<=n;i++){
        int x,y,r;
        scanf("%d %d %d",&x,&y,&r);
        p[i]=mp(mp(x,y),r);
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            LL x=p[j].x.x-p[i].x.x,y=p[j].x.y-p[i].x.y;
            LL r=p[i].y;
            if(x*x+y*y<r*r){
                if(p[i].y>p[j].y){
                    v[i].pb(j);
                }
                else{
                    v[j].pb(i);
                }
            }
        }
        val[i]=p[i].y*p[i].y;
    }
    for(int i =1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
        }
    }
    printf("%.12f\n",ans*pi);
    return 0;
}