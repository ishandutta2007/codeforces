#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, t, ans, a[MN], dp[MN];
vector<int> v;

int maxi(int l, int r) {
    int maxi = -1, idx = -1;
    for(int i = l; i <= r; i++) {
        if(a[i] > maxi) {
            maxi = a[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    scanf("%lld", &t);
    st:

    scanf("%lld", &n);
    n *= 2;

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    v.clear();

    for(int tmp = n-1; tmp >= 0; tmp--) {
        int mx = maxi(0, tmp);
        v.push_back(tmp - mx + 1);
        tmp = mx;
    }

    dp[0] = 1;
    for(int x : v)
        for(int nv = n; nv >= x; nv--)
            if(dp[nv-x]) dp[nv] = 1;

    puts(dp[n/2] ? "YES" : "NO");
    for(int i = 0; i <= n; i++) dp[i] = 0;

    if(--t) goto st;
    return 0;
}