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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 300005
#define index Index
struct node{
    node *l,*r;
    int a,b;
    int Min;
    int tag;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),tag(0){

    }
}*root;
int Min(node *n){
    return n->Min+n->tag;
}
void pull(node *n){
    n->Min=min(Min(n->l),Min(n->r));
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Min=a[n->a];
        return;
    }
    //printf("%d %d\n",n->a,n->b);
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
void revise(node *n,int l,int r,int k){
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
int query(node *n,int l,int r){
    if(l==0||r==0){
        return 1e9;
    }
    if(n->a>=l&&n->b<=r){
        return Min(n);
    }
    if(n->b<l||n->a>r)return 1e9;
    push(n);
    int res=min(query(n->l,l,r),query(n->r,l,r));
    pull(n);
    return res;
}
int main(){
    char c[100005];
    scanf("%s",c+1);
    int a[100005];
    a[0]=0;
    for(int i = 1;c[i]!=0;i++){
        if(c[i]=='1')
        a[i]=a[i-1]+1;
        else
        a[i]=a[i-1]-1;
    }
    int n=strlen(c+1);
    root=new node(1,n);
    //printf("?\n");
    build(root,a);
    //printf("!\n");
    for(int i = 1;c[i]!=0;i++){
        if(c[i]=='1'){
          //  printf("%d %d %d %d\n",query(root,1,i-1),query(root,i-1,i-1),query(root,i,n),query(root,i,i));
            if(query(root,1,i-1)>=query(root,i-1,i-1)&&query(root,i,n)>=query(root,i,i)){
                c[i]='0';
                revise(root,i,n,-2);
            }
        }
    }
    printf("%s\n",c+1);
}

/*
7
A B son of C
A C son of D
A D son of B
A E son of B
A F son of C
A G son of D
A H son of E
*/