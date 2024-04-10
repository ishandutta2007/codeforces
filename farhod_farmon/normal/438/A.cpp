#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

long long a[N], s[N], n, m, ans;
bool used[N][N];
vector < int > v[N];
pair < int, int > p[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = {a[i], i};
    }
    sort(p + 1, p + n + 1);
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    sort(p + 1, p + n + 1);
    for(int i = 1; i <= n; i++){
        int x = p[i].se;
        for(int j = 0; j < v[x].size(); j++){
            if(used[v[x][j]][x])
                continue;
            used[x][v[x][j]] = true;
            ans += a[x];
        }
    }
    cout << ans << endl;
}