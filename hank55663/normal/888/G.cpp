#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
struct node{
    node *n[2];
    int Min;
    int Max;
    node(){
        n[0]=n[1]=NULL;
        Min=1e9;
        Max=0;
    }
}*root;
int Min(node *n){
    return n?n->Min:1e9;
}
int Max(node *n){
    return n?n->Max:0;
}
void pull(node *n){
    n->Min=min(Min(n->n[0]),Min(n->n[1]));
    n->Max=max(Max(n->n[0]),Max(n->n[1]));
}
void add(node *n,bitset<30> b,int i,int st){
    //printf("%lld %d\n",n,i);
    if(i==-1){
        n->Min=min(n->Min,st);
        n->Max=max(n->Max,st);
        return ;
    }
    if(!n->n[b[i]]){
        n->n[b[i]]=new node();
    }
    add(n->n[b[i]],b,i-1,st);
    pull(n);
}
int a[200005];
LL ans;
int query(int l,int r,int a){
    bitset<30> b(a);
    node *n=root;
    LL res=0;
    for(int i = 29;i>=0;i--){
        res<<=1;
        if(Min(n->n[b[i]])>r||Max(n->n[b[i]])<l){
            n=n->n[b[i]^1];
            assert(n);
            res++;
        }
        else{
            n=n->n[b[i]];
        }
        
    }
    return res;
}
void dc(int l,int r,int sum,int i){
    if(i==-1)return ;
   // printf("%d %d %d %d\n",l,r,sum,i);
    if(l>=r)return ;
    int x=lower_bound(a+l,a+r+1,sum+(1<<i))-a;
    dc(l,x-1,sum,i-1);
    dc(x,r,sum+(1<<i),i-1);
    //printf("%lld\n",x);
    if(x==l||x==r+1)return ;
  //  printf("%d %d %d %d %d\n",x,l,r,sum,i);
    if(x-l>r-x+1){
        int add=2e9;
        for(int i = x;i<=r;i++){
            add=min(add,query(l,x-1,a[i]));  
        }
        ans+=add;
    }
    else{
        int add=2e9;
        for(int i=l;i<x;i++){
            add=min(add,query(x,r,a[i]));
        }
        ans+=add;
    }
   // printf("%lld\n",ans);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    root = new node();
    for(int i = 0;i<n;i++){
     //   printf("%d\n",i);
        add(root,bitset<30>(a[i]),29,i);
    }
    //printf("?\n");
    dc(0,n-1,0,29);
    printf("%lld\n",ans);
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/