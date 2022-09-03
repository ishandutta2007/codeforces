#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define N 200005
#define less Less
struct node{
    node *l,*r;
    int a,b;
    int tag;
    int Min;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){
        tag=0;
        Min=0;
    }
}*root;
int Min(node *n){
    return n->tag?n->tag:n->Min;
}
void pull(node *n){
    n->Min=min(Min(n->l),Min(n->r));
}
node *clone(node *n,int l){
    node *ret = new node(l,n->b-n->a+l);
    ret->l=n->l;
    ret->r=n->r;
    ret->Min=n->Min;
    ret->tag=n->tag;
    return ret;
}
void push(node *n){
    n->l=clone(n->l,n->a);
    n->r=clone(n->r,(n->a+n->b)/2+1);
    if(n->tag){
        n->l->tag=n->tag;
        n->r->tag=n->tag;
        n->tag = 0;
    }
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Min=a[n->a];
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
int query(node *n,int l,int r){
   // printf("%d %d %d\n",n->a,n->b,Min(n));
    if(n->a>=l&&n->b<=r){
        return Min(n);
    }
    if(n->b<l||n->a>r){
        return 1e9+1;
    }
    push(n);
    int res=min(query(n->l,l,r),query(n->r,l,r));
    pull(n);
    return res;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[100005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    root = new node(1,n);
    build(root,a);
    for(int i = 1;i<k;i<<=1){
        node *temp=new node(1,root->b*2);
        temp->l=root;
        temp->r=root;
        pull(temp);
        root=temp;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int op,l,r;
        scanf("%d %d %d",&op,&l,&r);
        if(op==1){
            int x;
            scanf("%d",&x);
            revise(root,l,r,x);
        }
        else{
            printf("%d\n",query(root,l,r));
        }
    }
}