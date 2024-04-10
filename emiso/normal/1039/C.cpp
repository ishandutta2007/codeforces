#include <bits/stdc++.h>

#define MN 501000
#define MOD 1000000007

using namespace std;
typedef long long ll;

struct union_find {
    map<int, int> parent, rank_;

    union_find() {}

    int gparent(int node) {
        if(!parent.count(node)) return node;
        return parent[node];
    }

    int find(int node) {
        if(node == gparent(node)) return node;
        return parent[node] = find(parent[node]);
    }

    int grank(int node) {
        if(!rank_.count(node)) return rank_[node] = 1;
        return rank_[node];
    }

    bool join(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;

        if(grank(a) > grank(b)) {
            parent[b] = a;
            rank_[a] += rank_[b];
        } else {
            parent[a] = b;
            rank_[b] += rank_[a];
        }
        return true;
    }
};

ll n, m, k, c[MN], maxi, ans;
int a, b;
map<ll, union_find> fudeu;
map<ll, int> quant;

ll expo(ll b, ll e) {
    if(!e) return 1;
    b %= MOD;
    if(e & 1) return b * expo(b * b, e >> 1) % MOD;
    return expo(b * b, e >> 1);
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    maxi = ((1LL << k) - 1);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &c[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ll val = c[a] ^ c[b];
        if(fudeu[val].join(a, b)) quant[val]++;
    }

    ll safe = ((maxi - quant.size() + 1)%MOD + MOD)%MOD;
    ans = safe * expo(2, n) % MOD;


    for(auto p : quant) {
        ans += expo(2, n - p.second);
        if(ans >= MOD) ans -= MOD;
    }

    printf("%lld\n", ans);
    return 0;
}