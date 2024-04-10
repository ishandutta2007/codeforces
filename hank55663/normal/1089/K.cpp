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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
struct node{
    node *l,*r;
    LL Max;
    int a,b;
    LL sum;
    LL tag;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){
        sum=0;
        tag=0;
    }
}*root;
LL Max(node *n){
    return n->Max+n->tag;
}
void pull(node *n){
    n->Max=max(Max(n->l),Max(n->r));
    n->sum=n->l->sum+n->r->sum;
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void build(node *n){
    if(n->a==n->b){
        n->Max=n->a;
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
        return ;
    }
    if(n->b<l||n->a>r){
        return;
    }
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
void add(node *n,int x,int k){
    if(n->a==n->b){
        n->sum+=k;
        return ;
    }
    int mid=(n->a+n->b)/2;
    push(n);
    if(x<=mid)add(n->l,x,k);
    else add(n->r,x,k);
    pull(n);
}
LL queryMax(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return Max(n);
    }
    if(n->b<l||n->a>r)return 0;
    push(n);
    LL res=max(queryMax(n->l,l,r),queryMax(n->r,l,r));
    pull(n);
    return res;
}
LL querysum(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return n->sum;
    }
    if(n->b<l||n->a>r)return 0;
    push(n);
    LL res=querysum(n->l,l,r)+querysum(n->r,l,r);
    pull(n);
    return res;
}
int main(){
    int q;
    scanf("%d",&q);
    vector<pii> v;
    v.pb(mp(0,0));
    root = new node(1,1000000);
    build(root);
    while(q--){
        char c;
        scanf(" %c",&c);
        if(c=='+'){
            int t,d;
            scanf("%d %d",&t,&d);
            v.pb(mp(t,d));
            add(root,t,1000000,-d);
            add(root,t,d);
        }
        else if(c=='-'){
            int x;
            scanf("%d",&x);
            int t,d;
            tie(t,d)=v[x];
            add(root,t,1000000,d);
            add(root,t,-d);
            v.pb(mp(0,0));
        }
        else{
            int x;
            scanf("%d",&x);
            v.pb(mp(0,0));
            LL Max=max(queryMax(root,1,x-1),0ll);
            LL Sum=querysum(root,1,x);
          //  printf("%d %lld\n",Max,Sum);
            printf("%lld\n",Max+Sum+1-x);
        }
    }
}