#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans;

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n; i*=2, ans++);

    printf("%lld\n", ans);
    return 0;
}