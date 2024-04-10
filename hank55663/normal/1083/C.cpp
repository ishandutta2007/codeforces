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
int p[200005];
int locate[200005];
vector<int> v[200005];
int in[200005];
int out[200005];
int t;
int pa[200005][20];
int dep[200005];
void dfs(int x,int f){
    pa[x][0]=f;
    in[x]=++t;
    dep[x]=dep[f]+1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
    out[x]=++t;
}
int lca(int u,int v){
    if(dep[u]<dep[v])
    swap(u,v);
    for(int i=19;i>=0;i--){
        if(dep[pa[u][i]]>=dep[v])
        u=pa[u][i];
    }
    if(u==v)
    return v;
    for(int i=19;i>=0;i--){
        if(pa[u][i]!=pa[v][i]){
            u=pa[u][i];
            v=pa[v][i];
        }
    }
    return pa[u][0];
}
struct node{
    node *l,*r;
    int a,b;
    pii path;
    node(int _a,int _b):l(NULL),r(NULL){
        a=_a,b=_b;
        path=mp(-1,-1);
    }
}*root;
bool cmp(const int &a,const int &b){
    return in[a]<in[b];
}
pii merge(int a,int b,int c){
   // printf("a:%d b:%d c:%d\n",a,b,c);
    if(a==-1||b==-1||c==-1){
      //  printf("-1,-1\n");
        return mp(-1,-1);
    }
    vector<int> v;
    v.pb(a);
    v.pb(b);
    v.pb(c);
    sort(v.begin(),v.end(),cmp);
    if(in[v[1]]<=out[v[0]]&&in[v[2]]<=out[v[1]]){
       // printf("%d %d\n",v[0],v[2]);
    return mp(v[0],v[2]);
    }
    if(in[v[1]]<=out[v[0]]){
        int x=lca(v[1],v[2]);
        if(in[v[0]]<=out[x]&&in[x]<=in[v[0]]){
          //  printf("%d %d\n",v[1],v[2]);
            return mp(v[1],v[2]);
        }
    }
    else if(in[v[2]]<=out[v[1]]){
        int x=lca(v[0],v[2]);
        if(in[v[1]]<=out[x]&&in[x]<=in[v[1]]){
          //  printf("%d %d\n",v[0],v[2]);
            return mp(v[0],v[2]);
        }
    }
  // printf("-1 -1\n");
    return mp(-1,-1);
}
void pull(node *n){
    //printf("?\n");
    pii p1=n->l->path;
    pii p2=n->r->path;
    if(p1==mp(-1,-1)||p2==mp(-1,-1)){
        n->path=mp(-1,-1);
    }
    else{
     //   printf("!!\n");
        pii pp=merge(p1.x,p1.y,p2.x);
    //    printf("%d %d\n",pp.x,pp.y);
        n->path=merge(pp.x,pp.y,p2.y);
    }
  //  printf("!\n");
}
void build(node *n=root){
  //  printf("%d\n",n);
  //  printf("%d %d\n",n->a,n->b);
    if(n->a==n->b){
        n->path=mp(locate[n->a],locate[n->b]);
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void revise(node *n,int x){
    if(n->a==n->b){
        n->path=mp(locate[n->a],locate[n->b]);
        return ;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid)
    revise(n->l,x);
    else
    revise(n->r,x);
    pull(n);
}
int query(){
    node *n=root;
    if(root->path!=mp(-1,-1))return root->b;
    while(n->l->path==mp(-1,-1))n=n->l;
    int res=n->l->b;
    pii path=n->l->path;
    n=n->r;
    while(n&&n->l){
        pii pp=n->l->path;
        pii p1=merge(path.x,path.y,pp.x);
        p1=merge(p1.x,p1.y,pp.y);
        if(p1!=mp(-1,-1)){
            path=p1;
            res=n->l->b;
            n=n->r;
        }
        else{
            n=n->l;
        }
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d",&p[i]),locate[p[i]]=i;
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
    }
    dfs(1,0);
    root=new node(0,n-1);
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            pa[j][i]=pa[pa[j][i-1]][i-1];
        }
    }
    build();
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,y;
            scanf("%d %d",&x,&y);
            swap(locate[p[x]],locate[p[y]]);
            swap(p[x],p[y]);
            revise(root,p[x]);
            revise(root,p[y]);
        }
        else{
            printf("%d\n",query()+1);
        }
    }
}