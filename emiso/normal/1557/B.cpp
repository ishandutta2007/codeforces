#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, ans, a[MN];
pair<int, int> b[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        b[i] = {a[i], i};
    }
    sort(b, b + n);
    for(int i = 0; i < n; i++) {
        ans += (!i || b[i].second != b[i-1].second + 1);
    }

    puts(ans <= k ? "Yes" : "No");
    if(--t) goto st;
    return 0;
}