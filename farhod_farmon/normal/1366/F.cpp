#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;
const int mod = 1e9 + 7;

using namespace std;

int n, m, q;
long long d[N];
long long f[N];
long long inf = 1e18;

vector < pair < int, int > > v[N];

long double inter(pair < long long, long long > a, pair < long long, long long > b)
{
        return (long double)(b.se - a.se) / (a.fi - b.fi);
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m >> q;

        for(int i = 0; i < N; i++){
                d[i] = f[i] = - inf;
        }

        for(int i = 1; i <= m; i++){
                int x, y, w;
                cin >> x >> y >> w;
                v[x].push_back({y, w});
                v[y].push_back({x, w});
        }
        d[1] = 0;
        long long res = 0;
        int G = min(q, n + m);
        for(int i = 1; i <= G; i++){
                for(int j = 1; j <= n; j++){
                        if(d[j] == -inf){
                                continue;
                        }
                        for(auto p: v[j]){
                                f[p.fi] = max(f[p.fi], d[j] + p.se);
                        }
                }
                long long best = -inf;
                for(int j = 1; j <= n; j++){
                        d[j] = f[j];
                        f[j] = -inf;
                        best = max(best, d[j]);
                }
                res += best % mod;
        }
        q -= G;

        map < long long, long long > D;
        for(int i = 1; i <= n; i++){
                int mx = 0;
                for(auto j: v[i]){
                        mx = max(mx, j.se);
                }
                D[mx] = max(D[mx], d[i]);
        }
        vector < pair < long long, long long > > V;
        for(auto p: D){
                while(V.size() > 1 && inter(V[V.size() - 2], p) < inter(V[V.size() - 2], V[V.size() - 1])){
                        V.pop_back();
                }
                V.push_back(p);
        }

        res %= mod;
        long long done = 0;
        for(int i = 0; i < V.size(); i++){
                long long R = q;
                if(i + 1 < V.size()){
                        long long j = min(inter(V[i], V[i + 1]), (long double)q + 10);
                        j = max(j, 0ll);
                        //cout << " " << inter(V[i], V[i + 1]) << " " << j << endl;
                        while(j >= done && V[i].fi * j + V[i].se < V[i + 1].fi * j + V[i + 1].se)j -= 1;
                        while(j <= R && V[i].fi * (j + 1) + V[i].se > V[i + 1].fi * (j + 1) + V[i + 1].se)j += 1;
                        //cout << done << " " << R << "\n";
                        R = min(R, j);
                }
                V[i].fi %= mod;
                V[i].se %= mod;
                if(R > done){
                        res += V[i].se * (R - done) % mod;
                        res += V[i].fi * (R - done) % mod * done % mod;
                        res += (R - done) * (R - done + 1) / 2 % mod * V[i].fi % mod;
                        done = R;
                }
        }

        cout << res % mod << "\n";
}