#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 200001
#define ll long long
#define mo 1000000007
using namespace std;
ll a[mx],b[mx],c[mx],d[mx];int p[mx],e[mx],fr[mx],nt[mx],n;
int main(){
    scanf("%d",&n);
    rep(i,2,n)scanf("%d",&p[i]);
    rep(i,1,n)a[i]=1;
    dep(i,n,2){
        a[p[i]]=a[p[i]]*(1+a[i])%mo;
    }
    rep(i,2,n){
        if(e[p[i]]){
            nt[e[p[i]]]=i;fr[i]=e[p[i]];
        }
        e[p[i]]=i;
    }
    rep(i,2,n)if(fr[i])c[i]=c[fr[i]]*(1+a[i])%mo;
    else c[i]=(1+a[i])%mo;
    dep(i,n,2)if(nt[i])d[i]=d[nt[i]]*(1+a[i])%mo;
    else d[i]=(1+a[i])%mo;
    b[1]=1;
    rep(i,2,n){b[i]=1;
        if(fr[i])b[i]=b[i]*c[fr[i]]%mo;
        if(nt[i])b[i]=b[i]*d[nt[i]]%mo;     
        b[i]=(b[i]*b[p[i]]+1)%mo;
    }
    rep(i,1,n)printf("%I64d ",b[i]*a[i]%mo);
}