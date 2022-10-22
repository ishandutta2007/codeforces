#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 2e5 + 7;

int a[MAXN];
map <int, set <int>> d;
set <int> ms;

void del(int pos, int val) {
    d[val].erase(pos);
    if (d[val].size() == 1) ms.erase(val);
}

void add(int pos, int val) {
    d[val].insert(pos);
    if (d[val].size() == 2) ms.insert(val);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    for (int i = 0; i < n; ++i) d[a[i]].insert(i);

    for (auto elem : d) {
        if (2 <= elem.second.size()) ms.insert(elem.first);
    }

    while (ms.size()) {
        int x = *ms.begin();

        int p1 = *d[x].begin();
        d[x].erase(d[x].begin());
        int p2 = *d[x].begin();
        d[x].insert(p1);

        del(p1, x);
        del(p2, x);
        add(p2, 2 * x);
    }

    for (int i = 0; i < n; ++i) a[i] = -1;
    for (auto elem : d) {
        for (int i : elem.second) a[i] = elem.first;
    }
    
    vector <int> ans;
    for (int i = 0; i < n; ++i) if (a[i] != -1) ans.push_back(a[i]);

    cout << ans.size() << '\n';
    for (int elem : ans) cout << elem << ' ';
    cout << '\n';

    return 0;
}