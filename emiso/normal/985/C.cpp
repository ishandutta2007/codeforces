#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, k, l, x, mi, res, bs, vol;
vector<ll> brl;

int main() {
    scanf("%lld %lld %lld", &n, &k, &l);

    for(int i = 0; i < n*k; i++) {
        scanf("%lld", &x);
        brl.push_back(x);
    }
    sort(brl.begin(), brl.end());
    mi = brl[0];

    for(int i = brl.size()-1; i >= 0; i--) {
        if(brl[i] > mi + l) res++;
        else if(brl[i] <= mi + l) {
            if(res + 1 < k) res++;
            else {
                vol += brl[i];
                res = res - (k - 1);
                bs++;
            }
        }
    }

    assert(bs <= n);
    if(bs < n) printf("0\n");
    else printf("%lld\n", vol);
    return 0;
}