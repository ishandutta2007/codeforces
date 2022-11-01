#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n;
ll S, a[MN], b[MN], best;
//char s[MN]; string str;

int main() {
    scanf("%d %lld", &n, &S);

    for(int i=0; i<n; i++) {
        scanf("%lld",&a[i]);
    }

    ll l = 0, r = n;
    while(l < r) {
        ll m = (l + r + 1)/ 2;

        for(int i=0; i<n; i++) {
            b[i] = a[i] + (i + 1) * m;
        } sort(b, b + n);

        ll s = 0;
        for(int i=0; i<m; i++) {
            s += b[i];
        }

        if(s <= S) {
            best = s;
            l = m;
        }

        else {
            r = m - 1;
        }
    }

    printf("%lld %lld\n", l, best);
    return 0;
}