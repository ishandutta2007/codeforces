#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-reorder-functions")
#pragma GCC optimize("profile-values")
#pragma GCC optimize("tracer")
#pragma GCC optimize("vpt")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("ssse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("avx")
#pragma GCC target("avx2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")
#include<bits/stdc++.h>
using namespace std;
const int NN = 100001;
const int D = 51;
const int N = NN * D;
int n, m, d;
vector <int> g1[NN], rg1[NN];
int cost[N];
string str[NN];
int topptr = 0;
int top[N];
bool used1[N], used2[N];
int comp[N];
int v[N];
int ptr = 0;
int cp[N];
void dfs1(int u) {
    stack <int> st;
    st.push(u);
    while (st.size()) {
        int u = st.top();
        used1[u] = 1;
        int u1 = u / d, i = u - u1 * d;
        int j = 0;
        if (i + 1 < d) j = i + 1;
        if (cp[u] == (int)g1[u1].size()) {
            st.pop();
            top[topptr++] = u;
            continue;
        }   
        int v1 = g1[u1][cp[u]++];
        int v = v1 * d + j;
        if (!used1[v]) {
            st.push(v);
        }   
    }   
}   
void bfs(int u, int c) {
    queue <int> q;
    q.push(u);
    used2[u] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        int u1 = u / d, i = u - u1 * d;
        int j = d - 1;
        if (i) j = i - 1;
        if (str[u1][i] == '1') {
            v[ptr++] = u1;
        }   
        comp[u] = c;
        for (int v1 : rg1[u1]) {
            int v = v1 * d + j;
            if (used1[v] && !used2[v]) {
                used2[v] = 1;
                q.push(v);
            }   
        }   
    }   
}   
int compr() {
    dfs1(0);
    reverse(top, top + topptr);
    int c = 0;
    for (int i = 0; i < topptr; ++i) {
        int u = top[i];
        if (!used2[u]) {
            ptr = 0;
            bfs(u, c);
            sort(v, v + ptr);
            cost[c] = unique(v, v + ptr) - v;
            ++c;
        }   
    }   
    return comp[0];
}   
int dp[N];
void calc() {
    for (int i = 0; i < N; ++i) dp[i] = cost[i];
    int n = topptr;
    reverse(top, top + n);
    for (int ii = 0; ii < n; ++ii) {
        int u = top[ii];
        int c = comp[u];
        int u1 = u / d, i = u - u1 * d;
        int j = 0;
        if (i + 1 < d) j = i + 1;
        for (int v1 : g1[u1]) {
            int v = v1 * d + j;
            int vc = comp[v];
            if (vc == c) continue;
            dp[c] = max(dp[c], dp[vc] + cost[c]);
        }   
    }   
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif  
    cin >> n >> m >> d;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g1[u].push_back(v);
        rg1[v].push_back(u);
    }   
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }   
    int v = compr();
    calc();
    cout << dp[v] << '\n';
}