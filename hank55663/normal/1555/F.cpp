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
int f[300005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
vector<pii> v[300005];
int p[20][300005];
int dis[300005];
int val[300005];
int in[300005],out[300005];
int t;
void dfs(int x,int f){
    in[x]=++t;
    dis[x]=dis[f]+1;
    p[0][x]=f;
    for(auto it:v[x]){
        if(it.x!=f){
            val[it.x]=val[x]^it.y;
            dfs(it.x,x);
          
        }
    }
    out[x]=t;
}
void build(int n){
    for(int i = 1;i<20;i++){
        for(int j = 1;j<=n;j++){
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
}
int lca(int x,int y){
    if(dis[x]>dis[y])swap(x,y);
    int d=dis[y]-dis[x];
    for(int i = 0;i<20;i++){
        if(d&(1<<i))y=p[i][y];
    }
    if(x==y)return x;
    for(int i = 19;i>=0;i--){
        if(p[i][x]!=p[i][y]){
            x=p[i][x];
            y=p[i][y];
        }
    }
    return p[0][x];
}
struct node{
    node *l,*r;
    int add;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),add(0){

    }
}*root;
void push(node *n){
    n->l->add+=n->add;
    n->r->add+=n->add;
    n->add=0;
}
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void add(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        n->add++;
        return;
    }
    if(n->b<l||n->a>r)return;
    add(n->l,l,r);
    add(n->r,l,r);
}
int query(node *n,int x){
    if(n->a==n->b)return n->add;
    int mid=(n->a+n->b)/2;
    if(x<=mid){
        return query(n->l,x)+n->add;
    }
    else{
        return query(n->r,x)+n->add;
    }
}
pair<int,pii> e[500005];
int ans[500005];
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i = 1;i<=n;i++)f[i]=i;
    MEMS(ans);
    for(int i = 0;i<q;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        int fx=Find(x),fy=Find(y);
        if(fx!=fy){
            f[fx]=fy;
            v[x].pb(mp(y,w));
            v[y].pb(mp(x,w));
            ans[i]=1;
        }
        e[i]=mp(w,mp(x,y));
    }
    for(int i = 1;i<=n;i++){
        if(in[i]==0)dfs(i,0);
    }
    build(n);
    root = new node(1,n);
    build(root);
    for(int i = 0;i<q;i++){
       
        if(ans[i]==-1){
             //printf("! %d\n",i);
            if(val[e[i].y.x]^val[e[i].y.y]^e[i].x){
               // printf("%d %d %d %d %d\n",e[i].y.x,val[e[i].y.x],e[i].y.y,val[e[i].y.y],e[i].x);
                int par=lca(e[i].y.x,e[i].y.y);
                
                if(query(root,in[e[i].y.x])==query(root,in[par])&&query(root,in[e[i].y.y])==query(root,in[par])){
                    ans[i]=1;
                    int now=e[i].y.x;
                    //printf("?\n");
                   // printf("%d\n",par);
                    while(now!=par){//printf("%d\n",now);
                        add(root,in[now],out[now]);
                        now=p[0][now];
                        
                    };
                    now=e[i].y.y;
                    while(now!=par){//printf("%d\n",now);
                        add(root,in[now],out[now]);
                        now=p[0][now];
                          
                    }
                }
                else{
                    ans[i]=0;
                }
            }
            else{
                ans[i]=0;
            }
        }
        if(ans[i]==0)printf("NO\n");
        else printf("YES\n");
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/