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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
struct node{
    node *l,*r;
    int a,b;
    int tag;
    int Max;
    node(int _a,int _b):l(NULL),r(NULL),tag(0),Max(0),a(_a),b(_b){

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
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void add(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        n->tag++;
        return ;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r);
    add(n->r,l,r);
    pull(n);
}
int query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r)return Max(n);
    if(n->b<l||n->a>r)return 0;
    push(n);
    int res=max(query(n->l,l,r),query(n->r,l,r));
    pull(n);
    return res;
}
int last[400005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int ans=n;
    root=new node(1,n);
    build(root);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(last[x]==0){
            last[x]=i;
        }
        else{
            if(last[x]==i-1||query(root,last[x]+1,i-1)<k-1){
                ans--;
                add(root,last[x]+1,i-1);
            }
            last[x]=i;
        }
    }
    printf("%d\n",ans);
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/