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
#define MXN 3000000
const int mod=998244353;
struct node{
    node *l,*r;
    LL pre,suf;
    LL sum;
    LL ans;
    LL Minpre;
    LL a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL){
        pre=suf=sum=ans=Minpre=0;
    }
}*root;
void pull(node *n){
    n->sum=n->l->sum+n->r->sum;
    n->pre=max(n->l->pre,n->l->sum+n->r->pre);
    n->suf=max(n->l->suf+n->r->sum,n->r->suf);
    n->ans=max(max(n->l->ans,n->r->ans),n->l->suf+n->r->pre);
    n->Minpre=min(n->l->Minpre,n->l->sum+n->r->Minpre);
}
void build(node *n,LL *a){
    if(n->a==n->b){
        n->sum=a[n->a];
        n->pre=n->suf=n->ans=max(a[n->a],0ll);
        n->Minpre=min(a[n->a],0ll);
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
node query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return *n;
    }
    if(n->b<l||n->a>r){
        return node(1,1);
    }
    node ll=query(n->l,l,r);
    node rr=query(n->r,l,r);
    node res(1,1);
    res.l=&ll;
    res.r=&rr;
    pull(&res);
    return res;
}
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    LL a[100005],b[100005];
    for(int i = 1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i = 1;i<=n;i++)scanf("%lld",&b[i]);
    for(int i = 1;i<=n;i++)b[i]-=a[i];
    root=new node(1,n);
    build(root,b);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        node n=query(root,l,r);
        if(n.sum!=0||n.Minpre<0){
            printf("-1\n");
        }
        else{
            printf("%lld\n",n.ans);
        }
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
*/