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
    node *l,*r;
    int a,b;
    int tag;
    int Max,Min;
    node(int _a,int _b):a(_a),b(_b),tag(0),Max(0),Min(1e9),l(NULL),r(NULL){

    }
}*root;
int Min(node *n){
    return n->Min+n->tag;
}
int Max(node *n){
    return n->Max+n->tag;
}
void pull(node *n){
    n->Min=min(Min(n->l),Min(n->r));
    n->Max=max(Max(n->l),Max(n->r));
}
void push(node *n){
    if(!n->l){
        int mid=(n->a+n->b)/2;
        n->l=new node(n->a,mid);
        n->r=new node(mid+1,n->b);
        n->l->Min=n->a;
        n->l->Max=mid;
        n->r->Min=mid+1;
        n->r->Max=n->b;
    }
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void add(node *n,int k){
    if(Max(n)<k){
        n->tag++;
        return;
    }
    if(Min(n)>k){
        n->tag--;
        return;
    }
    if(Min(n)==k&&Max(n)==k){
        return;
    }
    push(n);
    add(n->l,k);
    add(n->r,k);
    pull(n);
}
int query(node *n,int k){
    if(!n)return k;
    int mid=(n->a+n->b)/2;
   // printf("%d %d %d\n",n->a,n->b,n->tag);
    if(k<=mid)return query(n->l,k)+n->tag;
    else return query(n->r,k)+n->tag;
}
void solve(){
    int n;
    scanf("%d",&n);
    root=new node(0,1000000000);
    root->Max=1000000000;
    root->Min=0;
    int last=0;
    for(int i = 0;i<n;i++){
        int t;
        scanf("%d",&t);
        add(root,t);
        int k;
        scanf("%d",&k);
        while(k--){
            int x;
            scanf("%d",&x);
            x=(x+last)%(1000000001);
            printf("%d\n",last=query(root,x));
        }
    }
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