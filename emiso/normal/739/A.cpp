#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int main() {
    int n, m, l, r,ans = 99999999;
    scanf("%d %d",&n, &m);

    for(int i=0; i<m; i++) {
        scanf("%d %d",&l, &r);
        ans = min(ans, r - l + 1);
    }

    printf("%d\n",ans);
    for(int i=0;i<n;i++) {
        if(i) printf(" ");
        printf("%d", i%ans);
    } printf("\n");

    return 0;
}