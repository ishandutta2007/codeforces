#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;
typedef map<int, int> mii;

unsigned short n, a[2002], b[2002];
map<unsigned short, unsigned short> dp[2001][10];

mii get(int x) {
    mii ret;
    while(x) {
        ret[x % 10]++;
        x /= 10;
    }
    return ret;
}

int rev(mii &m) {
    int ret = 0;
    for(auto &p : m) {
        for(int i = 0; i < p.second; i++) {
            ret = ret * 10 + p.first;
        }
    }
    assert(ret < 10000);
    return ret;
}

int solve(int id, int k, int f) {
    if(id == n && k == 0) return 0;
    if(dp[id][f].count(k)) return dp[id][f][k];

    int x = 65534;
    mii r = get(k);

    for(auto &p : r) {
        if(p.first == f) {
            p.second--;
            return dp[id][f][k] = solve(id, rev(r), f) + 1;
        }
    }

    int nxt = a[id];
    while(id < n && k < 1000 && nxt == f) {
        r[b[id]]++;
        return dp[id][f][k] = solve(id + 1, rev(r), f) + 1;
    }

    if(id < n && k < 1000) x = min(x, solve(id, k, nxt) + abs(f - nxt));
    for(auto &p : r) {
        x = min(x, solve(id, k, p.first) + abs(f - p.first));
    }

    return dp[id][f][k] = x;
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }

    printf("%d\n", solve(0, 0, 1));
    return 0;
}