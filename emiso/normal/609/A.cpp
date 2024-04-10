#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n,m,a[110],ans=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i = n-1; m > 0; i--) {
        ans++;
        m -= a[i];
    }
    printf("%d\n",ans);
    return 0;
}