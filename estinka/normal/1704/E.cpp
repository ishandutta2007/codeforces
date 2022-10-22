#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

const int mod = 998244353;
void upd(int& a, int b) { a = (a + b) % mod; }
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (a * 1ll * b) % mod; }
int pwr(int a, int b = mod - 2)
{
    if (!b) return 1;
    int h = pwr(a, b >> 1);
    h = mul(h, h);
    if (b & 1) h = mul(h, a);
    return h;
}

int n, m;
vector<vector<int> > in, out;
vector<int> vis;
vector<vector<int> > d; // d[u][i] = kvapne zo mna voda v i-tej sekunde?
vector<int> sum, a; // kolko z neho ide v n-tej sekunde alebo neskor
bool o = false;
void dfs(int u) // zisti tie intervaly
{
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : in[u]) dfs(v);
    sum[u] = a[u];
    for (int s = 0; s < n; s++) 
    {
        if (sum[u]) d[u][s] = 1, sum[u]--;
        for (int v : in[u]) sum[u] += d[v][s];
    }
    if (sum[u]) o = true;
    sum[u] %= mod;
    for (int v : in[u]) upd(sum[u], sum[v]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        o = false;
        cin >> n >> m;
        in.assign(n, {});
        out.assign(n, {});
        vis.assign(n, 0);
        d.assign(n, vector<int>(n, 0));
        sum.assign(n, 0);
        a.assign(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            out[--a].push_back(--b);
            in[b].push_back(a);
        }
        int r = -1;
        for (int i = 0; i < n; i++) if (out[i].empty()) r = i;
        dfs(r);
        int ans = 0;
        if (!o)
        {
            for (int i = 0; i < n; i++) if (d[r][i]) ans = i + 1;
        }
        else
        {
            ans = (n + sum[r]) % mod;
        }
        //cout << "                            ";
        cout << ans << "\n";
    }
    return 0;
}