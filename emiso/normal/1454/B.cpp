#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    map<int, int> x;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(x.count(a[i])) x[a[i]] = -1;
        else x[a[i]] = i;
    }

    ans = -1;
    for(auto tt : x) {
        if(tt.second != -1) {
            ans = tt.second + 1;
            break;
        }
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}