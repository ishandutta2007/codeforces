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
#define MXN 205
struct tnode{
    tnode *n[26];
    int val;
    tnode(){
        for(int i = 0;i<26;i++){
            n[i]=NULL;
        }
        val=0;
    }
};
struct node{
    node *l,*r;
    int Min;
    int tag;
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Min(0),tag(0){

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
void build(node *n){
    if(n->a==n->b){
        n->Min=1e9;
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
int query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return Min(n);
    }
    if(n->b<l||n->a>r)return 1e9;
    push(n);
    int res=min(query(n->l,l,r),query(n->r,l,r));
    pull(n);
    return res;
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return ;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
tnode *n[1000005];
int t;
int ans[1000005];
int dep=-1;

void dfs(tnode *n,int res){
    if(!n)return;
    dep++;
    if(n->val){
        ans[n->val]=min(query(root,0,dep-1)+1,res);
        int x=query(root,dep,dep);
        add(root,dep,dep,-x);
        add(root,dep,dep,ans[n->val]);
        add(root,0,dep,1);
        res=ans[n->val];
    }
    else{
        int x=query(root,dep,dep);
        add(root,dep,dep,-x);
        add(root,dep,dep,res);
    }
    for(int i = 0;i<26;i++){
        dfs(n->n[i],res+1);
    }
    dep--;
}
int main(){
    n[0]=new tnode();
    int q;
    scanf("%d",&q);
    for(int i = 1;i<=q;i++){
        int x;
        char c;
        scanf("%d %c",&x,&c);
        n[i]=new tnode();
        n[x]->n[c-'a']=n[i];
    }
    //dfs(n[0]);
    int k;
    scanf("%d",&k);
    for(int i = 1;i<=k;i++){
        int x;
        scanf("%d",&x);
        n[x]->val=i;
    }
    root = new node(0,q);
    build(root);
    //add(root,0,0,1);
    dfs(n[0],0);
    for(int i = 1;i<=k;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}
/*
[1,2,4,3,5,6]
concat(sorted([4,2,1]),sorted([5,3,6]))
concat(shuffle([2,1]),shuffle([2,3]))
concat(shuffle([2,1,3]),shuffle([3]))
1 3 4

*/