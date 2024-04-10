#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 7;

int a[MAXN];
vector <int> pos[MAXN];

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   

    vector <int> p;
    for (int i = 0; i < n; ++i) {
        if (a[i] == c) {
            p.push_back(i);
        }   
    }   

    for (int i = 0; i < n; ++i) {
        pos[a[i]].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (a[i] == c);
    }

    int add = 0;
    
    const int INF = 1e9 + 7;
    for (int i = 0; i < MAXN; ++i) {
        if (i == c) {
            continue;
        }
        int best = INF;
        int pr = 0;
        int curr = 0;
        for (int t : pos[i]) {
            curr = upper_bound(p.begin(), p.end(), t) - p.begin();
            best = min(best, pr - curr);
            ++pr;
            add = max(add, (pr - curr) - best);
        }   
    }   
    
    cout << ans + add << '\n';
    return 0;
}