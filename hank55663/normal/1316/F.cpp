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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int mod=1e9+7;
LL p2[300005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
struct treap{
    treap *l,*r;
    int Size;
    LL val;
    LL val2;
    LL k;
    treap(int _k):k(_k),l(NULL),r(NULL),Size(1),val(_k),val2(_k){
    }
}*root;
LL val(treap *t){
    return t?t->val:0;
}
LL val2(treap *t){
    return t?t->val2:0;
}
int Size(treap *t){
    return t?t->Size:0;
}
void pull(treap *t){
    t->val = val(t->r) * p2[Size(t->l) + 1] + t->k * p2[Size(t->l)] + val(t->l);
    t->val %= mod;
    t->val2 = val2(t->l) * p2[Size(t->r) + 1] + t->k * p2[Size(t->r)] + val2(t->r);
    t->val2 %= mod;
    t->Size = Size(t->l) + 1 + Size(t->r);
}
treap* merge(treap *l,treap *r){
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
void split(treap *t, int k, treap *&l, treap *&r){
    if(!t)l=r=NULL;
    else if(t->k<k){
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
void split2(treap *t, int k, treap *&l, treap *&r){
    if(!t)l=r=NULL;
    else if(Size(t->l)<k){
        l=t;
        split2(t->r,k-Size(t->l)-1,l->r,r);
        pull(l);
    }
    else{
        r=t;
        split2(t->l,k,l,r->l);
        pull(r);
    }
}
LL ans=0;
void msplit(treap *t,int k,treap *&l,treap *&r, int tag=0){
    if(tag){
        split2(t,k,l,r);
    }
    else
    split(t,k,l,r);
    ans-=val2(l)*val(r)%mod*p2[1]%mod;
    ans=(ans%mod+mod)%mod;
}
treap *mmerge(treap *l, treap *r){
    ans+=val2(l)*val(r)%mod*p2[1]%mod;
    ans%=mod;
    return merge(l,r);
}
int a[300005];
int main(){
    
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < 300005 ; i++){
        p2[i]=f_pow(f_pow(2,i),mod-2);
    }
    vector<int> v;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        //a[i]=rand();
        v.pb(a[i]);
    }
    sort(v.begin(),v.end());
    for(auto it:v){
        root=mmerge(root,new treap(it));
    }
    printf("%lld\n",ans*p2[1]%mod);
    int q;
    scanf("%d",&q);
    while(q--){
        int i=rand()%n+1,x=rand();
        scanf("%d %d",&i,&x);
        treap *l,*mid,*r;
        msplit(root,a[i],l,mid);
        msplit(mid,1,mid,r,1);
        a[i] = x;
        mid = new treap(x);
        root= mmerge(l,r);
        msplit(root,a[i],l,r);
        root=mmerge(mmerge(l,mid),r);
        printf("%lld\n",ans*p2[1]%mod);
    }
}
/*
9 4 
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9

*/