#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
    int Size;
    LL sum;
    LL val;
    int pri;
    node(int _val):sum(_val),val(_val),Size(1),l(NULL),r(NULL),pri(rand()){

    }
}*root;
int Size(node *n){
    return n?n->Size:0;
}
LL sum(node *n){
    return n?n->sum:0;
}
void pull(node *n){
    n->Size=Size(n->l)+Size(n->r)+1;
    n->sum=sum(n->l)+sum(n->r)+n->val;
}
node *merge(node *l,node *r){
    if(!l||!r)return l?l:r;
    if(l->pri>r->pri){
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
void split(node *n,LL k,node *&l,node *&r){
    if(!n)l=r=NULL;
    else if(sum(n->r)>=k){
        l=n;
        split(n->r,k,l->r,r);
        pull(l);
    }
    else{
        r=n;
        split(n->l,k-sum(n->r)-n->val,l,r->l);
        pull(r);
    }
}
void splitS(node *n,int k,node *&l,node *&r){
    if(!n)l=r=NULL;
    else if(Size(n->l)<k){
        l=n;
        splitS(n->r,k-Size(l)-1,l->r,r);
        pull(l);
    }
    else{
        r=n;
        splitS(n->l,k,l,r->l);
        pull(r);
    }
}
void dfs(node *n){
    if(!n)return;
    dfs(n->l);
    printf("%lld ",n->val);
    dfs(n->r);
}
void solve(){
    root=NULL;
    int n;
    scanf("%d",&n);
    LL a[100005];
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
     //   a[i]=-1;
    }
  //  a[0]=1e9;
   // a[n-1]=1e9;
    if(a[0]<0||a[n-1]<0){
        printf("-1\n");
    }
    else{
        LL ans=0;
        root=merge(root,new node(a[0]));
        for(int i = 1;i<n-1;i++){
            if(a[i]<0){
               // a[i-1]+=a[i];
                a[i+1]+=a[i];
                a[i]=-a[i];
                if(sum(root)<a[i]){
                    printf("-1\n");
                    return;
                }
                node *l,*r;
                split(root,a[i],l,r);
                ans+=Size(r);
               // printf("%d\n",Size(r));
                if(Size(r)==1){
                    r->val-=a[i];
                    r->sum=r->val;
                    root=merge(l,r);
                    root=merge(root,new node(a[i]));
                }
                else{
                    LL s=sum(r)-a[i];
                    node *mid,*rr;
                    splitS(r,1,mid,rr);
                    LL s2=-s+mid->val;
                    mid->val=mid->sum=s2;
                    root=merge(l,merge(new node(s),merge(mid,rr)));
                }
            }
            else{
                root=merge(root,new node(a[i]));
            }
          //  dfs(root);
          //  printf("\n");
        }
        if(a[n-1]<0){
            printf("-1\n");
            return;
        }
        printf("%lld\n",ans);
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
4999850001
*/