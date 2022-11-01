#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n;
ll ans, a[MN];

bool beautiful(int x) {
    for(int i = 1; (1 << i) <= x; i++) {
        ll a = ((1LL << i) - 1) * (1LL << (i - 1));
        if(a == x) return true;
        if(a > x) break;
    }
    return false;
}

int main() {
    scanf("%d", &n);

    int ans = 1;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            if(beautiful(i)) ans = max(ans, i);
            if(beautiful(n / i)) ans = max(ans, n / i);
        }
    }

    printf("%d\n", ans);
    return 0;
}