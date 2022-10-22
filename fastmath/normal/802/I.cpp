#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;
const int K = 26;

struct Node {
    bool term;
    int link, len;
    map <char, int> go;
};  

Node d[MAXN];
bool used[MAXN];
int dp1[MAXN], dp2[MAXN];

int last = -1;
int u = -1;
void add(char c) {
    int curr = u++;
    d[curr].len = d[last].len + 1;

    int p;
    for (p = last; p != -1 && d[p].go.find(c) == d[p].go.end(); p = d[p].link) {
        d[p].go[c] = curr;
    }   

    if (p == -1) {  
        d[curr].link = 0;
    }
    else {
        int q = d[p].go[c];
        if (d[p].len + 1 == d[q].len) {
            d[curr].link = q;
        }   
        else {
            int clone = u++;
            d[clone].link = d[q].link;
            d[clone].len = d[p].len + 1;
            d[clone].go = d[q].go;
            d[q].link = d[curr].link = clone;
            for (int t = p; t != -1 && d[t].go[c] == q; t = d[t].link) {
                d[t].go[c] = clone;
            }   
        }   
    }   

    last = curr;
}   

vector <int> topsort;
void dfs(int u) {
    used[u] = 1;
    for (auto e : d[u].go) {
        int v = e.second;
        if (!used[v]) {
            dfs(v);
        }   
    }   
    topsort.push_back(u);
}   

void solve() {
    for (int i = 0; i < MAXN; ++i) {
        dp1[i] = dp2[i] = 0;
        d[i].term = 0;
        d[i].link = -1;
        d[i].len = 0;
        d[i].go.clear();
    }

    string s;
    cin >> s;

    last = 0;
    u = 1;
    for (char c : s) {
        add(c);
    }   

    topsort.clear();
    memset(used, 0, sizeof used);
    dfs(0);
    reverse(topsort.begin(), topsort.end());
    
    dp1[0] = 1;
    for (int u : topsort) {
        for (auto e : d[u].go) {
            int v = e.second;
            dp1[v] += dp1[u];
        }   
    }   
    
    int t = last;
    while (t != -1) {
        d[t].term = 1;
        t = d[t].link;
    }   

    reverse(topsort.begin(), topsort.end());
    for (int u : topsort) {
        dp2[u] = d[u].term;
        for (auto e : d[u].go) {
            int v = e.second;
            dp2[u] += dp2[v];
        }   
    }   

    int ans = 0;
    for (int i = 1; i < u; ++i) {
        ans += dp1[i] * dp2[i] * dp2[i];
    }   

    cout << ans << '\n';
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }   

    return 0;
}