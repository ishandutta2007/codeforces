#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, k;
ll ans, a[MN], mx = INT_MIN, mi = INT_MAX, id, minl[MN], minr[MN];
//char s[MN]; string str;

int main() {
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        if(mx < a[i] or (mx == a[i] && i + 1 == n)) {
            mx = a[i];
            id = i;
        }
        mi = min(mi, a[i]);
    }

    if(k >= 3) {
        printf("%d\n", mx);
    }

    else if(k == 1) {
        printf("%d\n", mi);
    }

    else {
        minl[0] = a[0];
        minr[n-1] = a[n-1];
        ll best = INT_MIN;

        for(int i=1; i<n; i++) {
            minl[i] = min(minl[i-1], a[i]);
        }

        for(int i=n-2; i>=0; i--) {
            minr[i] = min(minr[i+1], a[i]);
        }

        for(int i = 1; i < n; i++) {
            best = max(best, max(minl[i-1], minr[i]));
        }
        printf("%lld\n", best);
    }

    return 0;
}