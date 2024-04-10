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
int f[400005];
LL Size[400005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
struct node{
    node *l,*r;
    int Size;
    LL sum;
    int k;
    node(int _k):Size(1),sum(_k),k(_k),l(NULL),r(NULL){

    }
}*root;
int Size2(node *n){
    return n?n->Size:0;
}
LL sum(node *n){
    return n?n->sum:0;
}
void pull(node *n){
    n->sum=sum(n->l)+sum(n->r)+n->k;
    n->Size=Size2(n->l)+Size2(n->r)+1;
}
node *merge(node *l,node *r){
    if(!l||!r)return l?l:r;
    if(rand()%(Size2(l)+Size2(r))<Size2(l)){
        l->r=merge(l->r,r);
        pull(l);
        return l;
    }
    else{
        r->l=merge(l,r->l);
        pull(r);
        return r;
    }
}
LL split(node *n,int k){
    if(k==0)return 0;
    if(!n)return 0;
    if(Size2(n->r)>=k){
        return split(n->r,k);
    }
    else{
        return split(n->l,k-Size2(n->r)-1)+n->k+sum(n->r);
    }
}
node *no[400005];
void solve(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    int a[200005],b[200005];
    vector<pii> vv;
    LL ans=0;
    for(int i = 0;i<n;i++)scanf("%d",&a[i]),vv.pb(mp(a[i],1)),ans+=a[i];//scanf("%d",&a[i]);
    for(int i = 0;i<m;i++)scanf("%d",&b[i]),vv.pb(mp(b[i],0));
    sort(vv.begin(),vv.end());
    for(int i = 0;i<n+m;i++){
        f[i]=i;
        Size[i]=vv[i].y;
        no[i]=new node(vv[i].x);
    }
    vector<pii> k;
    for(int i = 0;i<q;i++){
        int kk;
        scanf("%d",&kk);
        k.pb(mp(kk,i));
    }
    sort(k.begin(),k.end());
    vector<pair<int,int> > v;
    for(int i = 0;i<n+m-1;i++){
        v.pb(mp(vv[i+1].x-vv[i].x,i));
    }
    sort(v.begin(),v.end());
    int now=0;
    LL res[200005];
    for(auto it:k){
        while(now!=v.size()&&v[now].x<=it.x){
            int aa=v[now].y;
            int bb=aa+1;
            aa=Find(aa);
            bb=Find(bb);
            ans-=split(no[aa],Size[aa]);
             //   printf("%d %d %d\n",v[now].y,ans,Size[bb]);
            ans-=split(no[bb],Size[bb]);
            //    printf("%d %d %d\n",v[now].y,ans,Size[aa]);
            Size[bb]+=Size[aa];
            f[aa]=bb;
            no[bb]=merge(no[aa],no[bb]);
            ans+=split(no[bb],Size[bb]);
            //printf("%d %d\n",v[now].y,ans);
            now++;
        }
        //printf("!\n");
        res[it.y]=ans;
    }
    for(int i = 0;i<q;i++)printf("%lld\n",res[i]);
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