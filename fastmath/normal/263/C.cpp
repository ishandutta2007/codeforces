#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
vector <int> g[N];
int ans[N];
bool used[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <ii> e;
    for (int i = 0; i < 2 * n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v);
        g[v].app(u);
        if (v < u)
            swap(u, v);
        e.app(mp(u, v));
    }   
    sort(all(e));
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() != 4) {
            cout << "-1\n";
            exit(0);
        }   
    }   
    ans[0] = 1;
    for (int x : g[1]) {
        for (int y : g[1]) {
            if (x != y) {
                ans[1] = x;
                ans[2] = y;
                memset(used, 0, sizeof used);
                used[1] = used[x] = used[y] = 1;
                bool ban = 0;
                for (int i = 3; i < n; ++i) {
                    set <int> ms;
                    for (int e : g[x])
                        ms.insert(e);
                    vector <int> can;
                    for (int e : g[y]) {
                        if (ms.find(e) != ms.end()) {
                            can.app(e);
                        }   
                    }   
                    bool f = 0;
                    for (int e : can) {
                        if (!used[e]) {
                            x = y;
                            y = e;
                            used[e] = 1;
                            ans[i] = e;
                            f = 1;
                            break;
                        }   
                    }   
                    if (!f) {
                        ban = 1;
                        break;
                    }   
                }   
                if (!ban) {

                    vector <ii> e1;
                    for (int i = 0; i < n; ++i) {
                        int j = (i + 1) % n;
                        e1.app(mp(min(ans[i], ans[j]), max(ans[i], ans[j])));
                        j = (j + 1) % n;
                        e1.app(mp(min(ans[i], ans[j]), max(ans[i], ans[j])));
                    }   
                    sort(all(e1));

                    if (e != e1)
                        continue;

                    for (int i = 0; i < n; ++i)
                        cout << ans[i] << ' ';
                    cout << '\n';
                    exit(0);
                }
            }   
        }   
    }   
    cout << "-1\n";
}