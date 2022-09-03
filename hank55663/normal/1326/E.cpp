#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long
#define ULL unsigned long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
    node *l,*r;
    int Max;
    int tag;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),Max(0),tag(0){

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
int main(){
    int n;
    scanf("%d",&n);
    int p[300005];
    int loc[300005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&p[i]);
        loc[p[i]]=i;
    }
    root = new node(1,n);
    build(root);
    add(root,1,loc[n],1);
    int now=n-1;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        while(Max(root)<=0){
            add(root,1,loc[now],1);
            now--;
        }
        printf("%d ",now+1);
        add(root,1,x,-1);
    }
    printf("\n");
}
/*

5
AACCMMAA
A
AA
MM
ACA
ACMAA


5
0 9 7 1 100
-1 0 -1 -1 91
-1 5 0 -1 96
-1 8 9 0 99
-1 -1 -1 -1 0
3 4
3 5
5 6
5 7
3 or 4
3 or 5
5 or 6
5 or 7

dp[x]=max(dp[x-w_i*j]+j*t_i-delta t_i*j*(j-1)/2)
dp[x]=max(dp[j]+x*t_i-j*t_i-delta t_i*(x-j)*(x-j-1)/2)
dp[x]=max(dp[j]-j*t_i-delta t_i *(j^2/2+j/2) - 
        delta t_i * xj + x*t_i + delta t_i * (x^2/2-x/2))
dp[x]=max(dp[j] + g(j) - delta t_i *xj + w(i) )
g(j)= dp[j]-j*t_i-delta t_i *(j^2/2+j/2)
w(i)=  x*t_i + delta t_i * (x^2/2-x/2)
x^2/2 -xj -x/2  +j^2/2 +j/2
*/

/*
 

*/