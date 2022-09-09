#include<bits/stdc++.h>
using namespace std;
using LL = long long;
struct Node{
    int f, a, b, c, d;
};
#define ls (v << 1)
#define rs (ls | 1)
#define tm (((tl + tr) >> 1) + (((tl + tr) >> 1) & 1))
struct Seg{
    int n, MOD;
    vector<vector<int>> f;
    vector<Node> nodes;
    void up(Node& v, Node& L, Node& R) {
        if (L.f and R.f and (L.c + L.d) % MOD == R.a and (L.d + R.a) % MOD == R.b) {
            v.f = 1;
            v.a = (v.a + L.a) % MOD;
            v.b = (v.b + L.b) % MOD;
            v.c = (v.c + R.c) % MOD;
            v.d = (v.d + R.d) % MOD;
            L.a = L.b = L.c = L.d = 0;
            R.a = R.b = R.c = R.d = 0;
        }
        else v.f = 0;
    }
    Seg(int n, int MOD, const vector<int>& a) : n(n), MOD(MOD), f(2, vector<int>(n + 1)), nodes(n << 2) {
        f[0][1] = f[0][2] = 1 % MOD;
        for (int i = 3; i <= n; i += 1) f[0][i] = (f[0][i - 1] + f[0][i - 2]) % MOD;
        for (int i = 1; i <= n; i += 1) f[1][i] = (MOD - f[0][i]) % MOD;
        function<void(int, int, int)> DFS = [&](int v, int tl, int tr){
            if (tl + 1 == tr)
                nodes[v] = {1, a[tl], a[tr], a[tl], a[tr]};
            else {
                DFS(ls, tl, tm);
                DFS(rs, tm + 1, tr);
                up(nodes[v], nodes[ls], nodes[rs]);
            }
            //cout << tl << " " << tr << " " << nodes[v].f << " " << nodes[v].a << " " << nodes[v].b << " " << nodes[v].c << " " << nodes[v].d << "\n";
        };
        DFS(1, 1, n);
    }
    void add(int i, int L, int R) {
        function<void(int, int, int)> DFS = [&](int v, int tl, int tr){
            if (tl + 1 == tr) {
                if (tl >= L and tl <= R) {
                    nodes[v].a = (nodes[v].a + f[i][tl - L + 1]) % MOD;
                    nodes[v].c = (nodes[v].c + f[i][tl - L + 1]) % MOD;
                }
                if (tr >= L and tr <= R) {
                    nodes[v].b = (nodes[v].b + f[i][tr - L + 1]) % MOD;
                    nodes[v].d = (nodes[v].d + f[i][tr - L + 1]) % MOD;
                }
            }
            else if (tl >= L and tr <= R) {
                nodes[v].a = (nodes[v].a + f[i][tl - L + 1]) % MOD;
                nodes[v].b = (nodes[v].b + f[i][tl - L + 2]) % MOD;
                nodes[v].c = (nodes[v].c + f[i][tr - L + 0]) % MOD;
                nodes[v].d = (nodes[v].d + f[i][tr - L + 1]) % MOD;
            }
            else {
                if (L <= tm) DFS(ls, tl, tm);
                if (R > tm) DFS(rs, tm + 1, tr);
                up(nodes[v], nodes[ls], nodes[rs]);
            }
            //cout << tl << " " << tr << " " << nodes[v].f << " " << nodes[v].a << " " << nodes[v].b << " " << nodes[v].c << " " << nodes[v].d << "\n";
        };
        DFS(1, 1, n);
    }
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, q, MOD;
    cin >> n >> q >> MOD;
    vector<int> a(n + 2);
    for (int i = 1, A; i <= n; i += 1) {
        cin >> A;
        a[i] = A;
    }
    for (int i = 1, B; i <= n; i += 1) {
        cin >> B;
        a[i] = (a[i] + MOD - B) % MOD;
    }
    if (n & 1) n += 1;
    Seg seg(n, MOD, a);
    for (int i = 1; i <= q; i += 1) {
        string s;
        int L, R;
        cin >> s >> L >> R;
        seg.add(s == "B", L, R);
        cout << (seg.nodes[1].f and not seg.nodes[1].a and not seg.nodes[1].b ? "YES\n" : "NO\n");
    }
}