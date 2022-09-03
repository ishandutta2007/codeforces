#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
int val[1000005];
struct node{
    node *l,*r;
    int a,b;
    int len;
    int head,tail;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),len(0),head(0),tail(0){

    }
}*root;
void pull(node *n){
    n->head=n->l->head;
    n->tail=n->r->tail;
    if(n->l->len==0){
        n->head=n->r->head;
        n->tail=n->r->tail;
        n->len=n->r->len;
    }
    else if(n->r->len==0){
        n->head=n->l->head;
        n->tail=n->l->tail;
        n->len=n->l->len;
    }
    else if(n->l->tail==n->r->head){
        n->len=abs(n->l->len-n->r->len);
        if(n->l->len>n->r->len){
            n->head=n->l->head;
            if(n->len%2)n->tail=n->head;
            else n->tail=1-n->head;
        }  
         else{
             n->tail=n->r->tail;
            if(n->len%2)n->head=n->tail;
            else n->head=1-n->tail;
        }
    }
    else{
        n->len=n->l->len+n->r->len;
    }
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->tail=n->head=a[n->a];
        n->len=1;
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
node query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r)return *n;
    if(n->b<l||n->a>r){
        return node(0,0);
    }
    node ll=query(n->l,l,r);
    node rr=query(n->r,l,r);
    node res(0,0);
    res.l=&ll;
    res.r=&rr;
    pull(&res);
    return res;
}
void solve(){
   // v.clear();
    char c[1000005];
    scanf("%s",c+1);

    val[0]=0;
    //   v.pb(0);
    for(int i = 1;c[i]!=0;i++){
        if(c[i]=='('||c[i]==')')val[i]=1;
        else val[i]=0;
    }
    int n=strlen(c+1);
    root=new node(1,n);
    build(root,val);
    int Q;
    scanf("%d",&Q);
    for(int i = 0;i<Q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",query(root,l,r).len/2);
    }
    
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
[[([(([([([
1 8
3 4
1 8
2 7
5 6
*/