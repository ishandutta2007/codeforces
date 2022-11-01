#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll a, b, c, n, d;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &n);

    d = n - a - b + c;
    if(d < 1 || c > a || c > b || a >= n || b >= n || c >= n)
        printf("-1\n");
    else printf("%d\n", d);
    return 0;
}