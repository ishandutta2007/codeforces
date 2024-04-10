#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define SZ(x)(int((x).size()))
#define ALL(x)(x).begin(), (x).end()

template <typename T> inline bool chkmin(T & a,
    const T & b) {
    return b < a ? a = b, 1 : 0;
}
template <typename T> inline bool chkmax(T & a,
    const T & b) {
    return a < b ? a = b, 1 : 0;
}

typedef long long LL;

const LL infinity = 0x3f3f3f3f3f3f3f3f;
const LL mod = 1e9 + 7;
const int M = 2e3 + 3;

int seen[M] = {0};
int l[M];
map <pair<int, int>, int> g;
vector <vector<int>> d(M);

vector <int> query(int n, int current) {
    vector <int> v(n);
    cout << "? " << current << endl;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}

void solve() {
    int n;
    cin >> n;
    vector <int> v = query(n, 1);
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            g[mp(1, 1 + i)] = 1;
            seen[1 + i] = 1;
        }
        l[1 + i] = v[i];
        d[v[i]].pb(1 + i);
    }
    seen[1] = 1;
    for (int h = 2; h <= *max_element(l + 1, l + n + 1); ++h) {
        for (int j = 0; j < SZ(d[h]); ++j) {
            int cur = d[h][j];
            if (!seen[cur]) {
                int gr = -1, p = -1;
                seen[cur] = 1;
                vector <int> z = query(n, cur);
                vector <int> b;
                for (int i = 0; i < n; i++) {
                    if (z[i] == 2 && l[i + 1] == l[cur] - 2) {
                        gr = i + 1;
                    }
                    if (z[i] == 1 && l[i + 1] == l[cur] - 1) {
                        p = i + 1;
                    }
                    if (z[i] == 2 && l[i + 1] == l[cur]) {
                        b.pb(i + 1);
                    }
                    if (z[i] == 1 && l[i + 1] == l[cur] + 1) {
                        seen[i + 1] = 1;
                        g[mp(cur, 1 + i)] = 1;
                    }
                }
                g[mp(gr, p)] = 1;
                seen[p] = 1;
                g[mp(p, cur)] = 1;
                for (int k = 0; k < SZ(b); k++) {
                    int c = b[k];
                    g[mp(p, c)] = 1;
                    seen[c] = 1;
                }
            }
        }
    }
    for (int cur = 1; cur <= n; cur++) {
        if (!seen[cur]) {
            int p = -1;
            seen[cur] = 1;
            vector <int> z = query(n, cur);
            vector <int> b;
            for (int i = 0; i < n; i++) {
                if (z[i] == 1 && l[i + 1] == l[cur] - 1) {
                    p = i + 1;
                }
                if (z[i] == 2 && l[i + 1] == l[cur]) {
                    b.pb(i + 1);
                }
            }
            g[mp(p, cur)] = 1;
            for (int k = 0; k < SZ(b); k++) {
                int c = b[k];
                g[mp(p, c)] = 1;
                seen[c] = 1;
            }
        }
    }
    cout << "! " << endl;
    for (pair <pair<int, int>, int> cur: g) {
        cout << cur.f.f << " " << cur.f.s << endl;
    }
    return;
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}