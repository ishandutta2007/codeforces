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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
struct node{
    node *l,*r;
    int a,b;
    LL Max;
    LL tag;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Max(){
        tag=0;
    }
}*root;
LL Max(node *n){
    return n->Max+n->tag;
}
void pull(node *n){
    n->Max=min(Max(n->l),Max(n->r));
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
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
void add(node *n,int l,int r,int k){
    if(l>r)return;
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return ;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
int main(){
    int n;
    scanf("%d",&n);
    root = new node(1,n-1);
    build(root);
    int p[200005],loc[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&p[i]);
        loc[p[i]]=i;
    }
    int a[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        add(root,i,n-1,a[i]);
        //add(i,a[i]);
    }
    LL ans=a[1];
    for(int i = 1;i<=n;i++){
        add(root,loc[i],n-1,-a[loc[i]]);
        add(root,1,loc[i]-1,a[loc[i]]);
        ans=min(ans,Max(root));
    }
    printf("%lld\n",ans);
}