#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, x[MN], ans;
map<ll, ll> f1, f2;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &x[i]);
        f2[x[i]]++;
    }

    for(int i = 0; i < n; i++) {
        f2[x[i]]--;
        if(f2[x[i]] == 0) f2.erase(x[i]);

        f1[x[i]]++;
        if(f1[x[i]] == 1) ans += f2.size();
    }

    printf("%lld\n", ans);
    return 0;
}