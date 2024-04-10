#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, tot = 1, ch[maxn * 65][2], cnt[maxn * 65];
ll a[maxn], b[maxn], mn[maxn * 65];

int main() {
    scanf("%d", &n);
    memset(mn, 0x3f, sizeof(mn));
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
        int cur = 1;
        for (int j = 59; ~j; j--) {
            mn[cur] = min(mn[cur], b[i]);
            int c = b[i] >> j & 1;
            if (!ch[cur][c]) ch[cur][c] = ++tot;
            cur = ch[cur][c];
        }
        mn[cur] = b[i], cnt[cur]++;
    }
    auto del = [&](ll x) {
        static vector<int> id;
        id.clear();
        int cur = 1;
        for (int i = 59; ~i; i--) {
            id.push_back(cur);
            cur = ch[cur][x >> i & 1];
        }
        if (!--cnt[cur]) mn[cur] = LLONG_MAX;
        reverse(id.begin(), id.end());
        for (int k : id) mn[k] = min(mn[ch[k][0]], mn[ch[k][1]]);
    };
    function<ll(int, int, ll)> find = [&](int k, int i, ll x) {
        if (!~i) return mn[0];
        if (!k || mn[k] > 2e18) return mn[k];
        if (x >> i & 1) return find(ch[k][0], i - 1, x);
        return min(find(ch[k][0], i - 1, x), mn[ch[k][1]]);
    };
    ll lst = 0;
    for (int i = 1; i <= n; i++) {
        ll v = find(1, 59, lst);
        if (v > 2e18) puts("No"), exit(0);
        del(a[i] = v), lst ^= v;
    }
    puts("Yes");
    for (int i = 1; i <= n; i++) {
        printf("%lld ", a[i]);
    }
    return 0;
}