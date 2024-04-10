#include <bits/stdc++.h>
using namespace std;

#define inf 2000000001
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

const int bits = 9;
#define node pair<array<int, bits>, int>
const node null = {{inf, inf, inf, inf, inf, inf, inf, inf, inf}, inf};
const int power[bits] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
const int maxn = 1000000;

int n, m;
int arr[maxn], a[maxn], b[maxn];
node tree[maxn];

node attach(node x, node y) {
    node out = null;
    out.second = min(x.second, y.second);
    for (int j = 0; j < bits; j++) {
        int p = x.first[j], q = y.first[j];
        out.first[j] = min(p, q);
        if (max(p, q) < inf)
            out.second = min(out.second, p+q);
    }
    return out;
}

void upd(int i) {
    if (i >= n) {
        tree[i] = null;
        for (int j = 0; j < bits; j++)
            if ((arr[i-n]/power[j])%10 > 0)
                tree[i].first[j] = arr[i-n];
    } else
        tree[i] = attach(tree[2*i], tree[2*i+1]);
}

node query(int l, int r, int i) {
    if (l <= a[i] && b[i] <= r)
        return tree[i];
    if (b[i] < l || a[i] > r)
        return null;
    return attach(query(l, r, 2*i), query(l, r, 2*i+1));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int w; fin >> w >> m;
    n = 1<<int(ceil(log2(w)));
    fill(arr, arr+maxn, inf);
    fill(tree, tree+maxn, null);
    for (int i = 0; i < w; i++)
        fin >> arr[i];
    for (int i = 2*n-1; i > 0; i--) {
        if (i >= n)
            a[i] = b[i] = i-n;
        else {
            a[i] = a[2*i];
            b[i] = b[2*i+1];
        }
        upd(i);
    }
    for (int i = 0; i < m; i++) {
        int t; fin >> t;
        if (t == 1) {
            int j, x; fin >> j >> x; j--;
            arr[j] = x; j += n;
            for (; j > 0; j /= 2) {
                upd(j);
            }
        } else {
            int l, r; fin >> l >> r; l--, r--;
            int out = query(l, r, 1).second;
            if (out < inf)
                cout << out << "\n";
            else
                cout << "-1\n";
        }
    }
}