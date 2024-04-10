#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

long long n, m, L, s, t;
long long W[N][N];
long long d[N];
long long a[N * 10];
long long b[N * 10];
vector < long long > v[N];
vector < long long > g;

long long get(long long o)
{
    for(int i = 0; i < g.size(); i++){
        int x = a[g[i]],
            y = b[g[i]];
        W[x][y] = W[y][x] = o / g.size();
        if(i < o % g.size())
            W[x][y]++,
            W[y][x]++;
    }
    set < pair < long long, long long > > se;
    for(int i = 0; i < n; i++)
        d[i] = 1e18;
    d[s] = 0;
    se.insert({0, s});
    while(!se.empty()){
        int x = se.begin()->se;
        se.erase(se.begin());
        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i],
                w = W[x][y];
            if(d[x] + w < d[y]){
                se.erase({d[y], y});
                d[y] = d[x] + w;
                se.insert({d[y], y});
            }
        }
    }
    return d[t];
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> L >> s >> t;
    for(int i = 0; i < m; i++){
        long long w;
        cin >> a[i] >> b[i] >> w;
        if(w == 0)
            g.pb(i);
        W[a[i]][b[i]] = W[b[i]][a[i]] = w;
        v[a[i]].pb(b[i]);
        v[b[i]].pb(a[i]);
    }
    long long l = g.size(),
              r = (1e9 + 1) * (long long)(g.size());
    while(l < r){
        long long mid = (l + r) / 2 + 1;
        if(get(mid) <= L)
            l = mid;
        else
            r = mid - 1;
    }
    if(get(l) != L){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i = 0; i < m; i++)
        cout << a[i] << " " << b[i] << " " << W[a[i]][b[i]] << "\n";
}