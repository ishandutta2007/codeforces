#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define LOGN 22
#define MAXN (1 << LOGN)

void FST(vector<ll> &a) {
    for (int b = 0; b < LOGN; b++)
        for (int i = 0; i < MAXN; i++)
            if (a[i] && (i & (1 << b)) == 0)
                a[i + (1 << b)] = a[i];
}

int n, x[1000100];
vector<ll> a(MAXN);

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        a[x[i]] = x[i];
    }

    FST(a);

    for(int i = 0; i < n; i++) {
        ll y = a[(MAXN-1) ^ x[i]];
        printf("%lld ", y ? y : -1);
    }

    return 0;
}