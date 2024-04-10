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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
/*
struct node{
    node *l,*r;
    int Min,Max;
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){

    }
}*roota,*rootb;
void pull(node *n){
    n->Max=max(n->l->Max,n->r->Max);
    n->Min=min(n->l->Min,n->r->Min);
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Max=n->Min=a[n->a];
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
int queryMax(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return n->Max;
    }
    if(n->b<l||n->a>r)return -2e9;
    return max(queryMax(n->l,l,r),queryMax(n->r,l,r));
}
int queryMin(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return n->Min;
    }
    if(n->b<l||n->a>r)return 2e9;
    return min(queryMin(n->l,l,r),queryMin(n->r,l,r));
}*/
int Maxa[200005][20];
int Mina[200005][20];
int Maxb[200005][20];
int Minb[200005][20];
void build(int Max[200005][20],int Min[200005][20],int *a,int n){
    for(int i = 1;i<=n;i++){
        Max[i][0]=a[i];
        Min[i][0]=a[i];
    }
    for(int i = 1;i<20;i++){
        for(int j=1;j<=n;j++){
            Max[j][i]=max(Max[j][i-1],Max[min(j+(1<<(i-1)),n)][i-1]);
            Min[j][i]=min(Min[j][i-1],Min[min(j+(1<<(i-1)),n)][i-1]);
        }
    }
}
int len[200005];
int queryMax(int Max[200005][20],int l,int r){
    int length=len[r-l+1];
  //  printf("%d %d %d %d\n",l,r,length,r-(1<<length)+1);
    return max(Max[l][length],Max[r-(1<<length)+1][length]);
}
int queryMin(int Min[200005][20],int l,int r){
    int length=len[r-l+1];
    return min(Min[l][length],Min[r-(1<<length)+1][length]);
}
int main(){
    int n;
    scanf("%d",&n);
    len[1]=0;
    for(int i = 2;i<=n;i++){
        if(__builtin_popcount(i)==1){
            len[i]=len[i-1]+1;
        }
        else{
            len[i]=len[i-1];
        }
    }
    int a[200005],b[200005];
    for(int i =1;i<=n;i++){
      //  a[i]=1;
        scanf("%d",&a[i]);
    }

    for(int i = 1;i<=n;i++){
        //b[i]=1;
        scanf("%d",&b[i]);
    }
    build(Maxa,Mina,a,n);
    build(Maxb,Minb,b,n);
    /*roota=new node(1,n);
    rootb=new node(1,n);
    build(roota,a);
    build(rootb,b);*/
    LL ans=0;
   // int vis[200005];
    //MEM(vis);
    //int aa[200005],bb[200005];
    for(int i = 1;i<=n;i++){
        int Min=0,Max=i+1;
        while(Max>Min+1){
            int mid=(Max+Min)/2;
            int aa=queryMax(Maxa,mid,i);
            int bb=queryMin(Minb,mid,i);
          //  vis[mid]=i;
            if(aa>=bb){
                Min=mid;
            }
            else{
                Max=mid;
            }
        }
        int res=Max;
        Min=0,Max=i+1;
        while(Max>Min+1){
            int mid=(Max+Min)/2;
          //  printf("! %d %d\n",mid,i);
            int aa=queryMax(Maxa,mid,i);
            int bb=queryMin(Minb,mid,i);
           // printf("?%d %d\n",aa,bb);
            if(aa>bb){
                Min=mid;
            }
            else{
                Max=mid;
            }
        }
        ans+=res-Min-1;
    }
    printf("%lld\n",ans);
}

/*

23847657 
23458792534

102334155
111111111 
111111111
*/