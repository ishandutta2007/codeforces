#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

lli n, a[N], mx[N], cnt;
vector < pair < lli, lli > > v[N];

void dfs(lli x, lli p)
{
    //cout << p << " " << x << endl;
    if(mx[x] > a[x])
        return;
    cnt++;
    for(int i = 0; i < v[x].size(); i++){
        lli y = v[x][i].fi, c = v[x][i].se;
        if(y == p)
            continue;
        mx[y] = max(mx[x], 0ll) + c;
        dfs(y, x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 2; i <= n; i++){
        lli x, c;
        cin >> x >> c;
        v[x].pb({i, c});
        v[i].pb({x, c});
    }
    dfs(1, 0);
    //cout << mx[9] << endl;
    cout << n - cnt << endl;
}