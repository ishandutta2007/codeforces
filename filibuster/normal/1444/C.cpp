#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 5e5 + 13;
const int B = 350;

vector<int> g[N];
int a[N]; // statements
int c[N]; // my colors
bool used[N];
int gr[N]; // for comp what group
bool is[N]; // for group is correct
vector<int> group[N];


void dfs1(int v, int c1) {
    c[v] = c1;
    used[v] = true;

    for(auto u : g[v])
        if(a[v] == a[u]) {
            if(!used[u])
                 dfs1(u, c1 ^ 1);
            else if(c[v] == c[u])
                is[a[v]] = false;
        }

}

map<int, int> ccol;
vector<int> cg[N * 2];
bool fl = false;

void dfs2(int v, int cl) {
    ccol[v] = cl;
//    cout << "dfs2 " << v << ' ' << cl << endl;

    for(auto u : cg[v]) {
        if(ccol.count(u)) {
            if(ccol[u] == cl) {
                fl = true;
//                cout << "dfs2 error " << v << ' '<< u << endl;
            }

        } else {
            dfs2(u, cl ^ 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];

        a[i]--;

        group[a[i]].push_back(i);
    }


    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    for(int i = 0; i < k; i++)
        is[i] = true;

    int col = 0;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            dfs1(i, col * 2);
            gr[col] = a[i];
            col++;
        }
    }

//    for(int i = 0; i < n; i++) {
//        cout << c[i] << ' ';
//    }
//    cout<< endl;

    int cnt = 0; // cnt correct
    for(int i = 0; i < k; i++)
        cnt += is[i];

//    cout << cnt << endl;

    li ans = 0;
    for(int i = 0; i < k; i++) {
        if(!is[i])
            continue;

//        cout << endl << endl << "next group " << i << endl;

//        map<int, vector<int>> mp;
        map<int, vector<pii>> e;
        set<int> cmp;
        for(auto v : group[i]) {
            for(auto u : g[v]) {
                if(a[v] != a[u] && is[a[u]]) {
//                    mp[a[u]].push_back(u);
                    e[a[u]].emplace_back(v, u);
                    cmp.insert(a[u]);
                }
            }
        }

        ans += cnt - cmp.size() - 1;

        vector<int> lst;
        for(auto j : cmp) {
//            cout << "other " << j << endl;


//            for(int l = 0; l < n * 2; l++)
//                if(!cg[l].empty())
//                    cout << "not empty" << endl;

            fl = false;
            for(auto ed : e[j]) {
                int v = c[ed.f], u = c[ed.s];
//                cout << v << ' ' << u << endl;
                lst.push_back(v);
                lst.push_back(u);
                lst.push_back(v ^ 1);
                lst.push_back(u ^ 1);

                cg[v].push_back(u);
                cg[u].push_back(v);
                cg[v].push_back(v ^ 1);
                cg[v ^ 1].push_back(v);
                cg[u].push_back(u ^ 1);
                cg[u ^ 1].push_back(u);
            }

            for(auto v : lst)
                if(ccol.count(v) == 0)
                    dfs2(v, 0);

//            cout << fl << endl;
            if(!fl)
                ans++;

            ccol.erase(ccol.begin(), ccol.end());
            for(auto x : lst)
                cg[x].erase(cg[x].begin(), cg[x].end());
            lst.erase(lst.begin(), lst.end());

        }
//        for(auto j : cmp) {
//            for(auto ed : e[j]) {
//                int v = ed.f, u = ed.s;
//                if(rev.count(c[u] / 2)) {
//
//                } else {
//                    if(rev.count(c[v] / 2))
//                        rev[c[u] / 2] = (c[v] - c[u]) % 2;
//                }
//            }
//        }
    }

    cout << ans / 2 << endl;
}