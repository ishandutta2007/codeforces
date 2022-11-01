#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll x, y;

int main() {
    scanf("%lld %lld", &y, &x);

    if(x == 0) puts("No");
    else if(x == 1) {
        if(y == 0) puts("Yes");
        else puts("No");
    }
    else if(y + 1 < x) puts("No");
    else {
        y -= (x - 1);
        if(y % 2) puts("No");
        else puts("Yes");
    }

    return 0;
}