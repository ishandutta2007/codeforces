#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, m, ans, a[210][210];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &m);

    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%lld", &a[i][j]);

    int flag = 0;
    for(int i = 0; i < n+m; i++) {
        int xo = 0;
        for(int j = 0; j <= i; j++) {
            xo ^= a[i-j][j];
        }
        if(xo != 0) flag = 1;
    }

    puts(flag ? "Ashish" : "Jeel");
    if(--t) goto st;
    return 0;
}