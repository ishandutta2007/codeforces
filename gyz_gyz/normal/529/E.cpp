#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
long long a[5002];
int n,k,x,q,l,r,m,ans;
int main(){
    scanf("%d%d",&n,&k);
    rep(i,1,n)scanf("%I64d",&a[i]);
    a[n+1]=300000000;scanf("%d",&q);
    rep(o,1,q){
        scanf("%d",&x);ans=30;
        rep(i,1,n)rep(j,1,k)if(a[i]*j<=x)rep(s,0,k-j){
            l=0;r=n+1;m=(l+r)/2;
            for(;l+1<r;m=(l+r)/2)if(a[i]*j+a[m]*s>x)r=m;else l=m;
            if(a[i]*j+a[m]*s==x)if(j+s<ans)ans=j+s;
        }
        if(ans>k)printf("-1\n");else printf("%d\n",ans);
    }
}