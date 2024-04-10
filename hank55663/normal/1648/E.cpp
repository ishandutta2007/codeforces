#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
const int mod=998244353;
#define MXN 2005
vector<pii> v[200005];
vector<int> com[200005];
int Size[200005];
int f[200005],f2[200005];
int Find(int x,int *f){
    if(f[x]==x)return x;
    return f[x]=Find(f[x],f);
}
pii edge[200005];
int p[20][200005],val[20][200005];
int d[200005];
void dfs(int x,int f){
    d[x]=d[f]+1;
    for(auto it:v[x]){
        if(it.x!=f){
           // printf("%d %d\n",x,it.x);
            p[0][it.x]=x;
            val[0][it.x]=it.y;
            dfs(it.x,x);
        }
    }
}
void build(int n){
     /* for(int i = 1;i<20;i++){
        for(int j=1;j<=n;j++){
            //p[i][j]=p[i-1][p[i-1][j]];
            val[i][j]=max(val[i-1][j],val[i-1][p[i-1][j]]);
        }
    }*/
    for(int i = 1;i<20;i++){
        for(int j=1;j<=n;j++){
            p[i][j]=p[i-1][p[i-1][j]];
            val[i][j]=max(val[i-1][j],val[i-1][p[i-1][j]]);
        }
    }
}
int lca(int x,int y){
    if(d[y]<d[x])swap(x,y);
    int dd=d[y]-d[x];
    int ans=0;
  //  printf("?%d %d %d?\n",x,y,dd);
    for(int i=0;i<20;i++){
        if(dd&(1<<i)){
            ans=max(ans,val[i][y]);
           // printf("%d\n",val[i][y]);
            y=p[i][y];
        }
    }
    if(x==y)return ans;
    for(int i = 19;i>=0;i--){
        if(p[i][x]!=p[i][y]){
            ans=max(val[i][x],ans);
            ans=max(val[i][y],ans);
            x=p[i][x];
            y=p[i][y];
        }
    }
    ans=max(val[0][x],ans);
    ans=max(val[0][y],ans);
    return ans;
}
set<pii> s;
bool dfs2(int a,int b,int fa,int fb){
    if(s.find(mp(a,b))==s.end())return true;
    for(auto it:v[b]){
        if(it.x!=fb)
        if(dfs2(a,it.x,fa,b))return true;
    }
    for(auto it:v[a]){
        if(it.x!=fa)
        if(dfs2(it.x,b,a,fb))return true;
    }
    return false;
}
bool check(int a,int b){
    return dfs2(a,b,0,0);
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    s.clear();
    for(int i = 0;i<=n;i++){
        Size[i]=1;
        com[i].clear();
        v[i].clear();
        com[i].pb(i);
        for(int k=0;k<20;k++)
        val[k][i]=0;
      //  com2[i].pb(i);
        f2[i]=i;
        f[i]=i;
    }
    vector<pair<int,pii> > e;
    set<int> dd;
    for(int i = 0;i<m;i++){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        e.pb(mp(c,mp(x,y)));
        dd.insert(c);
        edge[i]=mp(x,y);
        s.insert(mp(x,y));
        s.insert(mp(y,x));
    }
    sort(e.begin(),e.end());
    for(auto it:e){
        int a=Find(it.y.x,f),b=Find(it.y.y,f);
        int w=it.x;
        if(a!=b){
            if(Size[a]>Size[b])swap(a,b);
            f[a]=b;
            vector<pii> ttmp;
            for(auto it:com[b]){
                vector<int> ok;
                vector<int> tmp;
                for(auto it2:com[a]){
                    if(check(it,it2)){
                        if(ok.empty()){
                            tmp.pb(it2);
                        }
                        ok.pb(it2);
                    }
                    else{
                        tmp.pb(it2);
                    }
                }
                for(auto it2:ok){
                    if(Find(ok[0],f2)!=Find(it2,f2)){
                    v[ok[0]].pb(mp(it2,w));
                    v[it2].pb(mp(ok[0],w));
                       // printf("%d %d %d\n",it,it2,w);
                    f2[Find(ok[0],f2)]=Find(it2,f2);
                    }
                }
                if(ok.size())
                ttmp.pb(mp(ok[0],it));
                swap(com[a],tmp);
            }
            for(auto it:ttmp){
                if(Find(it.x,f2)!=Find(it.y,f2)){
                    v[it.x].pb(mp(it.y,w));
                    v[it.y].pb(mp(it.x,w));
                    f2[Find(it.x,f2)]=Find(it.y,f2);
                }
            }
            vector<int> tmp;
            for(auto it:com[b]){
                if(Find(it,f2)==it)tmp.pb(it);
            }
            for(auto it:com[a]){
                if(Find(it,f2)==it)tmp.pb(it);
            }
            swap(tmp,com[b]);
            Size[b]+=Size[a];   
        }
    }
    for(int i =1;i<=n;i++)assert(Find(i,f2)==Find(1,f2));
    dfs(1,0);
    build(n);
    for(int i = 0;i<m;i++){
        int res;
        printf("%d ",res=lca(edge[i].x,edge[i].y));
        assert(dd.find(res)!=dd.end());
    }
    printf("\n");
}
int main(){
    int t=1;0000;
      scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}