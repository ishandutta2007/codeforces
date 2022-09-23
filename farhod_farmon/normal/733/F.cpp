#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr prlong longf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;

using namespace std;

long long n, m;
long long S;
long long w[N];
long long a[N];
long long b[N];
long long c[N];
long long tin[N];
long long tout[N];
long long tim;
long long p[N][21];
long long mx[N][21];
long long color[N];
long long dip[N];
bool took[N];
long long sum;
vector < pair < long long, long long > > v[N];
vector < pair < long long, pair < long long, long long > > > edge;

bool cmp(pair < long long, pair < long long, long long > > x, pair < long long, pair < long long, long long > > y)
{
    return w[x.fi] < w[y.fi];
}

long long get_color(long long x)
{
    if(color[x] == x)
        return x;
    return color[x] = get_color(color[x]);
}

void dfs(long long x, long long par)
{
    dip[x] = dip[par] + 1;
    tin[x] = ++tim;
    p[x][0] = par;
    for(auto y: v[x]){
        if(y.fi == par)
            continue;
        dfs(y.fi, x);
        sum += w[y.se];
        mx[y.fi][0] = w[y.se];
    }
    tout[x] = ++tim;
}

bool ispar(long long x, long long y)
{
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}

long long get_par(long long x, long long y)
{
    if(ispar(x, y))
        return x;
    if(ispar(y, x))
        return y;
    for(long long i = 20; i >= 0; i--)
        if(!ispar(p[x][i], y))
            x = p[x][i];
    return p[x][0];
}

long long get(long long x, long long g)
{
    long long ka = 0;
    for(long long i = 20; i >= 0; i--){
        if(g >= (1 << i)){
            g -= (1 << i);
            ka = max(ka, mx[x][i]);
            x = p[x][i];
        }
    }
    return ka;
}

long long get_max(long long x, long long y)
{
    long long par = get_par(x, y);
    return max(get(x, dip[x] - dip[par]), get(y, dip[y] - dip[par]));
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(long long i = 1; i <= n; i++)
        color[i] = i;
    for(long long i = 1; i <= m; i++)
        cin >> w[i];
    for(long long i = 1; i <= m; i++)
        cin >> c[i];
    for(long long i = 1; i <= m; i++){
        long long x, y;
        cin >> x >> y;
        edge.pb({i, {x, y}});
        a[i] = x;
        b[i] = y;
    }
    cin >> S;
    sort(edge.begin(), edge.end(), cmp);
    for(long long i = 0; i < edge.size(); i++){
        long long x = edge[i].se.fi,
                  y = edge[i].se.se,
                  h = edge[i].fi;
        if(get_color(x) == get_color(y))
            continue;
        color[get_color(y)] = get_color(x);
        v[x].pb({y, h});
        v[y].pb({x, h});
    }
    dfs(1, 1);
    for(long long i = 1; i <= 20; i++){
        for(long long j = 1; j <= n; j++){
            p[j][i] = p[p[j][i - 1]][i - 1];
            mx[j][i] = max(mx[j][i - 1], mx[p[j][i - 1]][i - 1]);
        }
    }
    long long ans = 1e18,
              in = -1;
    for(long long i = 1; i <= m; i++){
        long long x = a[i],
                  y = b[i];
        long long l = w[i] - S / c[i];
        if(sum - get_max(x, y) + l < ans){
            ans = sum - get_max(x, y) + l;
            in = i;
        }
    }
    for(long long i = 1; i <= n; i++)
        color[i] = i;
    color[a[in]] = b[in];
    w[in] -= S / c[in];
    took[in] = true;
    ans = w[in];
    for(long long i = 0; i < edge.size(); i++){
        long long x = edge[i].se.fi,
                  y = edge[i].se.se,
                  h = edge[i].fi;
        if(get_color(x) == get_color(y) || h == in)
            continue;
        took[h] = true;
        ans += w[h];
        color[get_color(y)] = get_color(x);
    }
    cout << ans << endl;
    for(long long i = 1; i <= m; i++){
        if(!took[i])
            continue;
        cout << i << " " << w[i] << endl;
    }
}