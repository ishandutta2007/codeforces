#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200100;

using namespace std;

vector < lli > v[N];
lli n, down[N], up[N], k, s[N], a[N];
lli ans;

void f(lli x, lli p)
{
    s[x] = a[x];
    for(int i = 0; i < v[x].size(); i++){
        lli y = v[x][i];
        if(y == p)
            continue;
        f(y, x);
        s[x] += s[y];
        down[x] += down[y] + s[y];
    }
}

void dfs(lli x, lli p)
{
    lli mx = k + k - s[x];
    for(int i = 0; i < v[x].size(); i++){
        lli y = v[x][i];
        if(y == p)
            continue;
        up[y] = up[x] + down[x] - down[y] - s[y] + k + k - s[y];
        dfs(y, x);
        mx = max(mx, s[y]);
    }
    if(mx <= k)
        ans = max(ans, up[x] + down[x]);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= k + k; i++){
        lli x;
        cin >> x;
        a[x] = 1;
    }
    for(int i = 1; i < n; i++){
        lli x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    f(1, -1);
    dfs(1, -1);
    cout << ans << endl;
}