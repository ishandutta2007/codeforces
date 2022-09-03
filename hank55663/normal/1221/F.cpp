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
struct node{
    node *l,*r;
    LL Max;
    LL Maxi;
    LL tag;
    node():l(NULL),r(NULL),Max(0){
        tag=0;
    }
}*root;
void push(node *n){
    //if(!n->l)n->l=new node();
    //if(!n->r)n->r=new node();
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
LL Max(node *n){
    return n->Max+n->tag;
}
void pull(node *n){
    if(Max(n->l)>Max(n->r)){
        n->Max=Max(n->l);
        n->Maxi=n->l->Maxi;
    }
    else{
        n->Max=Max(n->r);
        n->Maxi=n->r->Maxi;
    }
    //n->Max=max(Max(n->l),Max(n->r));
}
void build(node *n,int L,int R,int *a){
   // printf("%d %d\n",L,R);
    if(L==R){
        n->Max=a[L];
        n->Maxi=L;
        return;
    }
    int mid=(L+R)/2;
    n->l=new node();
    n->r=new node();
    build(n->l,L,mid,a);
    build(n->r,mid+1,R,a);
    pull(n);
}
void add(node *n,int L,int R,int l,int r,int k){
 //   printf("%d %d %d %d\n",L,R,l,r);
    if(L>=l&&R<=r){
        n->tag+=k;
        return;
        //return Max(n);
    }
    if(R<l||L>r)return;
  //  printf("?\n");
    push(n);
    int mid=(L+R)/2;
    add(n->l,L,mid,l,r,k);
    add(n->r,mid+1,R,l,r,k);
    pull(n);
}
pll query(node *n,int L,int R,int l,int r){
    if(L>=l&&R<=r){
        return mp(Max(n),n->Maxi);
    }if(R<l||L>r)return mp(-1e18,-1e18);
    push(n);
    int mid=(L+R)/2;
    pll res=max(query(n->l,L,mid,l,r),query(n->r,mid+1,R,l,r));
    pull(n);
    return res;
}
pair<pii,int> p[500005];
int a[500005];
int main(){
    int n;
    scanf("%d",&n);

    map<int,int> m;
    //set<int> vis;
    for(int i = 0;i<n;i++){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        if(x<y)swap(x,y);
        p[i]=mp(mp(x,y),c);
        m[y];
    }
    int index=0;
    for(auto &it:m){
        it.y=++index;
        a[index]=it.x;
    }
    sort(p,p+n);
    root = new node();
    build(root,1,index,a);
    LL ans=0;
    LL al=1e9+7,ar=1e9+7;
    for(int i = 0;i<n;i++){
        //printf("!\n");
        add(root,1,index,1,m[p[i].x.y],p[i].y);
       // printf("?\n");
        if(i==n-1||p[i].x.x!=p[i+1].x.x){
        pll res=query(root,1,index,1,prev(m.upper_bound(p[i].x.x))->y);
        res.x-=p[i].x.x;
        //printf("%d %d %d %d %d\n",p[i].x.x,p[i].x.y,p[i].y,res.x,res.y);
        if(res.x>ans){
            ans=res.x;
            
            al=a[res.y];ar=p[i].x.x;
        } 
        }
    }
    printf("%lld\n%lld %lld %lld %lld\n",ans,al,al,ar,ar);
    return 0;
}
/*
5 5
 _ _ _ _ _
|_ _  |_  |
|  _| |  _|
| |_   _| |
|    _ _  |
|_|_ _ _|_|

*/