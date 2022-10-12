#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif


const int N = 100005, B = 400;
int b[N], p[N], ps[N], f[N];
int n;

// O(BlogB)
void sort_block(int x) {
    int l = x*B, r = min(n-1, (x+1)*B-1);
    copy(p+l, p+r+1, ps+l);
    sort(ps+l, ps+r+1);
    for (int i = l; i <= r; i++)
        ps[i] -= i-l;
}

// O(B^2)
void compute_block(int x) {
    int l = x*B, r = min(n-1, (x+1)*B-1);
    for (int i = r; i >= l; i--) {
        p[i] = b[i];
        for (int j = i+1; j <= r; j++)
            if (b[j] <= p[i]) p[i]++;
    }
    sort_block(x);
}

// O(BlogB)
void edit_block(int i, int y) {
    int x = i/B;
    int l = x*B, r = min(n-1, (x+1)*B-1);

    // recompute p[i]
    int pre = p[i];
    p[i] = y;
    for (int j = i+1; j <= r; j++)
        if (b[j] <= p[i]) p[i]++;

    // cycle j < i
    for (int j = i+1; j <= r; j++)
        f[p[j]] = 1;
    if (y > b[i]) {
        for (int j = l; j < i; j++)
            if (p[j] >= pre && p[j] <= p[i]) {
                p[j]--;
                while (f[p[j]]) p[j]--;
            }
    } else {
        for (int j = l; j < i; j++)
            if (p[j] <= pre && p[j] >= p[i]) {
                p[j]++;
                while (f[p[j]]) p[j]++;
            }
    }
    b[i] = y;
    for (int j = i+1; j <= r; j++)
        f[p[j]] = 0;

    sort_block(x);
}

// O(logB)
int apply_block(int x, int y) {
    int l = x*B, r = min(n-1, (x+1)*B-1);
    return y+upper_bound(ps+l, ps+r+1, y)-(ps+l);
}

// O(N/B logB)
int query(int i) {
    int y = p[i];
    for (int j = i/B+1; B*j < n; j++)
        y = apply_block(j, y);
    return y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i], b[i] = i-b[i];
    for (int i = 0; B*i < n; i++)
        compute_block(i);
    int q; cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x;
            edit_block(i-1, i-1-x);
        } else {
            int i; cin >> i;
            cout << query(i-1)+1 << "\n";
        }
    }
}