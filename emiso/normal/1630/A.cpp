#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, k, ans, cnt, used[1<<17];
//char s[MN]; string str;

void go(int l, int r) {
    assert(used[l] == 0 && used[r] == 0);
    used[l] = used[r] = 1;
    cnt++;
    ans += (l & r);
    printf("%d %d\n", l, r);
}

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &k);

    if (n == 4 && k == 3) puts("-1");
    else if(k < n - 1) {
        ans = cnt = 0;
        memset(used, 0, sizeof used);
        
        go(k, n-1);
        if (k != 0) go(0, n-1-k);
        for (ll i = 0; i < n; i++) {
            if(!used[i]) go(i, n-1-i);
        }

        assert(ans == k && cnt == n / 2);
    } else {
        ans = cnt = 0;
        memset(used, 0, sizeof used);

        go(n-1, n-2);
        go(1, 3);
        go(0, n-1-3);
        for (ll i = 0; i < n; i++) {
            if(!used[i]) go(i, n-1-i);
        }

        assert(ans == k && cnt == n / 2);
    }

    if(--t) goto st;
    return 0;
}