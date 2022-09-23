#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 400100;

using namespace std;

int n, q, t;
int d[N];
int a[N];
int mod = 1e9 + 7;
bool p[N];
int r[N];
bool used[N];
vector < int > g;

void dfs(int x)
{
    g.pb(x);
    if(used[x]){
        cout << 0 << endl;
        exit(0);
    }
    used[x] = true;
    if(r[x])
        dfs(r[x]);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> q >> t;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        r[x] = y;
        p[y] = true;
    }
    long long start = 0;
    for(int i = 1; i <= n; i++){
        if(!p[i]){
            g.clear();
            dfs(i);
            for(int j = 0; j < (int)g.size(); j++)
                start += (g.size() - j - 1) * a[g[j]];
            for(int j = 1; j < (int)g.size(); j++)
                a[g[j]] += a[g[j - 1]];
        }
    }
    if(start > t){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cout << 0 << endl;
            return 0;
        }
    }
    d[start] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = start; j <= t; j++){
            if(j + a[i] <= t)
                d[j + a[i]] = (d[j + a[i]] + d[j]) % mod;
        }
    }
    cout << d[t] << endl;
}