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
#define MXN 3000000
int S[200005];
void add(int x,int k){
    for(int i = x;i<200005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i)
        res+=S[i];
    return res;
}
pii p[200005];
struct node{
    node *l,*r;
    int tag;
    int Max;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),tag(0),Max(-1e9),l(NULL),r(NULL){
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
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
int query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
      //  printf("!!%d %d %d %d %d\n",Max(n),n->a,n->b,n->Max,n->tag);
        return Max(n);
    }
    if(n->b<l||n->a>r)return -1e9;
    push(n);
    int res=max(query(n->l,l,r),query(n->r,l,r));
    pull(n);
    return res;
}
void ass(node *n,int k,int w){
    if(n->a==n->b){
        n->tag=0;
        n->Max=w;
        return;
    }
    int mid=(n->a+n->b)/2;
    push(n);
    if(k<=mid)ass(n->l,k,w);
    else ass(n->r,k,w);
    pull(n);
}
void solve(){
    int n;
    scanf("%d",&n);
    set<int> s;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        p[i]=mp(x,i);
        add(i,1);
        s.insert(i);
    }
    s.insert(n+1);
    root=new node(1,n);
    build(root);
    sort(p+1,p+n+1);
    //reverse(p+1,p+n+1);
    int ans=0;
    int rMax=0;
    for(int i = 1;i<=n;i++){
       // printf("%d\n",Max(root));
     //  printf("%d\n",p[i].y);
        int x=p[i].y;
        s.erase(x);
        rMax=max(rMax,x);  
        int val=query(x-1)+x%2-(x-query(x-1));
        //printf("val:%d %d %d %d\n",val,query(x-1),x%2,-(x-query(x-1)+1));
        add(x,-1);
        ass(root,x,val);
        add(root,x+1,n,-2);
        if(*s.begin()>rMax)continue;
        ans=max(ans,i+query(root,*s.begin(),n));
     //   printf("%d %d\n",i,query(root,*s.begin(),n));
    }
    printf("%d\n",ans);
    
}
int main(){
    int t=1000000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
000010000
001010000
001010100
001011100
*/