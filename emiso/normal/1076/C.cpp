#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, d;

int main() {
    scanf("%lld", &n);

    while(n--) {
        scanf("%lld", &d);
        ll delta = d*d - 4*d;
        if(delta < 0) puts("N");
        else {
            double a = (d + sqrt((double)delta)) / 2;
            double b = (d - sqrt((double)delta)) / 2;
            printf("Y %.9f %.9f\n", a, b);
        }
    }
    return 0;
}