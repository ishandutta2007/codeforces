#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1000100

ll b, k, x, ans;

int main() {
    scanf("%lld %lld", &b, &k);

    for(int i = 0; i < k; i++) {
        scanf("%lld", &x);
        ans = (ans * b + x) % 2;
    }

    printf("%s\n", ans % 2 ? "odd" : "even");
    return 0;
}