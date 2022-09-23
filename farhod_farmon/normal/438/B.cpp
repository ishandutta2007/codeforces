#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

long long n, m;
long long p[N];
long long sz[N];
long long ans;
pair < long long, long long > a[N];
vector < long long > v[N];
bool used[N];
int us[N];

long long get(long long x)
{
    if(x == p[x])
        return x;
    return p[x] = get(p[x]);
}

void mrge(long long x, long long y)
{
    x = get(x);
    y = get(y);
    if(x == y)
        return;
    sz[x] += sz[y];
    p[y] = x;
}

void add(long long x, long long g)
{
    used[x] = true;
    long long s = 0;
    vector < long long > k;
    for(int i = 0; i < v[x].size(); i++){
        long long y = v[x][i];
        if(!used[y])
            continue;
        y = get(y);
        if(us[y] == x)
            continue;
        us[y] = x;
        s += sz[get(y)];
        k.pb(y);
    }
    ans += s * g;
    for(int i = 0; i < k.size(); i++){
        long long y = k[i];
        ans += sz[get(y)] * (s - sz[get(y)]) * g;
        s -= sz[get(y)];
        mrge(x, y);
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
        p[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i <= m; i++){
        long long x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    sort(a + 1, a + n + 1);
    for(int i = n; i >= 1; i--){
        add(a[i].se, a[i].fi);
        //cout << a[i].se << " " << a[i].fi << " " << ans << endl;
    }
    ans = ans + ans;
    cout << fixed << setprecision(6) << 1.0 * ans / (1.0 * n * (n - 1)) << endl;
}