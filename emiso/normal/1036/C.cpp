#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> digs;
void getdigs(ll x) {
    digs.clear();
    for(int i = 0; i <= 18; i++) {
        digs.push_back(x % 10);
        x /= 10;
    }
    reverse(digs.begin(), digs.end());
}

ll dp[19][4][2];
ll solve(int idx, int nz, int lim) {
    if(nz == 4) return 0;
    if(idx == 19) return 1;

    ll &x = dp[idx][nz][lim];
    if(x != -1) return x;
    x = 0;

    if(lim == 0) {
        x = solve(idx+1, nz, 0);
        x += 9*solve(idx+1, nz+1, 0);
    } else {
        x = solve(idx+1, nz, (digs[idx] == 0));
        if(digs[idx]) x += (digs[idx]-1)*solve(idx+1, nz+1, 0);
        if(digs[idx]) x += solve(idx+1, nz+1, 1);
    }

    return x;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ll l, r;
        scanf("%lld %lld", &l, &r);

        memset(dp, -1, sizeof dp);
        getdigs(l-1);
        l = solve(0, 0, 1);

        memset(dp, -1, sizeof dp);
        getdigs(r);
        r = solve(0, 0, 1);

        printf("%lld\n", r - l);
    }
    return 0;
}