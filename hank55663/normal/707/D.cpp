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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define MXN 200005
const int mod=1e9+7;
struct node{
    node *l,*r;
    int a,b;
    int sum;
    int tag;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),sum(0),tag(0){}
}*root[100005];
int Sum(node *n){
    return n->tag?n->b-n->a+1-n->sum:n->sum;
}
void pull(node *n){
    n->sum=Sum(n->l)+Sum(n->r);   
}
node* Clone(node *n){
    node *res=new node(n->a,n->b);
    res->l=n->l;
    res->r=n->r;
    res->sum=n->sum;
    res->tag=n->tag;
    return res;
}
void push(node *n){
    n->l=Clone(n->l);
    n->r=Clone(n->r);
    n->l->tag^=n->tag;
    n->r->tag^=n->tag;
    n->tag=0;
}
void build(node *n){
    if(n->a==n->b)return ;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void rever(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        //printf("%d %d\n",n->a,n->b);
        n->tag^=1;
        return ;
    }
    if(n->b<l||n->a>r)return ;
    push(n);
    rever(n->l,l,r);
    rever(n->r,l,r);
    pull(n);
}
void revise(node *n,int x,int k){
    if(n->a==n->b){
        n->tag=0;
        n->sum=k;
   //     printf("%d %d %d\n",n->a,n->b,Sum(n));
        return ;
    }
    int mid=(n->a+n->b)/2;
    push(n);
    if(x<=mid)
    revise(n->l,x,k);
    else 
    revise(n->r,x,k);
    pull(n);
    //printf("%d %d %d\n",n->a,n->b,Sum(n));
}
int main(){ 
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    root[0]=new node(0,n*m-1);
    build(root[0]);
    for(int i = 1;i<=q;i++){
        int op;
        scanf("%d",&op);
        if(op==1){
            root[i]=Clone(root[i-1]);
            int x,y;
            scanf("%d %d",&x,&y);
            x--,y--;
            revise(root[i],x*m+y,1);
        }
        else if(op==2){
            root[i]=Clone(root[i-1]);
            int x,y;
            scanf("%d %d",&x,&y);
            x--,y--;
           // printf("%d\n",x*m+y);
            revise(root[i],x*m+y,0);
        }
        else if(op==3){
            root[i]=Clone(root[i-1]);
            int x;
            scanf("%d",&x);
            x--;
           // printf("%d %d\n",x*m,(x+1)*m-1);
            rever(root[i],x*m,(x+1)*m-1);
        }
        else{
            int k;
            scanf("%d",&k);
            root[i]=root[k];
        }
        printf("%d\n",Sum(root[i]));
    }
}
/*
1 2 2 3 3 3 4
2 2 1
3 2 3
4 2 4 4 7
 
1 1
*/