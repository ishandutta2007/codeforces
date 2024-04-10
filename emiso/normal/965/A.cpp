#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll k, n, s, p, ans, shits;

int main() {
    scanf("%lld %lld %lld %lld", &k, &n, &s, &p);
    shits = n / s + (n % s != 0);
    shits *= k;
    ans = shits / p + (shits % p != 0);

    printf("%lld\n", ans);
    return 0;
}