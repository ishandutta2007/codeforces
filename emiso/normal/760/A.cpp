#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll m, d;

int main() {
    scanf("%lld %lld", &m, &d);

    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if(d >= 6) puts("6");
        else puts("5");
    } else if(m == 4 || m == 6 || m == 9 || m == 11) {
        if(d == 7) puts("6");
        else puts("5");
    } else {
        if(d == 1) puts("4");
        else puts("5");
    }

    return 0;
}