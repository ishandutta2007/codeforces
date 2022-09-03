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
int a[1000005];
LL val[1000005];
struct node{
    node *l,*r;
    LL add;
    int ass;
    int same;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),same(0),add(0),ass(0),l(NULL),r(NULL){

    };
}*root;
int same(node *n){
    return n->ass?n->ass:n->same;
}
void pull(node *n){
    if(same(n->l)==same(n->r)){
        n->same=same(n->l);
    }
    else n->same=0;
}
void push(node *n){
    n->l->add+=n->add;
    n->r->add+=n->add;
    n->add=0;
    if(n->ass){
        n->l->ass=n->ass;
        n->r->ass=n->ass;
        n->ass=0;
    }
}
void build(node *n){
    if(n->a==n->b){
        n->same=1;
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void revise(node *n,int l,int r,int c){
    if(n->a>=l&&n->b<=r&&same(n)){
        n->add+=val[same(n)];
        n->ass=c;
        n->add-=val[c];
        return;
    }
    if(n->b<l||n->a>r)return ;
    push(n);
    revise(n->l,l,r,c);
    revise(n->r,l,r,c);
    pull(n);
}
LL query(node *n,int x){
    if(n->a==n->b){
        
        return n->add+val[same(n)];
    }
    int mid=(n->a+n->b)/2;
    push(n);
    LL res;
    if(x<=mid)res=query(n->l,x);
    else res=query(n->r,x);
    pull(n);
    return res;
}
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    root=new node(1,n);
    build(root);
    while(q--){
        char c[10];
        scanf("%s",c);
        if(c[0]=='C'){
            int l,r,cc;
            scanf("%d %d %d",&l,&r,&cc);
            revise(root,l,r,cc);
        }
        else if(c[0]=='A'){
            int a,b;
            scanf("%d %d",&a,&b);
            val[a]+=b;
        }
        else{
            int x;
            scanf("%d",&x);
            printf("%lld\n",query(root,x));
        }
    }
}
int main(){
    int t=1;0000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}