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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
struct node{
    node *l,*r;
    int a,b;
    LL sum;
    int tag;
    pii Max;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){
        sum=0;
        tag=0;
        Max=mp(0,0);
    }
}*root[100005],*root2;
LL Sum(node *n){
    return n->sum+n->tag*1ll*(n->b-n->a+1);
}
void pull(node *n){
    n->sum=Sum(n->l)+Sum(n->r);
    n->Max=max(n->l->Max,n->r->Max);
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
node *Clone(node *a){
    node *res=new node(a->a,a->b);
    res->l=a->l;
    res->r=a->r;
    res->sum=a->sum;
    res->tag=a->tag;
    return res;
}
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Max=mp(a[n->a],n->a);
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
void add(node *n,int l,int r,int k){
    if(l>r)return;
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return;
    }
    if(n->b<l||n->a>r)return;
    
    n->l=Clone(n->l);
    n->r=Clone(n->r);
    push(n);
    add(n->l,l,r,k);
 
    add(n->r,l,r,k);
    pull(n);
}
pii query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return n->Max;
    }
    if(n->b<l||n->a>r)return mp(0,0);
    return max(query(n->l,l,r),query(n->r,l,r));
}
bool solve(){
    int n=7;
    scanf("%d",&n);
    int a[100005];
    root[n] = new node(1,n);
    build(root[n]);

    vector<pii> stk;
    for(int i = 1;i<=n-1;i++){
       scanf("%d",&a[i]);
    }
    root2=new node(1,n);
    build(root2,a);
    LL ans=0;
    LL res[100005];
    for(int i = n-1;i>=1;i--){
        if(a[i]!=n){
            
            pii x=query(root2,i,a[i]);
            swap(x.x,x.y);
           // root[i]=Clone(root[x.x]);
            res[i]=res[x.x];
            res[i]+=n-i;
            res[i]-=a[i]-x.x;
          //  add(root[i],i+1,n,1);
           // add(root[i],x.x+1,a[i],-1);
        }
        else{
            res[i]=n-i;
            //root[i]=Clone(root[n]);
            //add(root[i],i+1,n,1);
        }
        ans+=res[i];//Sum(root[i]);
    }
    printf("%lld\n",ans);
    return true;
}
int main(){
    int t=1;;
    while(t--)solve();
}