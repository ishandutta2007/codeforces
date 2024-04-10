#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstring>

using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int K = 3000;
const int MAGIC = 700;
 
const int N = 2e5 + 7;
 
const int L = N / MAGIC + 7;
int a[N], b[N];
int cur[N], B[N];
int ql[N], qr[N], qt[N], ans[N], dl[N], dr[N];
int sum[L];
int sw[N][2];
int pos[N];
 
inline void modify(int x, int y, int t) {
    if (B[y]) --sum[x];
    B[y] += t;
    if (B[y]) ++sum[x];
}
 
inline void add(int x) {
    modify(x / MAGIC, x, 1);
}
 
inline void del(int x) {
    modify(x / MAGIC, x, -1);
}
 
inline int get(int l, int r) {
    int nl = l / MAGIC;
    int nr = r / MAGIC;
    int res = 0;
    if (nl == nr) {
        for (int i = l; i <= r; ++i) {
            res += B[i];
        }
    }
    else {
        for (int i = l, end = (nl + 1) * MAGIC - 1; i <= end; ++i) res += B[i];
        for (int i = nl + 1; i <= nr - 1; ++i) res += sum[i];
        for (int i = nr * MAGIC; i <= r; ++i) res += B[i];
    }
    return res;
}
 
inline void mod(int l, int r, int x, int y) {
    bool hvx = B[x];
    if (hvx) del(x);
    bool hvy = B[y];
    if (hvy) del(y);
    swap(b[x], b[y]);
    swap(pos[b[x]], pos[b[y]]);
    if (hvx) {
        add(y);
    }
    if (hvy) {
        add(x);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
        pos[b[i]] = i;
    }

    int m = 0;
    int timer = 0;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 2) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            ++timer;
            sw[timer][0] = x;
            sw[timer][1] = y;
        }
        else {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            --l1, --r1, --l2, --r2;
            qt[m] = timer;
            ql[m] = l1;
            qr[m] = r1;
            dl[m] = l2;
            dr[m] = r2;
            ++m;
        }
    }

    vector <int> idx;
    for (int i = 0; i < m; ++i) idx.push_back(i);

    sort(idx.begin(), idx.end(), [&] (int i, int j) {
        if (qt[i] / K != qt[j] / K) {
            return qt[i] < qt[j];
        }
        else if (ql[i] / K != ql[j] / K) {
            return ((qt[i] / K) & 1) ? ql[i] < ql[j] : ql[i] > ql[j];
        }
        else {
            return ((ql[i] / K) & 1) ? qr[i] < qr[j] : qr[i] > qr[j];
        }
    });

    int t = 0, l = 0, r = -1;
    for (int i : idx) {
        while (t < qt[i]) {
            ++t;
            mod(l, r, sw[t][0], sw[t][1]);
        }
        while (t > qt[i]) {
            mod(l, r, sw[t][0], sw[t][1]);
            --t;
        }
        while (l > ql[i]) add(pos[a[--l]]);
        while (r < qr[i]) add(pos[a[++r]]);
        while (l < ql[i]) del(pos[a[l++]]);
        while (r > qr[i]) del(pos[a[r--]]);
        ans[i] = get(dl[i], dr[i]);
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << '\n';
    }
}