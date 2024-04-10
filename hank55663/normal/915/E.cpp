#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int value[600005];
struct node{
    node *l,*r;
    int a,b;
    int ori;
    int sum;
    int tag;
    node(int _a,int _b):a(_a),b(_b),sum(0),tag(-1){

    }
    node(){
        ori = 0;
        sum = 0;
        tag = -1;
    }
}*root,no[1200005];
int ti;
void push(node *n){
    if(n->tag!=-1){
        n->l->tag=n->tag;
        n->r->tag=n->tag;
        n->tag=-1;
    }
}
int Sum(node *n){
    if(n->tag==-1)return n->sum;
    if(n->tag==0)return 0;
    return n->ori;
}
void pull(node *n){
    n->sum=Sum(n->l)+Sum(n->r);
}
void build(node *n){
    if(n->a==n->b){
        n->sum=n->ori=value[n->b+1]-value[n->a];
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=&no[++ti];
    n->l->a=n->a,n->l->b=mid;
    build(n->l);
    n->r=&no[++ti];
    n->r->a=mid+1,n->r->b=n->b;
    build(n->r);
    pull(n);
    n->ori=n->sum;
}
void revise(node *n,int l,int r,int k){
    if(n->a>=l&&n->b<=r){
        n->tag=k;
        return;
    }
    if(n->b<l||n->a>r){
        return;
    }
    push(n);
    revise(n->l,l,r,k);
    revise(n->r,l,r,k);
    pull(n);
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    pair<pii,int> p[300005];
    vector<int> v;
    for(int i = 0;i<q;i++){
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        p[i]=mp(mp(l,r),k);
        v.pb(l);
        v.pb(r+1);
    }
    v.pb(1);
    v.pb(n+1);
    sort(v.begin(),v.end());
    unique(v.begin(),v.end());
    //random_shuffle(p,p+q);
    int index = v.size();
    for(int i = 0;i<index;i++){
        value[i+1]=v[i];
    }
   /* m[1];
    m[n+1];
    int index=0;
    for(auto& it:m){
        it.y=++index;
        value[index]=it.x;
        //printf("%d %d\n",index,value[index]);
    }*/

    root = new node(1,index-1);
    build(root);
    //printf("%d\n",Sum(root));
    for(int i = 0;i<q;i++){
        p[i].x.x=lower_bound(v.begin(),v.end(),p[i].x.x)-v.begin()+1;
        p[i].x.y=lower_bound(v.begin(),v.end(),p[i].x.y+1)-v.begin()+1;
        revise(root,p[i].x.x,p[i].x.y-1,p[i].y-1);
        printf("%d\n",Sum(root));
    }
}
/*

262143999937856
*/