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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
static const double INF = 2147483647;
struct node{
    node *l,*r;
    int pre,suf;
    int sum;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL){
        pre=suf=sum=0;
    }
}*root;
void pull(node *n){
    n->sum=n->l->sum+n->r->sum;
    n->pre=max(n->l->pre,n->l->sum+n->r->pre);
    n->suf=max(n->r->suf,n->l->suf+n->r->sum);
}
void build(node *n){
    if(n->a==n->b){
        n->sum=n->pre=n->suf=-1;
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void revise(node *n,int x,int w){
    if(n->a==n->b){
        n->pre=n->suf=n->sum=w;
        return;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid)revise(n->l,x,w);
    else revise(n->r,x,w);
    pull(n);
}
pii queryp(node *n,int l,int r){
    if(l>r)return mp(0,0);
    if(n->a>=l&&n->b<=r){
        return mp(n->pre,n->sum);
    }
    if(n->b<l||n->a>r)return mp(0,0);
    pii p1=queryp(n->l,l,r);
    pii p2=queryp(n->r,l,r);
    return mp(max(p1.x,p1.y+p2.x),p1.y+p2.y);
}
pii querys(node *n,int l,int r){
    if(l>r)return mp(0,0);
    if(n->a>=l&&n->b<=r){
        return mp(n->suf,n->sum);
    }
    if(n->b<l||n->a>r)return mp(0,0);
    pii p1=querys(n->l,l,r);
    pii p2=querys(n->r,l,r);
    return mp(max(p2.x,p2.y+p1.x),p1.y+p2.y);
}
vector<int> v[200005];
void solve(){
    int n;
    scanf("%d",&n);
    root=new node(1,n);
    build(root);
    int a[200005];
    int ans[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]].pb(i);
        ans[i]=0;
    }
    for(int i = 1;i<=n;i++){
        for(auto it:v[i]){
            revise(root,it,1);
        }
        for(auto it:v[i]){
            pii p1=querys(root,1,it-1);
            pii p2=queryp(root,it+1,n);
            int sum=(p1.x+p2.x+1);
            ans[it]=max(ans[it],(sum+1)/2-1);
        }
    }
    root=new node(1,n);
    build(root);
    for(int i = n;i>=1;i--){
        for(auto it:v[i]){
            revise(root,it,1);
        }
        for(auto it:v[i]){
            pii p1=querys(root,1,it-1);
            pii p2=queryp(root,it+1,n);
            int sum=(p1.x+p2.x+1);
            ans[it]=max(ans[it],sum/2);
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6 7
5 5 5 5 5 6 6 6 6 6 7 7 7

3 3 4 4 5 5 6 6 7 7 8
5 5 5 6 6 6 7 7 7 8 8 

3 3 4 4 5 5 6
5 5 5 5 5 5 5 

1 1 6
0 -3 -3

0 0 5
1 -2 -2
-2 -2 3
3 0 0
1 1
1 2 1
1 3 2 3 1
1 4 3 5 2 5 3 4 1
1 5 4 7 3 8 5 7 2 7 5 8 3 7 4 5 1
*/