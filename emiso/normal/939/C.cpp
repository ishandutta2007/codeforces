#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, ans, a[MN], s, f, tot, idx = 1;

int main() {
    scanf("%lld", &n);

    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }

    scanf("%lld %lld", &s, &f);
    s--; f--;

    for(int i = s; i != f; i = (i + 1) % n) {
        tot += a[i];
    }
    ans = tot;

    for(int i = 1; i < n; i++) {
        tot += a[(s - i + n) % n];
        tot -= a[(f - i + n) % n];

        if(tot > ans) {
            ans = tot;
            idx = i + 1;
        }
    }

    printf("%lld\n", idx);
    return 0;
}