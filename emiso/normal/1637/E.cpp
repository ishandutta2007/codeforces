#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, m, a[MN], c[MN], ans;

vector<ll> ys;
int compress(ll* arr, int n) {
    ys.clear();
    for(int i = 0; i < n; i++) {
        ys.push_back(arr[i]);
    }
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
    for(int i = 0; i < n; i++) {
        arr[i] = lower_bound(ys.begin(), ys.end(), arr[i]) - ys.begin();
    }
    return (int)ys.size();
}

int f[MN], mark[MN];
vector<int> cat[MN];
vector<int> adj[MN];

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        c[i] = a[i];
    }    
    ll N = compress(c, n);

    for(int i = 0; i < n; i++) {
        f[c[i]]++;
    }

    for (int i = 0, x, y; i < m; i++) {
        scanf("%d %d", &x, &y);
        x = lower_bound(ys.begin(), ys.end(), x) - ys.begin();
        y = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> freqs;
    for (int i = N-1; i >= 0; i--) {
        if (cat[f[i]].empty()) freqs.push_back(f[i]);
        cat[f[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        ll fa = f[c[i]];

        mark[c[i]] = 1;
        for (int v : adj[c[i]]) {
            mark[v] = 1;
        }

        for (int F : freqs) {
            for (ll j : cat[F]) {
                if (!mark[j]) {
                    ans = max(ans, (fa + F) * (a[i] + ys[j]));
                    break;
                }
            }
        }

        mark[c[i]] = 0;
        for (int v : adj[c[i]]) {
            mark[v] = 0;
        }
    }

    for (int i = 0; i <= n; i++) {
        f[i] = mark[i] = 0;
        cat[i].clear();
        adj[i].clear();
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}