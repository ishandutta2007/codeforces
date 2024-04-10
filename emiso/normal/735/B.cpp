#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int main() {
    int n,n1,n2,a[100100];
    scanf("%d %d %d",&n, &n1, &n2);

    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);

    double ans = 0, n1a = 0, n2a = 0;
    if(n1 > n2) swap(n1,n2);

    for(int i=1;i<=n1;i++)
        n1a += a[n-i];
    for(int i=1;i<=n2;i++)
        n2a += a[n-i-n1];

    ans = n1a / n1 + n2a / n2;

    printf("%f\n",ans);
    return 0;
}