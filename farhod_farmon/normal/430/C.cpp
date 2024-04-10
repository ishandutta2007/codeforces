#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100010;

using namespace std;

int n;
int a[N];
int b[N];
int d[2];
vector < int > v[N], ans;

int dfs(int x, int p, int g)
{
    if(d[g % 2] % 2)
        a[x] = 1 - a[x];
    if(a[x] != b[x]){
        ans.pb(x);
        d[g % 2]++;
    }
    for(auto y: v[x]){
        if(y == p)
            continue;
        dfs(y, x, g + 1);
    }
    if(a[x] != b[x])
        d[g % 2]--;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    dfs(1, 1, 1);
    cout << ans.size() << endl;
    for(auto x: ans)
        cout << x << endl;
}