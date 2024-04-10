#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
struct node{
    node *l,*r;
    int a,b;
    LL tag;
    LL Min;
    node(int _a,int _b):l(NULL),r(NULL){
        a=_a;
        b=_b;
        Min=0;
        tag=0;
    }
}*root;
LL dis[500005];
LL Min(node *n){
    return n->Min+n->tag;
}
void pull(node *n){
    n->Min=min(Min(n->l),Min(n->r));
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void build(node *n){
    if(n->a==n->b){
    //    printf("%d %d\n",n->a,dis[n->a]);
        n->Min=dis[n->a];
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void add(node *n,int l,int r,LL k){
    if(n==root){
    //    printf("%d %d %lld\n",l,r,k);
    }
    if(l>r)return;
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return ;
    }
    if(n->a>r||n->b<l){
        return ;
    }
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
LL query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return Min(n);
    }
    if(n->a>r||n->b<l){
        return 1e18;
    }
    push(n);
    LL ret=min(query(n->l,l,r),query(n->r,l,r));
    pull(n);
    return ret;
}
vector<pii> v[500005];
vector<pair<pii,int> > que[500005];
LL ans[500005];
int in[500005];
int out[500005];
int ti;
int n;
void dfs(int x,LL dep){
    in[x]=++ti;
    if(v[x].empty()){
        dis[x]=dep;
    }
    for(auto it:v[x]){
        dfs(it.x,it.y+dep);
    }
    out[x]=ti;
}
void dfs2(int x){
    for(auto it:que[x]){
        ans[it.y]=query(root,it.x.x,it.x.y);
       // printf("%d %d\n",it.y,ans[it.y]);
    }
    for(auto it:v[x]){
        add(root,in[it.x],out[it.x],-it.y);
        add(root,1,in[it.x]-1,it.y);
        add(root,out[it.x]+1,n,it.y);
        dfs2(it.x);
        add(root,in[it.x],out[it.x],it.y);
        add(root,1,in[it.x]-1,-it.y);
        add(root,out[it.x]+1,n,-it.y);
    }
}
int main(){
    int q;
    scanf("%d %d",&n,&q);
    fill(dis,dis+n+1,1e18);
    for(int i=2;i<=n;i++){
        int p,w;
        scanf("%d %d",&p,&w);
        v[p].pb(mp(i,w));
    }
    dfs(1,0);
    if(v[1].size()==1)
    dis[1]=0;
    for(int i=0;i<q;i++){
        int u,l,r;
        scanf("%d %d %d",&u,&l,&r);
        que[u].pb(mp(mp(l,r),i));
    }
    root = new node(1,n);
    build(root);
    dfs2(1);
    for(int i=0;i<q;i++)
        printf("%lld\n",ans[i]);
}