#include <bits/stdc++.h>
#define MN 100100

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll MOD = 1000000007;

ll pow_(ll b, ll e) {
    b %= MOD;
    if(!e) return 1;
    if(e % 2) return (b * pow_(b * b, e / 2)) % MOD;
    return pow_(b * b, e / 2);
}

int n, c, v[MN], com[MN], x[MN], y[MN];
map<int, vector<pii> > ro, co;
set<int> ur, uc;
vector<int> adj[MN], comp[MN];

void compo(int no, int c) {
    if(v[no]) return;
    v[no] = 1;
    com[no] = c;
    comp[c].push_back(no);

    for(int i = 0; i < adj[no].size(); i++) {
        int w = adj[no][i];
        compo(w, c);
    }
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);

        ro[y[i]].push_back({x[i], i});
        co[x[i]].push_back({y[i], i});

        ur.insert(y[i]);
        uc.insert(x[i]);
    }

    for(int x : ur) {
        sort(ro[x].begin(), ro[x].end());
        for(int i = 1; i < ro[x].size(); i++) {
            int u = ro[x][i].second, w = ro[x][i - 1].second;
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
    }
    for(int x : uc) {
        sort(co[x].begin(), co[x].end());
        for(int i = 1; i < co[x].size(); i++) {
            int u = co[x][i].second, w = co[x][i - 1].second;
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
    }

    for(int i = 0; i < n; i++) {
        if(!v[i]) compo(i, c++);
    }

    ll ans = 1;
    for(int i = 0; i < c; i++) {
        ll tmp, dl = 0;
        set<int> tr, tc;

        for(int no : comp[i]) {
            tr.insert(y[no]);
            tc.insert(x[no]);
        }

        dl = tr.size() + tc.size();
        tmp = pow_(2, dl);

        if(comp[i].size() + 1 == dl)
            tmp--;

        ans = (ans * tmp) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}