#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m;

int main() {
    scanf("%lld %lld", &n, &m);
    if(n > m) swap(n, m);

    if(n % 6 == 0 || m % 6 == 0) {
        printf("%lld\n", n*m);
    }
    else if(n == 1) {
        ll res = m / 6 * 6;
        m %= 6;
        if(m <= 3) printf("%lld\n", res);
        else if(m == 4) printf("%lld\n", res + 2);
        else if(m == 5) printf("%lld\n", res + 4);
    }
    else if(n % 2 == 0) {
        if(m <= 2) puts("0");
        else if(m == 3) puts("4");
        else if(n == 2 && m == 7) puts("12"); // <<<<
        else if(n == 4 && m == 7) puts("28");
        else printf("%lld\n", n*m);
    }
    else if(n == 3) {
        if(m == 3) puts("8");
        else if(m % 2 == 0) printf("%lld\n", n*m);
        else printf("%lld\n", n*m-1);
    }
    else { //n impar >= 5
        if(m % 2 == 0) printf("%lld\n", n*m); //m par >= 6
        else printf("%lld\n", n*m-1);
    }

    return 0;
}