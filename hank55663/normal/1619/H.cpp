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
struct node{
    node *l,*r,*f;
    int Size;
    int val;
    node(int k):l(NULL),r(NULL),f(NULL),val(k),Size(1){

    }
};
int Size(node *n){
    return n?n->Size:0;
}
void pull(node *n){
    n->Size=Size(n->l)+Size(n->r)+1;
}
node *merge(node *l,node *r){
    if(!l||!r)return l?l:r;
    if(rand()%(Size(l)+Size(r))<Size(l)){
        l->r=merge(l->r,r);
        if(l->r)
        l->r->f=l;
        pull(l);
        return l;
    }
    else{
        r->l=merge(l,r->l);
        if(r->l)
        r->l->f=r;
        pull(r);
        return r;
    }
}
void split(node *t,int k,node *&l,node *&r){
    if(!t)l=r=NULL;
    else if(Size(t->l)<k){
        l=t;
        split(t->r,k-Size(t->l)-1,l->r,r);
        if(r)
        r->f=NULL;
        if(l->r)
        l->r->f=l;
        pull(l);
        return;
    }
    else{
        r=t;
        split(t->l,k,l,r->l);
        if(l)l->f=NULL;
        if(r->l)r->l->f=r;
        pull(r);
        return;
    }
}
node *Find(node *n){
    if(n->f)return Find(n->f);
    return n;
}
int Cnt(node *n){
    int tot=1+Size(n->l);
    node *Next=n->f;
    while(Next){
        if(Next->l==n);
        else tot+=1+Size(Next->l);
        n=Next;
        Next=n->f;
    }
    return tot;

}
void dfs(node *n){
    if(n){
        dfs(n->l);
        printf("%d ",n->val);
        dfs(n->r);
    }
}
node *n[100005];
int p[100005];
int vis[100005];
node* rotate(node *n,int k){
    node *l,*r;
    split(n,k,l,r);
    return merge(r,l);
}
int print(node *n){
    if(n)printf("%d ",n->val);
    else printf("0 ");
}
void solve(){
    int N,q;
    scanf("%d %d",&N,&q);
    for(int i = 1;i<=N;i++)scanf("%d",&p[i]),n[i]=new node(i);
    for(int i =1;i<=N;i++){
        if(!vis[i]){
            node *nn=NULL;
            int now=i;
            do{
                vis[now]=1;
                nn=merge(nn,n[now]);
                now=p[now];
             //   printf("%d ",now);
            }while(now!=i);
          //  printf("\n");
        }
    }
    /*for(int i= 1;i<=N;i++){
        print(n[i]->l),print(n[i]->r),print(n[i]->f);
        printf("\n");
    }*/
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,y;
            scanf("%d %d",&x,&y);
            node *a=Find(n[x]),*b=Find(n[y]);
            if(a==b){
                a=rotate(a,Cnt(n[x]));
                node *l,*r;
                split(a,Cnt(n[y]),l,r);
            }
            else{
                a=rotate(a,Cnt(n[x]));
                b=rotate(b,Cnt(n[y]));
                a=merge(a,b);
            }
        }
        else{
            int i,k;
            scanf("%d %d",&i,&k);
            node *nn=Find(n[i]);
            int cnt=Cnt(n[i]);
           // dfs(nn);
           /// printf("\n");
           // dfs(n[2]);
           // printf("\n");
            node *l,*r;
            split(nn,cnt,l,r);
            
            nn=merge(r,l);
          //  dfs(nn);
            k%=Size(nn);
            if(k==0){
                printf("%d\n",i);
            }
            else{
                split(nn,k-1,l,r);
                node *ll,*mid;
                split(r,1,ll,mid);
                printf("%d\n",ll->val);
                nn=merge(l,merge(ll,mid));
            }
        }
    }
}
int main(){
    int t=1;0000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}