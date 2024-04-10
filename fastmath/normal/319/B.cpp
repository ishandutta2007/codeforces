#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int n;
bool del[MAXN];
int a[MAXN], to[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) to[i] = i + 1;
    vector <int> v;
    for (int i = n - 1; i >= 0; --i) {
        if (to[i] < n && a[to[i]] < a[i]) v.push_back(i);
    }
    int ans = 0;
    while (v.size()) {
        ++ans;
        vector <int> nv;
        for (int i : v) {
            if (del[i]) continue;
            del[to[i]] = 1;
            to[i] = to[to[i]];
            if (to[i] < n && a[to[i]] < a[i]) nv.push_back(i);
        }   
        v = nv;
    }
    cout << ans << '\n';

    return 0;
}