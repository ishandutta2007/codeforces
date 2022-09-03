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
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash;
#define MXN 100005
struct node{
    node *l,*r;
    int a,b;
    int tag;
    node(int _a,int _b){
        l=NULL;
        r=NULL;
        a=_a;
        b=_b;
        tag=0;
    }
}*root;
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return ;
    }
    if(n->a>r||n->b<l){
        return ;
    }
    add(n->l,l,r,k);
    add(n->r,l,r,k);
}
int query(node *n,int x){
    if(n->a==n->b)
    return n->tag;
    int mid=(n->a+n->b)/2;
    if(x<=mid)
    return query(n->l,x)+n->tag;
    return query(n->r,x)+n->tag;
}
int p[100005][20];
int d[100005];
int in[100005];
int out[100005];
int ti;
vector<int> v[100005];
void dfs(int x,int f){
    in[x]=++ti;
    p[x][0]=f;
    d[x]=d[f]+1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
    out[x]=ti;
}
void buildp(int n){
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++)
            p[j][i]=p[p[j][i-1]][i-1];
    }
}
int lca(int x,int y){

    if(d[x]<d[y])swap(x,y);
    for(int i=19;i>=0;i--){
        if(d[p[x][i]]>=d[y])x=p[x][i];
    }
    if(x==y)return x;
    for(int i=19;i>=0;i--){
        if(p[x][i]!=p[y][i]){
            x=p[x][i];
            y=p[y][i];
        }
    }
    return p[x][0];
}
int mod=1e9+7;
LL dp[100005][305];
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n-1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    buildp(n);
    root = new node(1,n);
    build(root);
    while(q--){
        int k,m,r;
        scanf("%d %d %d",&k,&m,&r);
        for(int i=0;i<=k;i++){
            for(int j=0;j<=m;j++)
                dp[i][j]=0;
        }
        dp[0][0]=1;
        vector<pii> v;
        for(int i=0;i<k;i++){
            int x;
            scanf("%d",&x);
            int pa=lca(r,x);
            int dis=d[x]+d[r]-2*d[pa];
           // printf("%lld\n",dis);
            v.pb(mp(dis,x));
        }
        sort(v.begin(),v.end());
        for(int i=1;i<=k;i++){
            int x=query(root,in[v[i-1].y]);
            for(int j=1;j<=m;j++){

                dp[i][j]=(dp[i-1][j]*max(j-x,0)+dp[i-1][j-1])%mod;
            }
            x=v[i-1].y;
            if(in[x]<in[r]&&out[x]>=in[r]){
                int y=r;
                for(int i=19;i>=0;i--){
                    if(d[p[y][i]]>d[x])y=p[y][i];
                }
                add(root,1,n,1);
                add(root,in[y],out[y],-1);
               
            }
            else if(x==r){
                add(root,1,n,1);
            }
            else{
                 add(root,in[x],out[x],1);
            }
        }
        LL ans=0;
        for(int j=1;j<=m;j++)
        ans+=dp[k][j];
        printf("%lld\n",ans%mod);
        for(auto it:v){
            int x=it.y;
            if(in[x]<in[r]&&out[x]>=in[r]){
                int y=r;
                for(int i=19;i>=0;i--){
                    if(d[p[y][i]]>d[x])y=p[y][i];
                }
                add(root,1,n,-1);
                add(root,in[y],out[y],1);
            }
            else if(x==r){
                add(root,1,n,-1);
            }
            else{
                 add(root,in[x],out[x],-1);
            }
        }
    }
}