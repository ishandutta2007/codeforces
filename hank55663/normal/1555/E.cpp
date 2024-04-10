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
struct node{
    node *l,*r;
    int tag;
    int Min;
    int a,b;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),tag(0),Min(0){

    }
}*root;
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
int Min(node *n){
    return n->Min+n->tag;
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
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pair<int,pii> > v;
    root=new node(1,m-1);
    build(root);
    for(int i = 0;i<n;i++){
        int l,r,w;
        scanf("%d %d %d",&l,&r,&w);
        r--;
        v.pb(mp(w,mp(l,r)));
    }
    sort(v.begin(),v.end());
    int r=0;
    int ans=1e9;
    for(int i = 0;i<v.size();i++){
        while(Min(root)==0&&r!=v.size()){
            add(root,v[r].y.x,v[r].y.y,1);
            r++;
        }
        if(Min(root)){
        //    printf("%d %d %d %d\n",v[r-1].x,v[i].x,r,i);
            ans=min(ans,v[r-1].x-v[i].x);
        }
        add(root,v[i].y.x,v[i].y.y,-1);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 1 4 2
3 3 4 4
*/