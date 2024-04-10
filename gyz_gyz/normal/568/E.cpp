#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define mx 100010
#define inf 2000000000
using namespace std;
int a[mx],b[mx],c[mx],w[mx],fr[mx],us[mx],le[mx],n,m,k,e,s,g,l,r,mid;
int main(){
    scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);
    scanf("%d",&m);rep(i,1,m)scanf("%d",&b[i]);
    rep(i,1,n)c[i]=inf;sort(b+1,b+m+1);b[m+1]=inf;a[n+1]=inf;
    rep(i,1,n)if(a[i]>0){
        l=0;r=n;mid=(l+r)/2;
        for(;l<r;mid=(l+r)/2){
            if(c[mid]<a[i])l=mid+1;else r=mid;
        }
        c[l]=a[i];fr[i]=w[l-1];w[l]=i;le[i]=l;
    }else{k=m;fr[i]=-1;le[i]=-1;
        dep(j,n,1)for(;b[k]>c[j-1];k--)
            if(b[k]<c[j])c[j]=b[k],w[j]=i;
    }
    dep(i,n,1)if(c[i]<inf){e=i;break;}
    k=n+1;le[k]=e+1;fr[k]=w[e];s=m+1;g=n+1;
    dep(i,e,0)
        if(le[fr[k]]!=-1)k=fr[k],g=k;
        else if(le[k]-i>1){
            while(b[s]==b[s-1])s--;
            s--;while(b[s]>=a[k])s--;
            while(a[g]!=-1)g--;
            a[g]=b[s];us[s]=1;g--;
            dep(j,g,0)if(le[j]==i&&a[j]<b[s]){
                k=j;g=j;break;
            }
        }   
    k=1;rep(i,1,n)if(a[i]==-1){
        while(us[k])k++;a[i]=b[k++];
    }
    rep(i,1,n)printf("%d ",a[i]);
}