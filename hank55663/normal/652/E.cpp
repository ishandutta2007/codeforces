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
#define N 262144
vector<vector<pii> > v;
int vis[300005],lwn[300005];
vector<int> stk;
int f[300005];
int bln[300005];
int val[300005];
int Find(int a){
    if(bln[a]==a)return a;
    return bln[a]=Find(bln[a]);
}
int t;
void dfs(int a,int p){
    stk.pb(a);
    bln[a]=a;
    vis[a]=lwn[a]=++t;
    for(pii it:v[a]){
        int x=it.x;
        if(x!=p){
            if(vis[x]==0){
                dfs(x,a);
                if(lwn[x]>vis[a]){
                    int fa=Find(x);
                    f[x]=Find(a);
                    while(stk.back()!=x){
                        bln[stk.back()]=fa;
                        stk.pop_back();
                    }
                    bln[stk.back()]=fa;
                    stk.pop_back();
                }
                lwn[a]=min(lwn[a],lwn[x]);
            }
            else{
                lwn[a]=min(lwn[a],vis[x]);
            }
        }
    }
}
vector<pii> v2[300005];
bool dfs(int s,int f,int t,int &ans,int sum){
    sum+=val[s];
    if(s==t){
        ans=sum;
        return true;
    }
    for(auto it:v2[s]){
        if(it.x!=f){
            if(dfs(it.x,s,t,ans,sum+it.y))return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    v.resize(n+1);
    pair<pii,int> p[300005];
    for(int i = 0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        v[x].pb(mp(y,w));
        v[y].pb(mp(x,w));
        p[i]=mp(mp(x,y),w);
    }
    dfs(1,0);
    while(!stk.empty()){
        bln[Find(stk.back())]=1;
        stk.pop_back();
    }
    for(int i = 1;i<=n;i++){
        Find(i);//printf("%d ",bln[i]);
    }
    for(int i = 0;i<m;i++){
        int a=Find(p[i].x.x),b=Find(p[i].x.y);
        if(a==b){
            val[a]+=p[i].y;
        }
        else{
            v2[a].pb(mp(bln[b],p[i].y));
            v2[b].pb(mp(bln[a],p[i].y));
        }
    }
    int s,t;
    scanf("%d %d",&s,&t);
    int ans;
    dfs(Find(s),0,Find(t),ans,0);
    if(ans){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/