#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mo 1000000007
#define N 1048577
#define ll long long
#define lb(x) ((x)&(-(x))) 
using namespace std;
struct pr1{int l,r,w;}d[N];
struct pr2{int l,r,id;}q[N];
int n,m,s,t,x,i1,i2;ll al,a[N],R[N],ans[N];
int A[N],pp[N],pr[N],Pr[N],P[N],PP[N],T[N],r[N];
inline bool cmp1(pr1 x,pr1 y){return x.r<y.r;}
inline bool cmp2(pr2 x,pr2 y){return x.r<y.r;}
ll ny(ll x){
    if(x==1)return 1;ll y=mo/x+1;
    return ny(x*y-mo)*y%mo;
}
inline ll qs(int x){ll y=1;
    for(;x;x-=lb(x))y=y*a[x]%mo;return y;
}
inline void add(int x,int y){
    for(;x<N;x+=lb(x))a[x]=a[x]*y%mo;
}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&A[i]);
    scanf("%d",&m);al=1;
    rep(i,1,m){scanf("%d%d",&q[i].l,&q[i].r);q[i].id=i;}
    rep(i,2,1000000){
        if(!pp[i])pr[++s]=i,Pr[i]=s;
        rep(j,1,s){
            if(i*pr[j]>1000000)break;
            pp[i*pr[j]]=1;
            if(!(i%pr[j]))break;
        }
    }
    rep(i,1,s)P[i]=(pr[i]-1)*ny(pr[i])%mo;
    rep(i,1,s)PP[i]=ny(P[i]);
    rep(i,1,s)al=al*P[i]%mo;
    rep(i,1,n){x=A[i];
        rep(j,1,s){
            if(pr[j]*pr[j]>x)break;
            if(!(x%pr[j])){
                while(!(x%pr[j]))x/=pr[j];
                if(T[j]+1<i){
                    d[++t].l=T[j]+1;d[t].r=i-1;
                    d[t].w=PP[j];
                }
                T[j]=i;
            }
        }
        if(x>1){
            if(T[Pr[x]]+1<i){
                d[++t].l=T[Pr[x]]+1;d[t].r=i-1;
                d[t].w=PP[Pr[x]];T[Pr[x]]=i;
            }
            T[Pr[x]]=i;
        }
    }
    rep(i,1,s)if(T[i]<n){
        d[++t].l=T[i]+1;d[t].r=n;d[t].w=PP[i];
    }
    sort(d+1,d+t+1,cmp1);sort(q+1,q+m+1,cmp2);
    i1=1;i2=1;R[0]=1;rep(i,1,N-1)a[i]=1;
    rep(i,1,n){
        for(;i2<=m&&q[i2].r==i;i2++)r[i2]=qs(q[i2].l);
        for(;i1<=t&&d[i1].r==i;i1++)add(d[i1].l,d[i1].w);
    }
    rep(i,1,n)R[i]=R[i-1]*A[i]%mo;
    rep(i,1,m){
        ans[q[i].id]=R[q[i].r]*ny(R[q[i].l-1])%mo;
        ans[q[i].id]=ans[q[i].id]*al%mo;
        ans[q[i].id]=ans[q[i].id]*ny(r[i])%mo;
        ans[q[i].id]=ans[q[i].id]*qs(q[i].l)%mo;
    }
    rep(i,1,m)printf("%I64d\n",ans[i]);
}