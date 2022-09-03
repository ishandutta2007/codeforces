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
#define MXN 10005
#define less Less
struct node{
    node *l,*r;
    int a,b;
    int Max;
    int tag;
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
void add(node *n,int l,int r,int k){
   // printf("%lld %d %d %d %d\n",n,n->a,n->b,l,r);
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return;
    }
    if(n->b<l||n->a>r)return;
    if(!n->l){
        int mid=(n->a+n->b)/2;
        n->l=new node(n->a,mid);
        n->r=new node(mid+1,n->b);
    }
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
int main(){
    int n,r;
    scanf("%d %d",&n,&r);
    vector<pair<pii,pii> > v;
    for(int i =0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v.pb(mp(mp(x+y-r,1),mp(y-x-r+3000002,y-x+r+3000002)));
        v.pb(mp(mp(x+y+r+1,-1),mp(y-x-r+3000002,y-x+r+3000002)));
    }
    sort(v.begin(),v.end());
    root=  new node(0,6e6+5);
    int ans=0;
    for(auto it:v){
    //    printf("%d %d %d %d\n",it.x.x,it.y.x,it.y.y,it.x.y);
        add(root,it.y.x,it.y.y,it.x.y);
        ans=max(ans,Max(root));
       // printf("%d\n",Max(root));
    }
    printf("%d\n",ans);
}