#include<cstdio>
#include<algorithm>
#define MAX(a,b) ((a>b)?(a):(b))
using namespace std;
int a[1000010],b[1000010],c[2000020];
int main(){
    int n,m;
    long long ans= 0LL;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]),c[i]=a[i];
    for(int i=0;i<m;i++) scanf("%d",&b[i]),c[n+i]=b[i];
    sort(c,c+m+n);
    int temp=c[m];
    for(int i=0;i<n;i++) ans+=MAX(0,(temp-a[i]));
    for(int i=0;i<m;i++) ans+=MAX(0,(b[i]-temp));
    printf("%I64d\n",ans);
    return 0;
}