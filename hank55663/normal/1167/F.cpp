#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
struct node{
    node *l,*r;
    int a,b;
    int tag;
    LL sum;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),tag(0){
    }
}*root1,*root2;
int mod=1e9+7;
LL Sum(node *n){
    return (n->sum+(LL)n->tag*(n->b-n->a+1))%mod;
}
void pull(node *n){
    n->sum=Sum(n->l)+Sum(n->r);
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->l->tag%=mod;
    n->r->tag%=mod;
    n->tag=0;
}
void build(node *n){
    if(n->a==n->b){
        n->sum=0;
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
LL query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return Sum(n);
    }
    if(n->b<l||n->a>r)return 0;
    push(n);
    LL x=(query(n->l,l,r)+query(n->r,l,r))%mod;
    pull(n);
    return x;
}
int main(){
    int n;
    scanf("%d",&n);
    root1=new node(1,n);
    root2=new node(1,n);
    build(root1);
    build(root2);
    pii p[500005];
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        p[i]=mp(x,i);
    }
    sort(p+1,p+n+1);
    LL ans=0;
    for(int i = 1;i<=n;i++){
        LL ad = query(root1,p[i].y,p[i].y)*p[i].y%mod+query(root2,p[i].y,p[i].y)*(n-p[i].y+1)%mod;
        ad += (LL)p[i].y*(n-p[i].y+1)%mod;
      //  printf("%lld %d\n",ad,p[i].x);
      //  printf("!%lld %lld\n", query(root1,1,p[i].y),query(root2,p[i].y,n));
        ad%=mod;
        ans+=ad*p[i].x%mod;
        ans%=mod;
        add(root1,1,p[i].y,n-p[i].y+1);
        add(root2,p[i].y,n,p[i].y);
    }
    printf("%lld\n",ans);
}