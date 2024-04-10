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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define rank Rank
#define MXN 15000
struct node{
    node *l,*r;
    //int a,b;
    int Min,Min2;
    node():l(NULL),r(NULL){

    }
}*root[9];
void pull(node *n){
    n->Min=min(n->l->Min,n->r->Min);
    if(n->Min==n->l->Min){
        n->Min2=min(n->l->Min2,n->r->Min);
    }
    else{
        n->Min2=min(n->l->Min,n->r->Min2);
    }
}
void build(node *n,int *a,int l,int r){
    if(l==r){
        n->Min=a[l];
        n->Min2=1e9+7;
        return;
    }
    int mid=(l+r)/2;
    n->l=new node();
    n->r=new node();
    build(n->l,a,l,mid);
    build(n->r,a,mid+1,r);
    pull(n);
}
void revise(node *n,int k,int x,int l,int r){
    if(l==r){
        n->Min=x;
        return ;
    }
    int mid=(l+r)/2;
    if(k<=mid)
    revise(n->l,k,x,l,mid);
    else
    revise(n->r,k,x,mid+1,r);
    pull(n);
}

pii query(node *n,int l,int r,int ll,int rr){
    if(ll>=l&&rr<=r){
        return  mp(n->Min,n->Min2);
    }
    if(rr<l||ll>r)
        return mp(1e9+7,1e9+7);
    int mid=(ll+rr)/2;
    pii p1=query(n->l,l,r,ll,mid),p2=query(n->r,l,r,mid+1,rr);
    int Min=min(p1.x,p2.x);
    int Min2;
    if(Min==p1.x){
        Min2=min(p1.y,p2.x);
    }
    else{
        Min2=min(p1.x,p2.y);
    }
    return mp(Min,Min2);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[200005];
    for(int i = 1;i<=n;i++){
    //    a[i]=rand()%10000000;
        scanf("%d",&a[i]);
    }
    int tmp[200005];
    for(int i = 1;i<=n;i++)
        tmp[i]=a[i];

    int aa[200005];
    for(int i = 0;i<9;i++){
        for(int j = 1;j<=n;j++){
            if(tmp[j]%10)
            aa[j]=a[j];
            else
            aa[j]=1e9+7;
            tmp[j]/=10;
        }
        root[i]=new node();
        build(root[i],aa,1,n);
    }
    while(m--){
        int op,l,r;
        /*op=rand()%2+1;
        if(op==1)
        {
            l=rand()%n+1;
            r=rand()%10000000;
        }
        else{
            l=rand()%n+1;
            r=rand()%n+1;
            if(l>r)swap(l,r);
        }*/
        scanf("%d %d %d",&op,&l,&r);
        if(op==1){
            int x=r;
            a[l]=r;
            for(int j = 0;j<9;j++){
                if(x%10){
                    revise(root[j],l,r,1,n);
                }
                else{
                    revise(root[j],l,1e9+7,1,n);
                }
                x/=10;
            }
        }
        else{
            int ans=2e9;
            for(int i = 0;i<9;i++){
                pii p =query(root[i],l,r,1,n);
                if(p.x<1e9&&p.y<1e9)
                ans=min(ans,p.x+p.y);
            }
            if(ans==2e9)ans=-1;
            printf("%d\n",ans);
        }
    }
    return 0;
}