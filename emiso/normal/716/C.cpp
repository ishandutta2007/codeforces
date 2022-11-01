#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

int main() {
    long long n, l = 1, x = 2;
    scanf("%lld",&n);

    for(int i=1; i<=n; i++) {
        long long k = l * (l * (l + 2) + 1) - x/l;
        printf("%lld\n",k);

        x = l * (l + 1);
        l++;
    }
    return 0;
}

/*
x1 * x1 = x + k*l
x1 = (l+1) * q

(l+1)^2 * q^2 = x + kl
(l^2 + 2l + 1) * q^2 = x + kl
*/