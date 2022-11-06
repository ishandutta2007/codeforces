#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
int n,a[2048],ans;
int main(){
    scanf("%d",&n);n=(1<<(n+1))-1;
    rep(i,2,n)scanf("%d",&a[i]);
    rep(i,1,n/2)a[i*2]+=a[i],a[i*2+1]+=a[i];
    dep(i,n/2,1)
        if(a[i*2]>a[i*2+1])a[i]=a[i*2],ans+=a[i*2]-a[i*2+1];
        else a[i]=a[i*2+1],ans+=a[i*2+1]-a[i*2];
    printf("%d\n",ans);
}