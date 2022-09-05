#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll cur = 2;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", 1LL * i * (i + 1) * (i + 1) - cur / i);
        cur = 1LL * i * (i + 1);
    }
    return 0;
}