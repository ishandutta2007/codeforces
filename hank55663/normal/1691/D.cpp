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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
struct node{
    node *l,*r;
    LL pre,suf;
    LL sum;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),pre(0),suf(0),sum(0){

    }
}*root;
void pull(node *n){
    n->sum=n->l->sum+n->r->sum;
    if(n->sum<-1e18)n->sum=-1e18;
    n->suf=max(n->r->suf,n->r->sum+n->l->suf);
    n->pre=max(n->l->pre,n->l->sum+n->r->pre);
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->sum=a[n->a];
        if(a[n->a]>=0){
            n->pre=n->suf=a[n->a];
        }
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
void revise(node *n,int k){
    if(n->a==n->b){
        n->sum=-1e18;
        n->pre=n->suf=0;
        return;
    }
    int mid=(n->a+n->b)/2;
    if(k<=mid)revise(n->l,k);
    else revise(n->r,k);
    pull(n);
}
node query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r)return *n;
    if(n->b<l||n->a>r)return node(0,0);
    int mid=(n->a+n->b)/2;
 //   if(r<=mid)return query(n->l,l,r);
 //   if(l>mid)return query(n->r,l,r);
    node a=query(n->l,l,r);
    node b=query(n->r,l,r);
    node res(0,0);
    res.l=&a;
    res.r=&b;
    pull(&res);
   // printf("%d %d\n",res.pre,res.suf);
    return res;
}
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    vector<pii> v;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        v.pb(mp(a[i],i));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    root=new node(1,n);
    build(root,a);
    for(auto it:v){
        if(it.y!=1){
         //   printf("?%d? ",query(root,1,it.y-1).suf);
            if(query(root,1,it.y-1).suf>0){
                printf("No\n");
                return;
            }
        }
        if(it.y!=n){
          //  printf("%d ",query(root,it.y+1,n).pre);
            if(query(root,it.y+1,n).pre>0){
                printf("No\n");
                return;
            }
        }
      //  printf("\n");
        revise(root,it.y);
    }
    printf("Yes\n");
}

int main(){
    srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}