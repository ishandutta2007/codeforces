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

const int N = 100100;

using namespace std;

int n;
vector < pair < int, int > > v[N];
vector < int > ans;

bool dfs(int x, bool t, int p)
{
    bool ok = false;
    for(int i = 0; i < v[x].size(); i++){
        if(v[x][i].fi != p)
            ok |= dfs(v[x][i].fi, v[x][i].se - 1, x);
    }
    if(t == true && ok == false){
        ans.pb(x);
        ok = true;
    }
    return ok;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y, t;
        cin >> x >> y >> t;
        v[x].pb({y, t});
        v[y].pb({x, t});
    }
    dfs(1, 0, -1);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}