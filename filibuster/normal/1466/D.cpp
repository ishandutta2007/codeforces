#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 14;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

vector<int> g[N];
int a[N];
int d[N];
bool used[N];

/*
1
5
5 1 1 1 1
1 2
1 3
1 4
1 5
*/

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
        used[i] = false;
    }

    li sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    set<pii> st;
    for(int i = 0; i < n; i++) {
        d[i] = g[i].size();
        st.insert({-a[i], i});
    }

    set<pii> e;

    cout << sum << ' ';

    int cur = 0;
    int cnt = 1;
    if(cnt == n - 1) {
        cout << endl;
        return;
    }
    for(auto p : st) {
        int v = p.s;
        bool fl = false;
        for(int i = 0; i < g[v].size() - 1; i++) {
            sum += a[v];
            cout << sum << ' ';
            cnt++;
            if(cnt == n - 1) {
                cout << endl;
                return;
            }
        }
//        for(auto u : g[v]) {
//            if(/*!used[u]*/e.count({v, u}) == 0 && (u != g[v].back() || fl)) {
//                sum += a[v];
//                cout << sum << ' ';
//                cnt++;
//                if(cnt == n - 1) {
//                    cout << endl;
//                    return;
//                }
//                e.insert({v, u});
//                e.insert({u, v});
//            } else {
//                fl = true;
////                cout << "not " << v + 1 << ' ' << u + 1 << ' ' << g[v].back() + 1 << ' ' << fl << endl;
//            }
//        }
//        used[v] = true;
    }
//    {
//        while(true) {
//            auto it = st.end();
//            it--;
//            int v = it->s;
//            for(int i = cur; i < g[v].size(); i++) {
//                int u = g[v][i];
//                if(!used[u]) {
//                    sum += a[v];
//                    cnt++;
//                    cout << sum << ' ';
//                    if(cnt == n - 1) {
//                        cout << endl;
//                        return;
//                    }
//                }
//            }
//            st.erase(it);
//            used[v] = true;
//        }
//    }
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}