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
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
int degree[1<<20];
int f[1<<20];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int n;
pii p[500005];
vector<pii> v[1<<20];
int now[1<<20];
vector<int> ans;
vector<int> stk;
int vis[500005];
void dfs(int x){
    while(now[x]!=v[x].size()){
        pii p=v[x][now[x]];
        now[x]++;
        if(vis[abs(p.y)])continue;
        vis[abs(p.y)]=1;
        stk.pb(p.y);
        dfs(p.x);
        ans.pb(stk.back());
        stk.pop_back();
    }
}
int go(int x){
    printf("%d\n",x);
    int mask=(1<<x)-1;
    for(int i = 0;i<n;i++){
        v[p[i].x&mask].pb(mp(p[i].y&mask,-(i+1)));
        v[p[i].y&mask].pb(mp(p[i].x&mask,(i+1)));
  //      printf("%d %d\n",p[i].x&mask,p[i].y&mask);
    }
    dfs(p[0].x&mask);
    //printf("%d\n",x);
    for(auto it:ans){
        if(it>0)
        printf("%d %d ",it*2-1,it*2);
        else
        printf("%d %d ",-it*2,-it*2-1);
    }
    printf("\n");
}
int main(){
    scanf("%d",&n);

    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    for(int i = 1;i<=20;i++){
        MEM(degree);
        for(int j=0;j<(1<<20);j++){
            f[j]=j;
        }
        int mask=(1<<i)-1;
        for(int j=0;j<n;j++){
            degree[p[j].x&((1<<i)-1)]++;
            degree[p[j].y&((1<<i)-1)]++;
            int a=p[j].x&((1<<i)-1);
            int b=p[j].y&((1<<i)-1);
            f[Find(a)]=Find(b);
        }
        int ok=1;
        for(int j = 0;j<n;j++){
            if(Find(p[j].y&mask)!=Find(p[0].x&mask)){
                ok=0;
            //    printf("%d %d %d\n",i,p[j].y&mask,p[0].x&mask);
            }
        }
        for(int j=0;j<(1<<20);j++){
            if(degree[j]&1)ok=0;
        }

        if(!ok){
            go(i-1);
            return 0;
        }
    }
    go(20);
    return 0;
}

/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/