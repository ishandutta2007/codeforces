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
    int a,b;
    int tag;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),tag(-1){

    }
}*root;
void push(node *n){
    if(n->tag!=-1){
        n->l->tag=n->tag;
        n->r->tag=n->tag;
        n->tag=-1;
    }
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
        n->tag=k;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    //pull(n);
}
int query(node *n,int x){
    if(n->a==n->b)return n->tag;
    int mid=(n->a+n->b)/2;
    push(n);
    if(x<=mid)return query(n->l,x);
    else return query(n->r,x);
}
LL dp[200005];
void solve(){
    int n,t;
    scanf("%d %d",&n,&t);
    int l[200005],r[200005];
    for(int i = 0;i<n;i++){
        int g,c;
        scanf("%d %d",&g,&c);
        //-c,g-c;
        l[i]=(t-c)%t;
        r[i]=(t+g-c)%t;
    }
    LL sum=0;
    map<int,int> m;
    for(int i = 1;i<n;i++){
        int d;
        scanf("%d",&d);
        sum+=d;
        l[i]=((l[i]-sum)%t+t)%t;
        r[i]=((r[i]-sum)%t+t)%t;
        m[l[i]];
        m[r[i]];
    }
    m[l[0]];
    m[r[0]];
    m[0];
    int index=0;
    for(auto &it:m)it.y=++index;
    root=new node(1,index);
    build(root);

    for(int i = n-1;i>=0;i--){
        int x=query(root,m[l[i]]);
        if(x==-1)dp[i]=0;
        else{
            dp[i]=dp[x]+((l[x]-l[i])%t+t)%t;
        }
        if(l[i]<r[i]){
            if(m[l[i]]!=1)add(root,1,m[l[i]]-1,i);
            add(root,m[r[i]],index,i);
        }
        else{
            add(root,m[r[i]],m[l[i]]-1,i);
        }
    }
    int last=-1;
    LL ans=8e18;
    for(auto &it:m){
        if(last!=-1){
            int x=query(root,last);
            if(x==-1)ans=sum;
            else
            ans=min(ans,sum+dp[x]+((l[x]-(it.x-1))%t+t)%t);
        }
        last=it.y;
    }
    int x=query(root,last);
    if(x==-1)ans=sum;
    else
    ans=min(ans,sum+dp[x]+((l[x]-(t-1))%t+t)%t);
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
4999850001
6
1 8 4 6 8 10
2 1
3 1
4 3
5 4
6 3
1 2 1
1 3 1
3 4 1
4 5 1
3 6 1
*/