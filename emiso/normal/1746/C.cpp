#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans[MN], a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    set<int> possib;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        possib.insert(i);
    }

    ans[1] = 1;
    possib.erase(1);

    for(int i = 2; i <= n; i++) {
        int nxt;
        if (a[i] > a[i-1]) {
            nxt = *possib.begin();
        } else {
            nxt = *possib.lower_bound(a[i-1] - a[i]);
        }
        possib.erase(nxt);
        ans[nxt] = i;
    }

    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    puts("");

    if(--t) goto st;
    return 0;
}