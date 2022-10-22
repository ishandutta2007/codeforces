#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int n, q;
int a[MAXN], w[MAXN];
void read() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> w[i];
}

int f[MAXN], f1[MAXN];

void add_(int i, int x) {
    for (; i < MAXN; i |= (i + 1)) {
        f[i] += x;
    }
}

int getpr_(int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        ans += f[i];
    }
    return ans;
}

int get_(int l, int r) {
    return getpr_(r) - getpr_(l - 1);
}

void add1_(int i, int x) {
    int t = x * (i - a[i]);
    for (; i < MAXN; i |= (i + 1)) {
        f1[i] += t;
        f1[i] = mod(f1[i]);
    }
}

int getpr1_(int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        ans += f1[i];
    }
    return ans;
}

int get1_(int l, int r) {
    return mod(getpr1_(r) - getpr1_(l - 1));
}
 
int p[MAXN];
void solve() {
    for (int i = 0; i < n; ++i) add_(i, w[i]);
    for (int i = 0; i < n; ++i) add1_(i, w[i]);
    for (int i = 0; i < n; ++i) p[i] = a[i] - i;
}

void upd(int i, int x) {
    int delt = x - w[i];
    add_(i, delt);
    add1_(i, delt);
    w[i] = x;
}

int getl(int l, int r) {
    int bl = a[l] - 1;
    int br = a[r] - (r - l) + 1;
    int sum = get_(l, r);
    while (bl < br - 1) {
        int bm = (bl + br) / 2;
        //a[i] <= (bm + (i - l))
        //a[i] <= bm + i - l
        //a[i] - i <= bm - l
        auto t = upper_bound(p + l, p + r + 1, bm - l);
        int sum1 = get_(t - p, r);
        if (sum < sum1 * 2) bl = bm;
        else br = bm;
    }
    return br;
}

int getans(int l, int r, int tl) {
    auto t = upper_bound(p + l, p + r + 1, tl - l);
    int bl = t - p - 1;
    int ans = 0;
    ans += mod(mod(get_(l, bl)) * (tl - l)) + get1_(l, bl);
    ans -= mod(mod(get_(bl + 1, r)) * (tl - l)) + get1_(bl + 1, r);
    return mod(ans);
}

int get(int l, int r) {
    int tl = getl(l, r);
    return getans(l, r, tl);
}

void print() {
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        if (x < 0) {
            upd(-x - 1, y);
        }
        else {
            cout << get(x - 1, y - 1) << '\n';
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    read();
    solve();
    print();    

    return 0;
}