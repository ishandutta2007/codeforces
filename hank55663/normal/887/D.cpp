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
    node *l,*r;
    int a,b;
    LL tag;
    LL Min;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),tag(0),Min(1e9){

    }
}*root1,*root2;
LL Min(node *n){
    return n->Min+n->tag;
}
void pull(node *n){
    n->Min=min(Min(n->l),Min(n->r));
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void build(node *n,LL *val){
    if(n->a==n->b){
        n->Min=val[n->a];
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,val);
    build(n->r,val);
    pull(n);
}
void revise(node *n,int l,int r,LL val){
    if(l>r)return ;
    if(n->a>=l&&n->b<=r){
        n->tag+=val;
        return;
    }
    if(n->b<l||n->a>r)return ;
    push(n);
    revise(n->l,l,r,val);
    revise(n->r,l,r,val);
    pull(n);
}
bool query(node *n,int l,int r){
    if(l>r)return true;
    if(n->a>=l&&n->b<=r){
        return Min(n)>=0;
    }
    if(n->b<l||n->a>r)return true;
    push(n);
    bool res=query(n->l,l,r)&query(n->r,l,r);
    pull(n);
    return res;
}
void query(node *n,int x){
    if(n->a==n->b){
        printf("%lld ",Min(n));
        return ;    
    }
    int mid=n->l->b;
    push(n);
    if(x<=mid)query(n->l,x);
    else query(n->r,x);
    pull(n);
}
LL cnt[300005][2];
LL val[2][300005];
int main(){
    int n,a,b,c,d;
    int start,len;
    scanf("%d %d %d %d %d %d %d",&n,&a,&b,&c,&d,&start,&len);
    pii p[300005];
    for(int i = 1;i<=n;i++){
        int t,q;
        scanf("%d %d",&t,&q);
        p[i]=mp(t,q);
    }
    val[0][0]=val[1][0]=start;
    for(int i = 1;i<=n;i++){
        cnt[i][0]=cnt[i-1][0];
        cnt[i][1]=cnt[i-1][1];
        cnt[i][p[i].y]++;
        if(p[i].y==0){
            val[0][i]=val[0][i-1]-b;
            val[1][i]=val[1][i-1]-d;
        }
        else{
            val[0][i]=val[0][i-1]+a;
            val[1][i]=val[1][i-1]+c;
        }
    }
    root1=new node(1,n);
    root2=new node(1,n);
    build(root1,val[0]);
    build(root2,val[1]);
    vector<pair<int,pii>> v;
    if(len<=p[1].x){
        v.pb(mp(0,mp(n+1,n)));
    }
    else{
        int x=lower_bound(p+1,p+n+1,mp(len,0))-p-1;
        v.pb(mp(0,mp(1,x)));
    }
    for(int i =1;i<=n;i++){
        int x=lower_bound(p+1,p+n+1,mp(p[i].x+len+1,0))-p-1;
        if(x<i){
            v.pb(mp(p[i].x+1,mp(n+1,n)));
        }
        else{
            v.pb(mp(p[i].x+1,mp(i+1,x)));
        }
        int l=p[i].x-len+1;
        if(l>=0){
            x=lower_bound(p+1,p+n+1,mp(l,0))-p;
            v.pb(mp(l,mp(x,i)));
        }
    }
    sort(v.begin(),v.end());
    for(auto it:v){
    
        int l=it.y.x,r=it.y.y;
        //printf("%d %d %d\n",it.x,l,r);
        bool res1=query(root1,1,l-1);
       // for(int i = 1;i<=l-1;i++)
       //     query(root1,i);
        LL add = cnt[l-1][0]*(d-b)+cnt[l-1][1]*(a-c);
        revise(root2,l,r,add);
        bool res2=query(root2,l,r);
        //for(int i=l;i<=r;i++)
        //    query(root2,i);
        revise(root2,l,r,-add);
        add=(cnt[r][0]-cnt[l-1][0])*(b-d)+(cnt[r][1]-cnt[l-1][1])*(c-a);
       // revise(root1,r+1,n,add);
        bool res3=true;//query(root1,r+1,n);
       // for(int i=r+1;i<=n;i++)
       //     query(root1,i);
       // printf("\n");
       // revise(root1,r+1,n,-add);
        if(res1&&res2&&res3){
            printf("%d\n",it.x);
            return 0;
        }
    }
    
    printf("-1\n");
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/