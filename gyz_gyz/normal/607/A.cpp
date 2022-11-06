#include<cstdio>
#include<algorithm>
#define N 100001
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
struct pr{int x,y;}a[N];
int p[N],n,l,r,m,ans;
inline bool cmp(pr x,pr y){return x.x<y.x;}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    rep(i,1,n){
        l=1;r=i;m=(l+r)/2;
        for(;l<r;m=(l+r)/2)
            if(a[m].x+a[i].y<a[i].x)l=m+1;else r=m;
        if(m==1)p[i]=1;else p[i]=p[m-1]+1;
    }
    rep(i,1,n)if(p[i]>ans)ans=p[i];
    printf("%d\n",n-ans);
}