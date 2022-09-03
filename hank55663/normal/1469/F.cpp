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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
struct node{
    node *l,*r;
    int a,b;
    LL tag;
    LL sum;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),tag(0),sum(0){

    }
}*root;
LL Sum(node *n){
    return n->sum+n->tag*(n->b-n->a+1);
}
void pull(node *n){
    n->sum=Sum(n->l)+Sum(n->r);
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void build(node *n){
    if(n->a==n->b){
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void add(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return;
    }
    if(n->b<l||n->a>r)return;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
int query(node *n,int x){
    if(n->a==n->b)return n->tag;
    push(n);
    int mid=(n->a+n->b)/2;
    int res;
    if(x<=mid)res= query(n->l,x);
    else res=query(n->r,x);
    pull(n);
    return res;
}
int query2(node *n,int k){
    if(n->a==n->b)return n->a;
    push(n);
    int res;
    if(Sum(n->l)>k)res=query2(n->l,k);
    else res=query2(n->r,k-Sum(n->l));
    pull(n);
    return res;
}
bool solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    LL a[200005];
    LL sum=0;
    for(int i =0;i<n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i]-2;
    }
    sum++;
    if(sum<k){
        printf("-1\n");
    }
    else{
        sort(a,a+n);
        reverse(a,a+n);
        root=new node(0,1000000);
        build(root);
        add(root,0,0,1);
        int now=0;
        int cnt=1;
        int ans=1e9;
        for(int i = 0;i<1000000;i++){
            int x=query(root,i);
            while(x--){
                if(now==n){
                    //printf("%d\n",i);
                    break;
                }
                add(root,i+2,i+2+a[now]/2-1,1);
                add(root,i+2,i+2+(a[now]-1)/2-1,1);
                add(root,i,i,-1);
                cnt+=a[now]-2;
                ans=min(ans,query2(root,k-1));
                now++;
            }
            if(now==n)break;
        }
        printf("%d\n",ans);
    }
    return true;
}
int main(){
    int t=1;00000;//0000;//00000;//000000;//000000;
 //   scanf("%d",&t);
   // for(int i = 0;i<(1<<21);i++)s.insert(i);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/