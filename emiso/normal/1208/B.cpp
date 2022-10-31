#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], bad;
map<int, int> freq;

int main() {
    scanf("%lld", &n);
    ans = n;

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int l = -1, r; l < n; l++) {
        if(l >= 0) {
            freq[a[l]]++;
            if(freq[a[l]] == 2) break;
            else ans = min(ans, n - l - 1LL);
        }

        for(r = n-1; r > l; r--) {
            freq[a[r]]++;
            if(freq[a[r]] == 2) break;
            else ans = min(ans, r - l - 1LL);
            if(r == l + 1) break;
        }
        for(; r < n; r++) {
            freq[a[r]]--;
        }
    }

    printf("%lld\n", ans);
    return 0;
}