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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
#define MXN 2000005
vector<int> v[150005];
vector<int> vB[150005];
int block=1000;
int Size[150005];
int in[150005];
int out[150005];
int p[150005];
int mod=998244353;
int val[150005];
struct node{
    node *l,*r;
    int a,b;
    LL tag;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),tag(0){
 
    }
}*root;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void push(node *n){
    n->l->tag+=n->tag;
    n->l->tag%=mod;
    n->r->tag+=n->tag;
    n->r->tag%=mod;
    n->tag=0;
}
void build(node *n){
    if(n->a==n->b){
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void add(node *n,int l,int r,LL k){
    if(l>r)return ;
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        n->tag%=mod;
        return ;
    }
    if(n->b<l||n->a>r)return ;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
}
LL query(node *n,int x){
    if(n->a==n->b)return n->tag;
    int mid=(n->a+n->b)/2;
    push(n);
    if(x<=mid)return query(n->l,x);
    else return query(n->r,x);
}
int t;
void dfs(int x,int f){
    in[x]=++t;
    Size[x]=1;
    p[x]=f;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
            if(Size[it]>block){
                vB[x].pb(it);
            }
        }
    }
    out[x]=t;
}
LL inv;
LL go(int v){
    if(v==0)return 0;
   // printf("%d\n",v);
    if(Size[v]>block)return 0;
    return val[p[v]]*inv%mod*Size[v]%mod+go(p[v]);
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    inv=f_pow(n,mod-2);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    root=new node(1,n);
    build(root);
    dfs(1,0);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            LL v,d;
            scanf("%lld %lld",&v,&d);
            add(root,in[v],out[v],d);
            //add(root,in[v],out[v],d*f_pow(n,mod-2)%mod*(n-Size[v]));
            add(root,1,in[v]-1,d*inv%mod*(Size[v])%mod);
            add(root,out[v]+1,n,d*inv%mod*(Size[v])%mod);
            val[v]+=d;
            val[v]%=mod;
            for(auto it:vB[v]){
                add(root,in[it],out[it],(mod-d*inv%mod*(Size[it])%mod)%mod);
            }
        }
        else{
            int v;
            scanf("%d",&v);
          //  printf("%d\n",v);
            printf("%lld\n",((query(root,in[v])-go(v))%mod+mod)%mod);
        }
    }
    return 0;
}