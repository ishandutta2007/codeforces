#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 10010
#define ll long long
#define inf 1000000000000000ll
ll a[mx],ans;int l[mx],r[mx],h[mx],n,k,ss;
using namespace std;
int main(){
    scanf("%d%d",&n,&k);
    rep(i,1,n)scanf("%d%d",&l[i],&r[i]);
    rep(i,1,n)h[i]=l[i],h[i+n]=r[i];h[n*2+1]=k;
    sort(h+1,h+n*2+2);ss=0;
    rep(i,1,n*2+1){
        if(h[i]!=h[i-1]||i==1)h[++ss]=h[i];
    }
    rep(i,1,ss){
        rep(j,1,n){
            if(l[j]==h[i])l[j]=i;
            if(r[j]==h[i])r[j]=i;
        }
        if(k==h[i])k=i;
    }
    rep(i,1,ss)a[i]=inf;a[k]=0;ans=inf;
    rep(i,1,n){
        rep(j,1,ss-1)
            if(a[j]+h[j+1]-h[j]<a[j+1])
                a[j+1]=a[j]+h[j+1]-h[j];
        dep(j,ss,2)
            if(a[j]+h[j]-h[j-1]<a[j-1])
                a[j-1]=a[j]+h[j]-h[j-1];
        rep(j,1,ss){
            if(j<l[i])a[j]+=h[l[i]]-h[j];
            if(j>r[i])a[j]+=h[j]-h[r[i]];
        }
    }
    rep(i,1,ss)if(a[i]<ans)ans=a[i];
    printf("%I64d\n",ans);
}