
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
struct treap{
    treap *l,*r;
    int val;
    LL sum;
    int Size;
    treap(int _val):l(NULL),r(NULL),val(_val),sum(_val){
        Size=1;
    }
};
LL Sum(treap *t){
    return t?t->sum:0;
}
int Size(treap *t){
    return t?t->Size:0;
}
void pull(treap *t){
    t->sum=Sum(t->l)+Sum(t->r)+t->val;
    t->Size=Size(t->l)+Size(t->r)+1;
}
treap *merge(treap *l,treap *r){
    if(!l||!r)return l?l:r;
    if(rand()%(Size(l)+Size(r))<Size(l)){
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
void split(treap *t,int k,treap *&l,treap *&r){
    if(!t)l=r=NULL;
    else if(k<t->val){
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
treap *t[400005];
int f[400005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
LL newvalue=0;
vector<treap*> v;
void travel(treap *t){
    if(t){
        travel(t->l);
        v.pb(t);
        travel(t->r);
        t->l=t->r=NULL;
        pull(t);
    }
} 
treap *mergetree(treap *l,treap *r,int ll,int lr,int rl,int rr){
   // printf("%d %d %d %d\n",ll,lr,rl,rr);
    if(Size(l)>Size(r)){
        swap(l,r);
        swap(ll,rl);
        swap(lr,rr);
    }
    else{
        newvalue-=Size(l)*Sum(r);
    }
   // printf("%lld\n",newvalue);
    v.clear();
    travel(l);
    for(int i=0;i<v.size();i++){
        newvalue-=(LL)v[i]->val*(ll+i);
    }
    ll=min(ll,rl);
    rr=max(rr,lr);
  //  printf("%lld\n",newvalue);
    for(auto it:v){
        treap *lll,*rrr;
        split(r,it->val,lll,rrr);
        newvalue+=Sum(rrr);//->sum;
       // printf("%lld %d %d\n",newvalue,ll,Size(lll));
        newvalue+=(LL)(ll+Size(lll))*it->val;
        r=merge(lll,merge(it,rrr));
    }
   // printf("%lld\n",newvalue);
    return r;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=400004;i++)
    f[i]=i;
    LL ori=0;//newvalue=0;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&b,&a);
        ori+=(LL)a*b;
        b=Find(b);
        b=b+Size(t[b]);
        t[b]=new treap(a);
        newvalue+=(LL)a*b;
        treap *tt=t[b];
        if(t[b-1]){
            treap *l=t[Find(b-1)];
            tt=t[Find(b-1)]=mergetree(l,tt,Find(b-1),b-1,b,b);
            f[b]=Find(b-1);
        }
        if(t[b+1]){
            treap *r=t[Find(b+1)];
            tt=t[Find(b)]=mergetree(tt,r,Find(b-1),b,b+1,b+Size(r));
            f[Find(b+1)]=Find(b);
        }
        printf("%lld\n",-ori+newvalue);
    }
}