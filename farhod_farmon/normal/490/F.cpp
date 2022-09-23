#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 6060;

using namespace std;

int n, a[N], ans, f[N];
vector < int > v[N];

void dfs(int x, int p)
{
    int l = 1,
        r = ans + 1;
    while(l < r){
        int m = (l + r) / 2;
        if(f[m] < a[x])
            l = m + 1;
        else
            r = m;
    }
    //cout << p << " " << x << " " << l << " " << f[l] << endl;
    ans = max(ans, l);
    int prev = f[l];
    f[l] = a[x];
    for(int i = 0; i < v[x].size(); i++)
        if(v[x][i] != p)
            dfs(v[x][i], x);
    //cout << "out " << x << " " << prev << endl;
    f[l] = prev;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i = 1; i < N; i++)
        f[i] = 1e9;
    for(int i = 1; i <= n; i++)
        dfs(i, -1);
    cout << ans << endl;
}