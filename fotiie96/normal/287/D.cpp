#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define clr(a) memset(a,0,sizeof(a))
int p[3010000],n;
int main() {
    scanf("%d",&n);
    rep(i,1,n+1) p[i]=i;
    rep(i,2,n+1) {
        int s=p[i-1],ns;
        for (int j=i-1;j<=n+i-2;j+=i) {
            ns=p[j+i];
            if (j+i<=n+i-2) p[j+i]=s;
                else p[n+i-1]=s;
            s=ns;
        }
    }
    rep(i,1,n+1) printf("%d ",p[n-1+i]);
}