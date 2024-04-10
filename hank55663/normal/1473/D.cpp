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
#define N 100000
#define rank Rank
struct node{
    node *l,*r;
    int a,b;
    int Max;
    int Min;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),Max(0){

    }
}*root;
void pull(node *n){
    n->Min=min(n->l->Min,n->r->Min);
    n->Max=max(n->l->Max,n->r->Max);
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Max=n->Min=a[n->a];
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
pii query(node *n,int l,int r){
    if(l>r)return mp(1e9,-1e9);
    if(n->a>=l&&n->b<=r){
        return mp(n->Min,n->Max);
    }
    if(n->b<l||n->a>r)return mp(1e9,-1e9);
    pii p1=query(n->l,l,r);
    pii p2=query(n->r,l,r);
    return mp(min(p1.x,p2.x),max(p1.y,p2.y));
}
bool solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    char c[200005];
    int p[200005];
    scanf("%s",c+1);
    p[0]=1;
    for(int i = 1;c[i]!=0;i++){
        if(c[i]=='-')p[i]=p[i-1]-1;
        else p[i]=p[i-1]+1;
    }
    root= new node(0,n);
    build(root,p);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        pii p1=query(root,0,l-1),p2=query(root,r+1,n);
        int val=p[r]-p[l-1];
        p2.x-=val;
        p2.y-=val;
        printf("%d\n",max(p2.y,p1.y)-min(p2.x,p1.x)+1);
    }
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
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