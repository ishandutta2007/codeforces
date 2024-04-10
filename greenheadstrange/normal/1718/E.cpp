//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
using namespace std;
const int maxn = 300005;
int n, m;
int gid(int a, int b) {
    return (a - 1) * m + b;
}
const ll mod = 10000000000037ll;
const int base = maxn + 10;
int a[maxn], b[maxn];
vi eg[maxn];
int to[maxn];
int hv[maxn];
int id[maxn];
int tid;
int q[maxn], inq[maxn], vis[maxn];
int comped[maxn];
int ok[maxn];
mt19937 rd;
vector<pair<vi, ll> > cal(int* S) {
    for (int i = 1; i <= tid; i++)
        eg[i].clear();
    for (int i = 1; i <= n; i++) {
        vector<pi> cr;
        for (int j = 1; j <= m; j++) {
            int a = S[gid(i, j)];
            if (a) cr.pb(mp(a, j + n));
        }
        sort(cr.begin(), cr.end());
        for (auto [u, v] : cr) eg[i].pb(v);
    }
    for (int j = 1; j <= m; j++) {
        vector<pi> cr;
        for (int i = 1; i <= n; i++) {
            int a = S[gid(i, j)];
            if (a)
                cr.pb(mp(a, i));
        }
        sort(cr.begin(), cr.end());
        for (auto [u, v] : cr)
            eg[j + n].pb(v);
    }
    vector<pair<vi, ll> > res;
    int l = 1, r = n;
    if (m < n) l = n + 1, r = n + m;
    memset(vis, 0, sizeof(vis));
    memset(ok, 0, sizeof(ok));
    for (int i = l; i <= r; i++) {
        if (!ok[i] && vis[i]) continue;
        for (int j = 1; j <= tid; j++) inq[j] = 0;
        int fr = 0, ed = 0;
        q[ed++] = i; inq[i] = 1;
        while (fr < ed) {
            int h = q[fr++];
            for (auto v : eg[h]) {
                if (inq[v]) continue;
                q[ed++] = v; inq[v] = 1;
            }
        }
        vi cur(ed);
        for (int j = 0; j < ed; j++) cur[j] = q[j];
        ll hs = 0;
        for (int j = 0; j < ed; j++)
            if (q[j] <= n) hs = (hs * base + maxn) % mod;
            else hs = (hs * base + maxn + 1) % mod;
            
        for (int j = 0; j < ed; j++) {
            if (q[j] >= l && q[j] <= r) {
                for (int k = 0; k < ed; k++) {
                    int a = q[j], b = q[k];
                    if (a > b) swap(a, b);
                    int eid = 0;
                    if (a > n || b <= n) eid = 0;
                    else eid = S[gid(a, b - n)];
                    hs = (hs * base + eid) % mod;
                }
            }
        }
        if (!vis[i]) {
            int tots = 0;
            vi nru;
            for (auto v : cur)
                if (v >= l && v <= r) nru.pb(v);
            shuffle(nru.begin(), nru.end(), rd);
            int msize = 40;
            if (nru.size() > msize)
                nru.resize(msize);
            for (auto v : nru)
                ok[v] = 1;
        }

        for (auto v : cur) vis[v] = 1;
        res.pb(mp(cur, hs));   
    }
    return res;
}
void otp(vi a) {
    for (auto x : a)
        cout << x << " ";
    cout << endl;
}
int main() {
    cin >> n >> m;
    tid = n + m;
    for (int i = 1; i <= n * m; i++)
        scanf("%d", &a[i]);
    auto res = cal(a);
    for (int i = 1; i <= n * m; i++)
        scanf("%d", &b[i]);
    auto res2 = cal(b);
    int flag = 1;
    int u = res.size(), v = res2.size();
    for (int i = 0; i < u; i++) {
        if (comped[res[i].fi[0]]) continue;
        for (int j = 0; j < v; j++) {
            if (hv[res2[j].fi[0]]) continue;
            if (res[i].se == res2[j].se) {
                int r = res[i].fi.size();
                for (int k = 0; k < r; k++)
                    to[res[i].fi[k]] = res2[j].fi[k];
                for (auto v : res2[j].fi)
                    hv[v] = 1;
                for (auto v : res[i].fi)
                    comped[v] = 1;
                break;
            }
        }
    }
    vi nv[2];
    for (int j = 0; j < 2; j++) {
        memset(vis, 0, sizeof(vis));
        auto cur = res;
        if (j == 1) cur = res2;
        for (auto a : cur)
            for (auto v : a.fi)
                vis[v] = 1;
        for (int i = 1; i <= tid; i++)
            if (!vis[i]) nv[j].pb(i);
    }
    if (nv[0].size() != nv[1].size()) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < nv[0].size(); i++) {
        int a = nv[0][i], b = nv[1][i];
        to[a] = b;
    }
    for (int i = 1; i <= tid; i++) id[i] = i;
    for (int j = 1; j <= tid; j++)
        if (!to[j])
        {
            cout << "-1" << endl;
            return 0;
        }
    vector<pi> acts[2];
    for (int t = 0; t < 2; t++) {
        int l = 1, r = n;
        if (t == 1) l = n + 1, r = n + m;
        for (int j = l; j <= r; j++) {
            int cnt = 0;
            while (1) {
                cnt += 1;
                if (cnt >= r - l + 5) {
                    exit(1);
                }
                int e = to[id[j]];
                if (e == j) break;
                acts[t].pb(mp(j, e));
                swap(id[j], id[e]);
            }
        }
    }
    cout << acts[0].size() + acts[1].size() << endl;
    for (int i = 0; i < 2; i++) {
        for (auto [u, v] : acts[i]) {
            if (u > n) u -= n;
            if (v > n) v -= n;
            printf("%d %d %d\n", i + 1, u, v);
        }
    }
    return (0-0); //<3
}