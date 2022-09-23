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

const int N = 1010;

using namespace std;

int n;
int m;
long long h[N];
long long d[N][N];
long long f[N][N];
vector < pair < int, int > > v[N];

void djk(int root)
{
    set < pair < long long, int > > s;
    for(int i = 1; i <= n; i++)
        d[root][i] = 1e18;
    d[root][root] = 0;
    s.insert({0, root});
    while(!s.empty()){
        int x = s.begin()->se;
        s.erase(s.begin());
        for(auto y: v[x]){
            if(d[root][y.fi] > d[root][x] + y.se){
                s.erase({d[root][y.fi], y.fi});
                d[root][y.fi] = d[root][x] + y.se;
                s.insert({d[root][y.fi], y.fi});
            }
        }
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int st, en;
    cin >> st >> en;
    for(int i = 1; i <= m; i++){
        int x, y, l;
        cin >> x >> y >> l;
        v[x].pb({y, l});
        v[y].pb({x, l});
    }
    for(int i = 1; i <= n; i++)
        djk(i);
    for(int i = 1; i <= n; i++){
        int t, c;
        cin >> t >> c;
        for(int j = 1; j <= n; j++){
            if(d[i][j] <= t)
                f[i][j] = c;
            else
                f[i][j] = 1e18;
        }
    }
    for(int i = 1; i <= n; i++)
        h[i] = 1e18;
    set < pair < long long, int > > s;
    h[st] = 0;
    s.insert({0, st});
    while(!s.empty()){
        int x = s.begin()->se;
        s.erase(s.begin());
        for(int i = 1; i <= n; i++){
            if(h[i] > h[x] + f[x][i]){
                s.erase({h[i], i});
                h[i] = h[x] + f[x][i];
                s.insert({h[i], i});
            }
        }
    }
    if(h[en] == 1e18)
        cout << -1 << endl;
    else
        cout << h[en] << endl;
}