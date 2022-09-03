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
int ti=0;
struct treap{
    treap *l,*r;
    int tagans;
    int num;
    int ans;
    int tag;
    int id;
    int pri;
    treap(int val):l(NULL),r(NULL),tagans(0),num(val),ans(0),tag(0),pri(rand()),id(ti++){
    }
};
int Num(treap *t){
    return t?t->num-t->tag:0;
}
int Ans(treap *t){
    return t?t->tagans+t->ans:0;
}
void go(treap *t,treap *u){
    if(u){
        u->tagans+=t->tagans;
        u->tag+=t->tag;
    }
}
void push(treap *t){
    t->ans+=t->tagans;
    t->num-=t->tag;
    go(t,t->l);
    go(t,t->r);
    t->tagans=0;
    t->tag=0;
}
treap *merge(treap *l,treap *r){
    if(!l||!r)return l?l:r;
    if(l->pri>r->pri){
        push(l);
        l->r=merge(l->r,r);
        return l;
    }
    else{
        push(r);
        r->l=merge(l,r->l);
        return r;
    }
}
void split(treap *t,int k,treap *&l,treap *&r){
    if(!t){
        l=r=NULL;
        return ;
    }
    push(t);
  //  printf("%d\n",Num(t));
    if(Num(t)<k){
        l=t;
        split(t->r,k,l->r,r);
    }
    else{
        r=t;
        split(t->l,k,l,r->l);
    }
}
int val(treap *t){
    push(t);
    if(t->l){
        return val(t->l);
    }
    return Num(t);
}
treap* t[200005];
int ans[200005];
void go(treap *t){
    if(!t)return;
    push(t);
    ans[t->id]=t->ans;
    go(t->l);
    go(t->r);
}
int main(){
    int n;
    scanf("%d",&n);
    pii p[200005];
    for(int i = 0;i<n;i++){
        int c,q;
        scanf("%d %d",&c,&q);
        p[i]=mp(-q,c);
    }
    sort(p,p+n);
    int q;
    scanf("%d",&q);
    pii pp[200005];
    for(int i=0;i<q;i++){
        int x;
        scanf("%d",&x);
        t[i]=new treap(x);
        pp[i]=mp(x,i);
    }
    sort(pp,pp+q);
    treap *root=NULL;
    for(int i = 0;i<q;i++){
        //printf("%d %d\n",Num(root),Num(t[pp[i].y]));
        root = merge(root,t[pp[i].y]);
        
    }

    for(int i = 0;i<n;i++){
        treap *l,*r;
        split(root,p[i].y,l,r);
        if(r){
            r->tagans++;
            r->tag+=p[i].y;
          //  printf("!\n");
        }
        treap *mid;
        split(r,p[i].y,mid,r);
        root=merge(l,r);
        while(mid){
            int x=val(mid);
            treap *l,*r;
            split(mid,x+1,l,r);
            //printf("%d %d %d\n",x,l,r);
           // getchar();
            mid=r;
            treap *ll,*rr;
            split(root,x,ll,rr);
            root=merge(merge(ll,l),rr);
        }
    }
    go(root);
    for(int i = 0;i<q;i++)
        printf("%d ",ans[i]);
    printf("\n");
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/