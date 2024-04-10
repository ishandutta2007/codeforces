#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
bool used[N];
vector < int > v[N];

void dfs(int x, int p)
{
    used[x] = true;
    for(int y: v[x]){
        if(y == p)
            continue;
        dfs(y, x);
        used[x] &= used[y];
        if(a[x] != a[y])
            used[x] = false;
    }
}

void solve(int x, int p, int up = 1)
{
    if(!up)
        return;
    bool can = up;
    set < int > s1, s2;
    for(int y: v[x]){
        if(a[x] != a[y])
            s1.insert(y);
        if(y != p && !used[y])
            s2.insert(y);
        if(y != p && !used[y])
            can = false;
    }
    if(can){
        cout << "YES" << endl;
        cout << x << endl;
        exit(0);
    }
    for(int y: v[x]){
        if(y == p)
            continue;
        if(a[x] != a[y])
            s1.erase(y);
        if(!used[y])
            s2.erase(y);
        int ng = up;
        if(!s1.empty() || !s2.empty())
            ng = false;
        solve(y, x, ng);
        if(a[x] != a[y])
            s1.insert(y);
        if(!used[y])
            s2.insert(y);
    }
}

void solve()
{
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1, -1);
    solve(1, -1);
    cout << "NO" << endl;
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t = 1;
    if(mtest)
        cin >> t;
    while(t--)
        solve();
}