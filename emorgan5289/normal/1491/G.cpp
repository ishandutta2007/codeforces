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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 2e5+5;
int a[N], h[N], v[N], s[N];
vector<array<int, 2>> ans;

void op(int i, int j) {
    ans.pb({i+1, j+1});
    swap(a[i], a[j]);
    if (h[i] == h[j]) h[i] ^= 1, h[j] ^= 1;
}

void fixcycle(int i) {
    if (i != a[i] && i == a[a[i]]) op(i, a[i]);
    if (i == a[i]) return;
    while (!h[i] || h[a[i]]) i = a[i];
    while (i != a[i]) op(i, a[i]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--;
    vector<int> c;
    int p = -1;
    for (int i = 0; i < n; i++)
        if (!v[i]) {
            c.pb(i);
            for (int j = i; !v[j]; j = a[j])
                v[j] = 1, s[i]++;
            if (s[i] == 1) c.pop_back(), p = i;
        }
    while (c.size() > 1) {
        int x = c.back(); c.pop_back();
        int y = c.back(); c.pop_back();
        p = x;
        op(a[x], a[y]), op(x, y);
        fixcycle(x);
        fixcycle(y);
    }
    if (c.size() == 1) {
        int x = c[0];
        int y = a[x], z = a[a[x]];
        if (s[c[0]] == 2) {
            op(x, p), op(y, p), op(x, p);
        } else {
            op(x, z), op(x, y);
            fixcycle(x);
        }
    }
    cout << ans.size() << "\n";
    for (auto& [i, j] : ans)
        cout << i << " " << j << "\n";
    debug(vector(a, a+n));
    debug(vector(h, h+n));
}