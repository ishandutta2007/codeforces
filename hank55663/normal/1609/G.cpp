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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
    node *l,*r;
    LL ans;
    LL add;
    LL sum;
    LL Max;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),add(0),sum(0),ans(0),Max(0){

    }
}*root;
LL Sum(node *n){
    return n->sum+n->add*(n->b-n->a+1);
}
LL ans(node *n){
    LL tot=n->b-n->a+1;
    return n->ans+n->add*(tot)*(tot+1)/2;
}
LL Max(node *n){
    return n->Max+n->add;
}
void pull(node *n){
    n->ans=ans(n->l)+ans(n->r)+Sum(n->l)*(n->r->b-n->r->a+1);
    n->sum=Sum(n->l)+Sum(n->r);
    n->Max=max(Max(n->l),Max(n->r));
}
void push(node *n){
    n->l->add+=n->add;
    n->r->add+=n->add;
    n->add=0;
}
void build(node *n,LL *b){
    if(n->a==n->b){
        n->sum=n->Max=n->ans=b[n->a];
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,b);
    build(n->r,b);
    pull(n);
   // printf("%d %d %d\n",n->a,n->b,n->ans);
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->add+=k;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
pll query(node *n,int k){
    if(n->a==n->b){
        if(Sum(n)<=k)return mp(n->a,Sum(n));
        return mp(n->a-1,0);
    }
    push(n);
    pll res;
    if(Max(n->l)<=k){
        res= query(n->r,k);
        res.y+=Sum(n->l);
    }
    else res=query(n->l,k);
    pull(n);
    return res;
}
void solve(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    LL a[105],b[100005];
    for(int i = 0;i<n;i++)scanf("%lld",&a[i]);
    for(int i = 0;i<m;i++)scanf("%lld",&b[i]);
    for(int i = n-1;i>=1;i--)a[i]-=a[i-1];
    for(int i = m-1;i>=1;i--)b[i]-=b[i-1];
    /*for(int i = 0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    for(int i = 0;i<m;i++)printf("%d ",b[i]);
    printf("\n");*/
    root=new node(1,m-1);
    build(root,b);
    while(q--){
        int t,k,d;
        scanf("%d %d %d",&t,&k,&d);
        if(t==1){
            //if(k==n)a[0]+=d;
            for(int i = n-k;i<n;i++)a[i]+=d;
        }
        else{
            if(k==m)b[0]+=d;
            add(root,m-k,m-1,d);
        }
        LL res=(a[0]+b[0])*(n+m-1);//+ans(root);
        //printf("%lld %lld\n",res,root->add);
        res+=ans(root);
       //  printf("%lld\n",res);
        for(int i = 1;i<n;i++){
            res+=a[i]*(n-i);
            pll p=query(root,a[i]);
            res+=p.y+(m-1-p.x)*a[i];
           //  printf("%lld ",res);
        }
        printf("%lld\n",res);
    }
}
int main(){
    int t=1;0000;
  //  scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/