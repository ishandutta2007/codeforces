#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

long long n;
long long ans;
long long a[N];
long long d[N];
vector < long long > v[N];

void dfs(long long x, long long p)
{
    d[x] = -1e16;
    long long h[2] = {d[x], d[x]};
    for(auto y: v[x]){
        if(y == p)
            continue;
        dfs(y, x);
        a[x] += a[y];
        d[x] = max(d[x], d[y]);
        if(d[y] > h[0]){
            h[1] = h[0];
            h[0] = d[y];
        }
        else if(d[y] > h[1])
            h[1] = d[y];
    }
    if(h[1] != -1e16)
        ans = max(ans, h[0] + h[1]);
    d[x] = max(d[x], a[x]);
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
    ans = -1e16;
    dfs(1, -1);
    if(ans == -1e16)
        cout << "Impossible" << endl;
    else
        cout << ans << endl;
}