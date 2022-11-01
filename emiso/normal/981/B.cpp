#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, x, val;
map<ll, ll> bst;

int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &x, &val);
        if(!bst.count(x)) bst[x] = val;
        else if(bst[x] < val) bst[x] = val;
    }

    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &x, &val);
        if(!bst.count(x)) bst[x] = val;
        else if(bst[x] < val) bst[x] = val;
    }

    for(auto p : bst) {
        ans += p.second;
    }

    printf("%lld\n", ans);
    return 0;
}