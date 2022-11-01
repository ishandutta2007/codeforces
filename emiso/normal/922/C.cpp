#include <bits/stdc++.h>

#define MN 1001000LL

using namespace std;
typedef long long ll;

ll n, k;

int main() {
    scanf("%lld %lld", &n, &k);

    for(int i = 1; i <= min(MN, k); i++) {
        if(n % i != (i-1)) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");
    return 0;
}