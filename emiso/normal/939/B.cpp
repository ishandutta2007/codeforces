#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, k, ans, a[MN], idx;

int main() {
    scanf("%lld %lld", &n, &k);

    for(int i=0; i<k; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = 0; i <k; i++) {
        ll cap = (n / a[i]) * a[i];
        if(cap > ans) {
            ans = cap;
            idx = i;
        }
    }

    printf("%lld %lld\n", idx + 1, n / a[idx]);
    return 0;
}