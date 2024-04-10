#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
#define HOME

const int N = 1e6+7;
vector <int> g[N], a[N];
vector <int> ans[2];

signed main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int i = 0; i < 2 * n; ++i) {
            cout << (i % n) + 1 << ' ';
        }
        cout << endl;
    }
    else {
        cout << "Second" << endl;
        for (int i = 1; i <= 2 * n; ++i) {
            int x;
            cin >> x;
            a[x].app(i);
        }
        for (int i = 1; i <= n; ++i) {
            int u = a[i][0], v = a[i][1];
            g[u].app(v); g[v].app(u);
        }
        for (int i = 1; i <= n; ++i) {
            g[i].app(i + n);
            g[i + n].app(i);
        }

        vector <bool> used(2 * n + 1);
        for (int i = 1; i <= 2 * n; ++i) {
            if (!used[i]) {
                int u = i;
                vector <int> c;
                while (1) {
                    used[u] = 1;
                    c.app(u);
                    int v = -1;
                    for (int t : g[u]) {
                        if (!used[t]) {
                            v = t;
                            break;
                        }
                    }
                    if (v == -1)
                        break;
                    u = v;
                }

                for (int j = 0; j < c.size(); ++j)
                    ans[j&1].app(c[j]);
            }
        }

        int sum = 0;
        for (auto e : ans[0])
            sum += e;
        if (sum % (2 * n)) {
            for (auto e : ans[1])
                cout << e << ' ';
            cout << endl;
        }
        else {
            for (auto e : ans[0])
                cout << e << ' ';
            cout << endl;
        }
    }

    int t;
    cin >> t;
}