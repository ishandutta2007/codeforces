#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
    node *l,*r;
    int a,b;
    LL sum;
    LL Min;
    LL tag;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL){
        sum=0;
        Min=0;
        tag=0;
    }
}*root;
LL sum(node *n){
    if(n->tag){
        return n->tag*(n->b-n->a+1);
    }
    else{
        return n->sum;
    }
}
LL Min(node *n){
    if(n->tag)return n->tag;
    return n->Min;
}
void pull(node *n){
    n->sum=sum(n->l)+sum(n->r);
    n->Min=min(Min(n->l),Min(n->r));
}
void push(node *n){
    if(n->tag){
        n->l->tag=n->tag;
        n->r->tag=n->tag;
        n->tag=0;
    }
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Min=n->sum=a[n->a];
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
void revise(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag=k;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    revise(n->l,l,r,k);
    revise(n->r,l,r,k);
    pull(n);
}
int query1(node *n,LL x){
    if(n->a==n->b)return n->a;
    push(n);
    int res;
    if(Min(n->l)<=x)res=query1(n->l,x);
    else res=query1(n->r,x);
    pull(n);
    return res;
}
pll query2(node *n,LL x){
    if(n->a==n->b)return mp(n->a,x);
    push(n);
    pll res;
    if(sum(n->l)<=x)x-=sum(n->l),res=query2(n->r,x);
    else res=query2(n->l,x);
    pull(n);
    return res;
}
LL query3(node *n,int k){
    if(k==0)return 0;
    if(n->a==n->b)return sum(n);
    push(n);
    LL res=0;
    int mid=(n->a+n->b)/2;
    if(k<=mid)res+=query3(n->l,k);
    else res+=query3(n->r,k)+sum(n->l);
    pull(n);
    return res;
}
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    int a[200005];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    a[n+1]=0;
    root=new node(1,n+1);
    build(root,a);
    while(q--){
        int t;
        scanf("%d",&t);
        if(t==1){
            int x,y;
            scanf("%d %d",&x,&y);
            int res=query1(root,y);
            if(res<=x){
                revise(root,res,x,y);
            }
        }
        else{
            int ans=0;
            LL x,y;
            scanf("%lld %lld",&x,&y);
            int now=x;
            while(now!=n+1){
                y+=query3(root,now-1);
                pll p=query2(root,y);
                ans+=p.x-now;
                if(p.x==n+1){
                    break;
                }
                assert(ans<=n);
                now=query1(root,p.y);
                y=p.y;
            }
            printf("%d\n",ans);
        }
    }
}

int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}