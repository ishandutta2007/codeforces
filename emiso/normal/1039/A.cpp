#include <bits/stdc++.h>

#define MN 201000
#define INF 2100000000000000000LL

using namespace std;
typedef long long ll;

ll n, t, lb[MN], rb[MN], a[MN], x[MN];

void end() {
    puts("No");
    exit(0);
}

int main() {
    scanf("%lld %lld", &n, &t);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        lb[i] = -INF;
        rb[i] = INF;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &x[i]);
        if(x[i] < x[i-1] || x[i] < i) end();
    }

    for(int i = 1; i <= n; i++) {
        lb[i] = max(lb[i-1] + 1, a[i] + t);
        if(x[i] > i) lb[i] = max(lb[i], a[i+1] + t);

        if(x[i] < n) rb[x[i]] = min(rb[x[i]], a[x[i]+1] + t - 1);
    }

    for(int i = 1; i <= n; i++) {
        if(lb[i] > rb[i]) end();
    }

    puts("Yes");
    for(int i = 1; i <= n; i++) {
        printf("%lld ", lb[i]);
        assert(lb[i] > lb[i-1]);
    }
    return 0;
}