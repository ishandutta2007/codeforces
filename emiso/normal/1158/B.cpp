#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, k, p;

int main() {
    scanf("%lld %lld", &n, &k);
    p = (n - k + 2) / 2;
    if(k == 1) p = n;

    for(int i = 0; i < n; i++) {
        if(i % p == 0) printf("0");
        else printf("1");
    }
    return 0;
}