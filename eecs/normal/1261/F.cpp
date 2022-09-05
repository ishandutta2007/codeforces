#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 110, P = 998244353;
int n1, n2, ans;
ll l1[maxn], r1[maxn], l2[maxn], r2[maxn];
vector<ll> V[61];
vector<pair<ll, ll>> seg;

#define mid (l + r >> 1)
void ins(int k, ll v, ll l, ll r, ll ql, ll qr) {
    V[k].push_back(v);
    if (l >= ql && r <= qr) return;
    if (mid >= ql) ins(k - 1, v, l, mid, ql, qr);
    if (mid < qr) ins(k - 1, v | (1LL << (k - 1)), mid + 1, r, ql, qr);
}

void query(int k, ll v, ll l, ll r, ll ql, ll qr) {
    if (l >= ql && r <= qr) {
        for (ll x : V[k]) seg.emplace_back(v ^ x, (v ^ x) + (1LL << k) - 1);
        return;
    }
    if (mid >= ql) query(k - 1, v, l, mid, ql, qr);
    if (mid < qr) query(k - 1, v | (1LL << (k - 1)), mid + 1, r, ql, qr);
}

int main() {
    scanf("%d", &n1);
    for (int i = 1; i <= n1; i++) {
        scanf("%lld %lld", &l1[i], &r1[i]);
        ins(60, 0, 0, (1LL << 60) - 1, l1[i], r1[i]);
    }
    scanf("%d", &n2);
    for (int i = 1; i <= n2; i++) {
        scanf("%lld %lld", &l2[i], &r2[i]);
        query(60, 0, 0, (1LL << 60) - 1, l2[i], r2[i]);
    }
    for (int i = 0; i <= 60; i++) {
        V[i].clear();
    }
    for (int i = 1; i <= n2; i++) {
        ins(60, 0, 0, (1LL << 60) - 1, l2[i], r2[i]);
    }
    for (int i = 1; i <= n1; i++) {
        query(60, 0, 0, (1LL << 60) - 1, l1[i], r1[i]);
    }
    sort(seg.begin(), seg.end());
    ll lst = 0;
    for (auto p : seg) {
        ll l = max(lst + 1, p.first), r = p.second;
        if (l > r) continue;
        ans = (ans + (l + r) % P * ((r - l + 1) % P) % P * ((P + 1) / 2)) % P, lst = r;
    }
    printf("%d\n", ans);
    return 0;
}