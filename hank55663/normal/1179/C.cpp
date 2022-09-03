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
#define MEM(x) memset(x,0,sizeof(x)
struct node{
    node *l,*r;
    int a,b;
    int Max;
    int tag;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL){
        Max=0;
        tag=0;
    }
}*root;
int Max(node *n){
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
void build(node *n){
    if(n->a==n->b){
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void revise(node *n,int l,int r,int k){
    if(n==root){
     //   printf("%d %d %d\n",l,r,k);
    }
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    revise(n->l,l,r,k);
    revise(n->r,l,r,k);
    pull(n);
}
int query(node *n){
    if(n->a==n->b){
        return n->a;
    }
    push(n);
    int res;
    if(Max(n->r)>0){
        res=query(n->r);
    }
    else{
        res=query(n->l);
    }
    pull(n);
    return res;
}
int main(){
    root=new node(1,1000000);
    build(root);
    int n,m;
    scanf("%d %d",&n,&m);
    int a[300005];
    int b[300005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        revise(root,1,a[i],1);
    }
    for(int i = 1;i<=m;i++){
        scanf("%d",&b[i]);
        revise(root,1,b[i],-1);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int op,i,x;
        scanf("%d %d %d",&op,&i,&x);
        if(op==1){
            revise(root,1,a[i],-1);
            a[i]=x;
            revise(root,1,a[i],1);
            if(Max(root)<=0){
                printf("-1\n");
            }
            else{
                printf("%d\n",query(root));
            }
        }
        else{
            revise(root,1,b[i],1);
            b[i]=x;
            revise(root,1,b[i],-1);
            if(Max(root)<=0){
                printf("-1\n");
            }
            else{
                printf("%d\n",query(root));
            }
        }
    }
}
/*
m3->m2->m->m4
0 1 2 3 453*
0 1 3 2 4 4 2
0 1 4 2 3 3 2
0 2 1 3 4
0 2 3 1 4 4 1
0 2 4 1 3 3 1
0 3 1 2 4 4 2
0 3 2 1 4 4 1
0 4 1 
0 4 2
0 4 3

*/