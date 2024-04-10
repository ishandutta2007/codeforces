#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll x, ans, a[MN];
vector<ll> op;

bool p2(ll x) {
    return (x & (x-1)) == 0;
}

int main() {
    scanf("%lld", &x);

    while(!p2(x+1)) {
        for(int i = 20; i >= 0; i--) {
            if((1 << i) < x && (x & (1 << i)) == 0) {
                op.push_back(i + 1);
                x ^= ((1 << (i+1)) - 1);
                break;
            }
        }
        ans++;
        if(p2(x+1)) break;
        x++;
        ans++;
    }

    printf("%lld\n", ans);
    for(ll x : op) printf("%lld ", x);
    return 0;
}