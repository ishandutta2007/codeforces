#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

int main() {
    int n, c, ans=0,t, last=0;
    scanf("%d %d",&n, &c);

    for(int i=0; i<n; i++) {
        scanf("%d",&t);
        if(t - last > c) ans = 0;
        last = t;
        ans++;
    }

    printf("%d\n",ans);
    return 0;
}