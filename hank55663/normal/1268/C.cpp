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
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> set_t;
set_t s;
struct treap{
    treap *l,*r;
    LL tag;
    LL sum;
    int val;
    int index;
    int Size;
    treap(int _index):val(0),index(_index),tag(0),sum(0),l(NULL),r(NULL),Size(1){

    }
}*root;
LL Sum(treap *n){
    return n?n->sum+n->Size*n->tag:0;
}
int Size(treap *n){
    return n?n->Size:0;
}
void push(treap *n){
    if(n->l){
        n->l->tag+=n->tag;
    }
    if(n->r){
        n->r->tag+=n->tag;
    }
    n->val+=n->tag;
    n->tag=0;
}
void pull(treap *n){
    n->Size=Size(n->l)+Size(n->r)+1;
    n->sum=Sum(n->l)+Sum(n->r)+n->val;
}
treap *merge(treap *l,treap *r){
    if(!l||!r)return l?l:r;
    if(rand()%(Size(l)+Size(r))<Size(l)){
        push(l);
        l->r=merge(l->r,r);
        pull(l);
        return l;
    }
    else{
        push(r);
        r->l=merge(l,r->l);
        pull(r);
        return r;
    }
}
void split(treap *t,int k,treap *&l,treap *&r){
    if(!t){
        l=r=NULL;
        return;
    }
    push(t);
    if(t->index<k){
        l=t;
        split(t->r,k,l->r,r);
        pull(l);
    }
    else{
        r=t;
        split(t->l,k,l,r->l);
        pull(r);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        root = merge(root,new treap(i));
    }
    int loc[200005];
    for(int i = 1;i<=n;i++){
        int x=n-i+1;
        scanf("%d",&x);
        loc[x]=i;
    }
    int Min=1e9,Max=0;
    LL ans=0;
    for(int i = 1;i<=n;i++){
        Min=min(Min,loc[i]);
        Max=max(Max,loc[i]);
        treap *l,*r;
        split(root,loc[i],l,root);
        split(root,loc[i]+1,root,r);
        ans+=Sum(root);
        s.insert(loc[i]);
        int x=*s.find_by_order(i/2);
        if(l)
        l->tag++;
        root=merge(l,r);
        treap *tmp;
        split(root,Min,l,root);
        split(root,x,tmp,root);
        split(root,Max,root,r);
        //printf("%d ",x);
        printf("%lld ",ans+Sum(root)+(LL)Size(tmp)*i-Sum(tmp));
        root=merge(l,merge(tmp,merge(root,r)));
    }
    printf("\n");
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/