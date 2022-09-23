#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 33;
const int MX = 10000001;
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll ax[N];
ll ay[N];
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
vector < ll > v[N];

void dfs(ll f, ll x, ll y, ll l, ll p, ll ph)
{
    ax[f] = x;
    ay[f] = y;
    int h = 0;
    for(int f2: v[f]){
        if(f2 == p)
            continue;
        if((h + 2) % 4 == ph)
            h++;
        dfs(f2, x + l * dx[h], y + l * dy[h], l / 2, f, h);
        h++;
    }
}

void solve()
{
    cin >> n;
    for(ll i = 2; i <= n; i++){
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(ll i = 1; i <= n; i++){
        if(v[i].size() > 4){
            cout << "NO" << endl;
            return;
        }
    }
    dfs(1, 0, 0, 1e15, -1, -1);
    cout << "YES" << endl;
    for(ll i = 1; i <= n; i++)
        cout << ax[i] << " " << ay[i] << endl;
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