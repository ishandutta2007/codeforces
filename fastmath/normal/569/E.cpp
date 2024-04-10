#include <bits/stdc++.h>

using namespace std;

#define int long long

const int M = 201;
const int N = 501;

vector <int> g[N], ng[N], rg[N];

int n, m;
string al;

bool gett(char c) {
    return c == 'C';
}   

bool gett1(char c) {
    return gett(al[c - 'a']);
}   

void add(int u, bool ut, int v, bool vt, vector <int> g[]) {
    g[u + M * ut].push_back(v + M * vt);
    g[v + M * (!vt)].push_back(u + M * (!ut));
}   

bool used[N];
void dfs1(int u, vector <int> &tp) {
    used[u] = 1;
    for (int v : ng[u]) {
        if (!used[v]) {
            dfs1(v, tp);
        }   
    }      
    tp.push_back(u);
}   

int comp[N];
void dfs2(int u, int c) {
    used[u] = 1;
    comp[u] = c;
    for (int v : rg[u]) {
        if (!used[v]) {
            dfs2(v, c);
        }   
    }   
}   

bool check(vector <bool> pr) {
    for (int i = 0; i < N; ++i) {
        rg[i].clear();
    }   
    for (int i = 0; i < N; ++i) {
        ng[i] = g[i];
    }
    for (int i = 0; i < (int)pr.size(); ++i) {
        add(i, !pr[i], i, pr[i], ng);
    }
    for (int u = 0; u < N; ++u) {
        for (int v : ng[u]) {
            rg[v].push_back(u);
        }   
    }   
    memset(used, 0, sizeof used);
    vector <int> tp;
    for (int u = 0; u < N; ++u) {
        if (!used[u]) {
            dfs1(u, tp);
        }   
    }
    reverse(tp.begin(), tp.end());
    memset(used, 0, sizeof used);
    int c = 0;
    for (int u : tp) {
        if (!used[u]) {
            dfs2(u, c++);
        }   
    }   
    for (int u = 0; u < n; ++u) {
        if (comp[u] == comp[u + M]) {
            return 0;
        }   
    }   
    return 1;
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> al;
    cin >> n >> m;
    vector <int> cnt(2);
    for (int c : al) {
        ++cnt[gett(c)];
    }   
    if (!cnt[0]) {
        for (int i = 0; i < n; ++i) {
            add(i, 0, i, 1, g);
        }   
    }   
    if (!cnt[1]) {
        for (int i = 0; i < n; ++i) {
            add(i, 1, i, 0, g);
        }   
    }   
    for (int i = 0; i < m; ++i) {
        int p1, p2;
        char t1, t2;
        cin >> p1 >> t1 >> p2 >> t2;
        --p1; --p2;
        add(p1, gett(t1), p2, gett(t2), g);
    }   
    string s;
    cin >> s;
    vector <bool> t;
    for (int i = 0; i < n; ++i) {
        t.push_back(gett1(s[i]));
    }   
    if (check(t)) {
        cout << s << '\n';
        exit(0);
    }
    for (int i = n - 1; i >= 0; --i) {
        vector <bool> pr;
        for (int t = 0; t < i; ++t) {
            pr.push_back(gett1(s[t]));
        }   
        vector <bool> can(2);
        for (int t = 0; t <= 1; ++t) {
            pr.push_back(t);
            can[t] = check(pr);
            pr.pop_back();
        }   
        for (char c = s[i] + 1; c < 'a' + (int)al.size(); ++c) {
            if (can[gett1(c)]) {
                string ans;
                for (int t = 0; t < i; ++t) {
                    ans += s[t];
                }   
                ans += c;
                pr.push_back(gett1(c));
                for (int t = i + 1; t < n; ++t) {
                    vector <bool> can(2);
                    for (int nt = 0; nt <= 1; ++nt) {
                        pr.push_back(nt);
                        can[nt] = check(pr);
                        pr.pop_back();
                    }
                    for (char c = 'a'; c < 'a' + (int)al.size(); ++c) {
                        if (can[gett1(c)]) {
                            ans += c;
                            pr.push_back(gett1(c));
                            break;
                        }   
                    }   
                }   
                cout << ans << '\n';
                exit(0);
            }   
        }   
    }   

    cout << "-1\n";
    return 0;
}