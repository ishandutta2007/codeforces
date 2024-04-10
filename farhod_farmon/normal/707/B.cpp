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

int n, m, k, ans = 1e9 + 1;
bool used[N];
vector < pair < int, int > > v[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int x, y, l;
        cin >> x >> y >> l;
        v[x].pb({y, l});
        v[y].pb({x, l});
    }
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        used[x] = true;
    }
    for(int i = 1; i <= n; i++){
        if(!used[i])
            continue;
        for(int j = 0; j < v[i].size(); j++){
            if(!used[v[i][j].fi])
                ans = min(ans, v[i][j].se);
        }
    }
    if(ans == 1e9 + 1)
        ans = -1;
    cout << ans << endl;
}