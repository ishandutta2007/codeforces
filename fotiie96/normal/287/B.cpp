#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define clr(a) memset(a,0,sizeof(a))
long long n,k;
int main() {
    scanf("%I64d%I64d",&n,&k);
    --n;--k;
    if (k*(k+1)/2<n) {
        puts("-1");
        return 0;
    }
    if (n==0) {
        puts("0");
        return 0;
    }
    long long l=1,r=k+1;
    while (l+1<r) {
        int md=(l+r)>>1;
        if ((k+md)*(k-md+1)/2>=n) l=md; else r=md;
    }
    printf("%d\n",(int)k+1-l);
}