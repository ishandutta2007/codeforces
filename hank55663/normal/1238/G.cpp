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
#define MXN 1500
int c;
struct node{
    node *l,*r;
    int a,b;
    int Min;
    int tag;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Min(c),tag(0){

    }
}*root;
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
int Min(node *n){
    return n->tag+n->Min;
}
void pull(node *n){
    n->Min=min(Min(n->l),Min(n->r));
}
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
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
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
pair<int,pii> p[500005];
void solve(){
     int n,m,c0;
    scanf("%d %d %d %d",&n,&m,&c,&c0);
    root = new node(0,n);
    build(root);
    add(root,0,0,-c0);
    for(int i=1;i<=n;i++){
        int t,a,b;
        scanf("%d %d %d",&t,&a,&b);
        p[i]=mp(t,mp(a,b));
    }
    sort(p+1,p+n+1);
    int last=0,vol=c0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    LL ans=0;
    for(int i=1;i<=n;i++){
        vol-=p[i].x-last;
        last=p[i].x;
        while(vol<0){
            if(pq.empty()){
                printf("-1\n");
                return;
            }
            pii x=pq.top();
            int qu=min(query(root,x.y,i-1),p[x.y].y.x);
            if(qu==0){
                pq.pop();
            }
            else{
                LL addv=min(-vol,qu);
                ans+=addv*x.x;
                vol+=addv;
                p[x.y].y.x-=addv;
                add(root,x.y,i-1,-addv);
                qu-=addv;
                if(qu==0)pq.pop();
            }
        }
        add(root,i,i,-vol);
        pq.push(mp(p[i].y.y,i));
    }
    vol-=m-last;
    while(vol<0){
        if(pq.empty()){
            printf("-1\n");
            return;
        }
        pii x=pq.top();
        int qu=min(query(root,x.y,n),p[x.y].y.x);
        if(qu==0){
            pq.pop();
        }
        else{
            LL addv=min(-vol,qu);
           // printf("%lld\n",addv);
            ans+=addv*x.x;
            vol+=addv;
            p[x.y].y.x-=addv;
            add(root,x.y,n,-addv);
            qu-=addv;
            if(qu==0)pq.pop();
        }
      //  printf("%d\n",vol);
    }
    printf("%lld\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       solve();
    }
}
/*
100
3
 1000000001 1000000000 1
1 999999997 1
1 1 1000000000
1 1 999999999

*/