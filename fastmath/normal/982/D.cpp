#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int a[MAXN];
int par[MAXN];
int cnt[MAXN];
bool used[MAXN];

multiset <int> s1, s2;

int root(int u) {
    if (par[u] == u) return u;
    else return par[u] = root(par[u]);
}

int comp = 0;

void merge(int u, int v) {
    --comp;
    u = root(u);
    v = root(v);

    if (cnt[v] < cnt[u]) {
        par[v] = u;
        s1.erase(s1.find(cnt[u]));
        s1.erase(s1.find(cnt[v]));
        s2.erase(s2.find(-cnt[u]));
        s2.erase(s2.find(-cnt[v]));
        cnt[u] += cnt[v];
        s1.insert(cnt[u]);
        s2.insert(-cnt[u]);
    }
    else {
        par[u] = par[v];
        s1.erase(s1.find(cnt[u]));
        s1.erase(s1.find(cnt[v]));
        s2.erase(s2.find(-cnt[u]));
        s2.erase(s2.find(-cnt[v]));
        cnt[v] += cnt[u];
        s1.insert(cnt[v]);
        s2.insert(-cnt[v]);
    }
}

void add(int i, int n) {
    ++comp;
    s1.insert(1);
    s2.insert(-1);
    if (i && used[i - 1]) merge(i, i - 1);
    if (i + 1 < n && used[i + 1]) merge(i, i + 1);
    used[i] = true;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    map <int, vector <int>> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        d[a[i]].push_back(i);
    }
    
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        cnt[i] = 1;
    }

    int ans = -1, best = -1;
    for (auto elem : d) {
        for (int i : elem.second) {
            add(i, n);
        }
        
        if (*s1.begin() == -*s2.begin()) {
            if (best < comp) {
                ans = elem.first + 1;
                best = comp;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}