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
    LL sum;
    LL tag,add,ass;
    int a,b;
    node *l,*r;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),sum(0),tag(-1),add(0),ass(-1){

    }
}*root;
const int mod=998244353;
LL Sum(node *n){
    if(n->ass!=-1)return ((n->ass*(n->b-n->a+1)*n->tag+n->add*(n->b-n->a+1))%mod+mod)%mod;
    return ((n->sum*n->tag+n->add*(n->b-n->a+1))%mod+mod)%mod;
}
void pull(node *n){
    n->sum=(Sum(n->l)+Sum(n->r))%mod;
}
void push(node *n){
    if(!n->l){
        int mid=(n->a+n->b)/2;
        n->l=new node(n->a,mid);
        n->r=new node(mid+1,n->b);
    }
    if(n->ass!=-1){
        n->l->tag=1;
        n->r->tag=1;
        n->l->add=0;
        n->r->add=0;
        n->l->ass=n->ass;
        n->r->ass=n->ass;
    }
   // else{
    n->l->tag*=n->tag;
    n->l->add*=n->tag;
  /*  if(n->l->ass!=-1){
        n->l->ass*=n->tag;
        n->l->ass=(n->l->ass%mod+mod)%mod;
    }*/

    n->l->add+=n->add;
    n->l->add=(n->l->add%mod+mod)%mod;
     n->r->tag*=n->tag;
      /*if(n->r->ass!=-1){
        n->r->ass*=n->tag;
        n->r->ass=(n->r->ass%mod+mod)%mod;
    }*/
    n->r->add*=n->tag;
    n->r->add+=n->add;
        n->r->add=(n->r->add%mod+mod)%mod;
   // }
    n->add=0;
    n->tag=1;
    n->ass=-1;
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->add+=k;
        n->add%=mod;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
void ass(node *n,int l,int r,int k){
    if(l>r)return;
     if(n->a>=l&&n->b<=r){
        n->ass=k;
        n->tag=1;
        n->add=0;
        //n->add%=mod;
        return;
    }
    if(n->b<l||n->a>r)return;
   // printf("%d %d\n",n->tag,n->add);
    push(n);
   // printf("!%d %d %d\n",n->l->sum,n->l->tag,n->l->add);
    ass(n->l,l,r,k);
    ass(n->r,l,r,k);
    pull(n);
    //printf("%d %d %d\n",n->a,n->b,Sum(n));
}
void tag(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag*=k;
        n->tag%=mod;
        n->add*=k;
        n->add%=mod;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    tag(n->l,l,r,k);
    tag(n->r,l,r,k);
    pull(n);
}
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    root=new node(1,1000000000);
    ass(root,1,a[0],1);
    for(int i = 1;i<n;i++){
       
       // printf("%lld\n",Sum(root));
        LL sum=(Sum(root)%mod+mod)%mod;
         tag(root,1,1000000000,-1);
     //    printf("%lld\n",Sum(root));
        add(root,1,1000000000,sum);
     //   printf("%lld\n",Sum(root));
        ass(root,a[i]+1,1000000000,0);
     //   printf("%lld\n",Sum(root));
    }
    printf("%lld\n",Sum(root));
}
int main(){
    int t=1;0000;
   // scanf("%d",&t);
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