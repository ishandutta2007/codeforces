#include <bits/stdc++.h>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int main() {
    int t,s,x;
    scanf("%d %d %d",&t,&s,&x);
    if(x >= t) {
        x = x - t;

        if((x % s == 0 || x % s == 1) && x != 1) printf("YES\n");
        else printf("NO\n");
    }
    else printf("NO\n");
    return 0;
}