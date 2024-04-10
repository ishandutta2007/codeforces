#include<bits/stdc++.h>
#pragma optimizer(O2)
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
vector<int> v[100005];
pii p[100005];
int pre[100005];
int val[100005];
const int mod=1e9+7;
struct node{
    node *l,*r;
    int a,b;
    int sum;
    int x;
    int tot;
    int tag;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL){
        sum=0;
        x=0;
        tot=(pre[b]-pre[a-1]+mod)%mod;
        tag=0;
    }
};
 
LL Sum(node *n){
    LL tag=(n->tag);
    return ((n->tot*tag - (n->x*tag<<1) - tag*tag%mod*(n->b-n->a+1) + n->sum)%mod+mod)%mod;
}
 
LL x(node *n){
     LL tag=(n->tag);
    return (tag*(n->b-n->a+1)+n->x)%mod;
}
void pull(node *n){
    n->sum=(Sum(n->l)+Sum(n->r))%mod;
    n->x=(x(n->l)+x(n->r))%mod;
   // n->tot=(n->l->tot+n->r->tot)%mod;
}
void push(node *n){
    if(!n->l)n->l=new node(n->a,(n->a+n->b)/2);
    if(!n->r)n->r=new node((n->a+n->b)/2+1,n->b);
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->l->tag%=mod;
    n->r->tag%=mod;
    n->tag=0;
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        n->tag%=mod;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int Size[100005];
bool cmp(const int &x,const int &y){
    return Size[x]<Size[y];
}
void dfs(int x,int f){
    int sum=1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            sum+=Size[it];
        }
    }
    sort(v[x].begin(),v[x].end(),cmp);
    Size[x]=sum;
}
void erase(node *n){
    if(n){
        erase(n->l);
        erase(n->r);
        delete n;
    }
}
LL ans=0;
void dfs3(int x,int f,node *n){
    add(n,p[x].x,p[x].y,val[x]);
    for(auto it:v[x]){
        if(it!=f){
            dfs3(it,x,n);
        }
    }
}
node* dfs2(int x,int f){
    if(v[x].size()==1&&f!=0){
        node *n=new node(1,1e5);
        add(n,p[x].x,p[x].y,val[x]);
        ans+=Sum(n);
        ans%=mod;
      //  vector<int> tmp;
       // tmp.pb(x);
        return n;
    }
    node *n=dfs2(v[x].back(),x);
    int tt=v[x].back();
    v[x].pop_back();
    for(auto it:v[x]){
        if(it!=f){
            auto pp=dfs2(it,x);
            erase(pp);
            dfs3(it,x,n);
        }
    }
    v[x].pb(tt);
    add(n,p[x].x,p[x].y,val[x]);
    ans+=Sum(n);
  //  printf("%d %lld\n",x,Sum(n));
    ans%=mod;
    return n;
}
int main(){
    int n;
    scanf("%d",&n);
    LL sum=1;
    for(int i=  1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        sum=sum*(y-x+1)%mod;
        val[i]=f_pow(y-x+1,mod-2);
        pre[x]=(pre[x]+f_pow(y-x+1,mod-2))%mod;
        pre[y+1]=(pre[y+1]-f_pow(y-x+1,mod-2)+mod)%mod;
    }
    for(int t=0;t<2;t++)
    for(int i = 1;i<=100000;i++){
        pre[i]+=pre[i-1];
        pre[i]%=mod;
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    dfs2(1,0);
    printf("%lld\n",ans*sum%mod);
}