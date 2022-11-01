#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll l, w, ans = 1000000000000000LL, a[MN], acum[MN];

int main() {
    scanf("%lld %lld", &w, &l);

    for(int i = 1; i < w; i++) {
        scanf("%lld", &a[i]);
        acum[i] = acum[i-1] + a[i];
    }

    for(int i = l; i < w; i++) {
        ans = min(ans, acum[i] - acum[i-l]);
    }

    printf("%lld\n", ans);
    return 0;
}