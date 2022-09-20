#include <bits/stdc++.h>
 
#define fi first
#define se second
 
const int N = 1000100;
 
using namespace std;
 
struct fenw
{
        long long t[N];
        int c[N];
 
        void clear()
        {
                for(int i = N - 1; i >= 0; i--){
                        t[i] = c[i] = 0;
                }
        }
 
        void upd(int x, int y, int c_)
        {
                while(x < N){
                        t[x] += y;
                        c[x] += c_;
                        x += x & -x;
                }
        }
 
        void updt(int x, int y)
        {
                while(x < N){
                        t[x] += y;
                        x += x & -x;
                }
        }
        void updc(int x, int y)
        {
                while(x < N){
                        c[x] += y;
                        x += x & -x;
                }
        }
 
        long long gett(int x)
        {
                int res = 0;
                while(x > 0){
                        res += t[x];
                        x -= x & -x;
                }
                return res;
        }
        int getc(int x)
        {
                int res = 0;
                while(x > 0){
                        res += c[x];
                        x -= x & -x;
                }
                return res;
        }
        int get(int x)
        {
                return 1ll * x * getc(x) - gett(x);
        }
        int get(int l, int r)
        {
                return get(r) - get(l - 1);
        }
};
 
int n;
long long a[N];
int b[N];
fenw A, B;
vector<pair<pair<int, int>, pair<int, int>>> V[61], G[61];
 
int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);
 
        cin >> n;
        int mx = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                b[i] = __builtin_popcountll(a[i]);
                mx = max(mx, b[i]);
        }
 
        vector<int> v, g;
        v.reserve(n + 1);
        g.reserve(n + 1);
        v.push_back(0);
        g.push_back(0);
 
        for(int i = 1; i <= n; i++){
                while(v.size() > 1 && a[i] >= a[v.back()]){
                        V[b[v.back()]].push_back({{i, -1}, {v[v.size() - 2] + 1, v[v.size() - 1]}});
                        v.pop_back();
                }
                while(g.size() > 1 && a[i] <= a[g.back()]){
                        G[b[g.back()]].push_back({{i, -1}, {g[g.size() - 2] + 1, g[g.size() - 1]}});
                        g.pop_back();
                }
                V[b[i]].push_back({{i, 1}, {v.back() + 1, i}});
                G[b[i]].push_back({{i, 1}, {g.back() + 1, i}});
                v.push_back(i);
                g.push_back(i);
        }
 
        long long res = 0;
 
        for(int it = 0; it <= mx; it++){
                A.clear();
                B.clear();
                long long all = 0;
 
                for(int i = 1, j = 0, h = 0; i <= n; i++){
                        while(j < V[it].size() && V[it][j].fi.fi == i){
                                int l = V[it][j].se.fi, r = V[it][j].se.se, z = V[it][j].fi.se;
                                all += B.get(l, r) * z;
                                A.upd(l, (l - 1) * z, z);
                                A.upd(r + 1, (1 - l) * z, -z);
                                A.updt(r + 1, (l - r - 1) * z);
                                j += 1;
                        }
                        while(h < G[it].size() && G[it][h].fi.fi == i){
                                int l = G[it][h].se.fi, r = G[it][h].se.se, z = G[it][h].fi.se;
                                all += A.get(l, r) * z;
                                B.upd(l, (l - 1) * z, z);
                                B.upd(r + 1, (1 - l) * z, -z);
                                B.updt(r + 1, (l - r - 1) * z);
                                h += 1;
                        }
                        res += all;
                }
        }
 
        cout << res << "\n";
}