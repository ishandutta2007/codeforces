#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll int

const int N = 200200;
const long long mod = 1e15 + 3;

using namespace std;

long long n;
long long a[N];
long long b[N];
long long w[N];
long long p[N];
long long s[N];
long long up[N];
long long can[N];
vector < pair < long long, long long > > v[N];

void dfs(int x, int pr)
{
    for(auto y: v[x]){
        if(y.fi == pr)
            continue;
        dfs(y.fi, x);
        long long g = min(p[y.se] - s[y.fi], min(p[y.se], w[y.se] - 1));
        g = max(g, 0ll);
        p[y.se] -= g;
        w[y.se] -= g;
        up[y.se] = g;
        s[x] += s[y.fi] + w[y.se];
        if(s[y.fi] > p[y.se]){
            cout << -1 << endl;
            exit(0);
        }
    }
}

long long solve(int x, int pr)
{
    long long cnt = 0;
    for(auto y: v[x]){
        if(y.fi == pr)
            continue;
        long long g = min(can[x] - s[x], up[y.se]);
        p[y.se] += g;
        w[y.se] += g;
        cnt += g;
        s[x] += g;
        can[y.fi] = min(can[x] - s[x] + s[y.fi], p[y.se]);
        g = solve(y.fi, x);
        cnt += g;
        s[x] += g;
    }
    return cnt;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a[i] >> b[i] >> w[i] >> p[i];
        v[a[i]].pb({b[i], i});
        v[b[i]].pb({a[i], i});
    }
    can[1] = 1e15;
    dfs(1, -1);
    solve(1, -1);
    cout << n << endl;
    for(int i = 1; i < n; i++)
        cout << a[i] << " " << b[i] << " " << w[i] << " " << p[i] << endl;
}