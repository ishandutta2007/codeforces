#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int a[200005];
long long pre[200005];
int main(){
    scanf("%d%d",&n,&m);
    for (int x=0;x<n;x++) scanf("%d",&a[x]);
    sort(&a[0],&a[n]);

    for (int x=0;x<m;x++) pre[x]=a[x];

    for (int x=m;x<n;x++) pre[x]=pre[x-m]+a[x];

    long long ans=0;
    for (int x=0;x<n;x++){
        ans+=pre[x];
        printf("%lld ",ans);
    }
}