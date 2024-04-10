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
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
struct node{
    node *l,*r;
    int a,b;
    LL tag;
    LL Max;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Max(0),tag(0){

    }
}*root;
LL Max(node *n){
    return n->Max+n->tag;
}
void pull(node *n){
    n->Max=max(Max(n->l),Max(n->r));
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void build(node *n,LL *v){
    if(n->a==n->b){
        n->Max=-v[n->a];
      //  printf("%d %d %d\n",n->a,n->b,n->Max);
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,v);
    build(n->r,v);
    pull(n);
 //   printf("%d %d %d\n",n->a,n->b,n->Max);
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return ;
    }
    if(n->b<l||n->a>r)return ;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
LL a[1000005],b[1000005];
int main(){
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    fill(a,a+1000005,1e18);
    fill(b,b+1000005,1e18);
    LL aa=1e18,bb=1e18;
    for(int i = 0;i<n;i++){
        LL x,y;
        scanf("%lld %lld",&x,&y);
        a[x]=min(a[x],y);
        aa=min(aa,y);
    }
    for(int i = 0;i<m;i++){
        LL x,y;
        scanf("%lld %lld",&x,&y);
        b[x]=min(b[x],y);
        bb=min(bb,y);
    }
    vector<pair<int,pii> > v;
    for(int i = 0;i<p;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        v.pb(mp(x,mp(y,z)));
    }
    sort(v.begin(),v.end());
    root = new node(1,1000000);
    build(root,b);
    int now=0;
    LL ans=-aa-bb;
  //  printf("%d\n",vb.size());
    for(int i = 1;i<=1000000;i++){
        while(now!=v.size()&&v[now].x<i){
            if(v[now].y.x!=1000000){
                add(root,v[now].y.x+1,1000000,v[now].y.y);
            }
            now++;
        }
        ans=max(ans,Max(root)-a[i]);
    }
    printf("%lld\n",ans);
}