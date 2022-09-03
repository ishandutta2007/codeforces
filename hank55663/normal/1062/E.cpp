
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
int p[100005][20];
int d[100005];
int in[100005];
int inv[100005];
vector<int> v[100005];
int t;
void dfs(int x,int f){
    d[x]=d[f]+1;
    in[x]=++t;
    inv[t]=x;
    p[x][0]=f;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
}
int lca(int x,int y){
    if(d[x]<d[y])
    swap(x,y);
    for(int i=19;i>=0;i--){
        if(d[p[x][i]]>=d[y])
        x=p[x][i];
    }
    if(x==y)return x;
    for(int i=19;i>=0;i--){
        if(p[x][i]!=p[y][i])
        x=p[x][i],y=p[y][i];
    }
    return p[x][0];
}
struct node{
    pii Min;
    pii Max;
    node *l,*r;
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL){
        a=_a;
        b=_b;
    }
}*root;
pii mergemax(pii a,pii b){
    pii res=mp(0,0);
    res.x=max(a.x,b.x);
    int arr[4]={a.x,a.y,b.x,b.y};
    for(int i=0;i<4;i++){
        if(arr[i]!=res.x)
            res.y=max(res.y,arr[i]);
    }
    return res;
}
pii mergemin(pii a,pii b){
    pii res=mp(1000000,1000000);
    res.x=min(a.x,b.x);
    int arr[4]={a.x,a.y,b.x,b.y};
    for(int i=0;i<4;i++){
        if(arr[i]!=res.x)
            res.y=min(res.y,arr[i]);
    }
    return res;
}
void pull(node *n){
    n->Min=mergemin(n->l->Min,n->r->Min);
    n->Max=mergemax(n->l->Max,n->r->Max);
}
void build(node *n=root){
    if(n->a==n->b){
        n->Min=n->Max=mp(in[n->a],in[n->a]);
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
pair<pii,pii> query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return mp(n->Min,n->Max);
    }
    if(l>n->b||r<n->a){
        return mp(mp(1000000,1000000),mp(-1,-1));
    }
    pair<pii,pii> p1,p2;
    p1=query(n->l,l,r);
    p2=query(n->r,l,r);
    return mp(mergemin(p1.x,p2.x),mergemax(p1.y,p2.y));
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
    }
    dfs(1,0);
    for(int i=1;i<=19;i++){
        for(int j=1;j<=n;j++){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
    root=new node(1,n);
    build(root);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        pair<pii,pii> ans=query(root,l,r);
        int a1=lca(inv[ans.x.x],inv[ans.y.y]);
        int a2=lca(inv[ans.x.y],inv[ans.y.x]);
      //  printf("%d %d %d %d\n",inv[ans.x.x],inv[ans.x.y],inv[ans.y.x],inv[ans.y.y]);
      //  printf("%d %d\n",a1,a2);
        if(d[a1]>d[a2]){
            printf("%d %d\n",inv[ans.y.x],d[a1]-1);
        }
        else{
            printf("%d %d\n",inv[ans.x.x],d[a2]-1);
        }
    }
}