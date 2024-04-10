
#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int m;
int d[N];
bool used[N];
vector < int > ans;
vector < pair < int, int > > v[N];

void dfs(int x, int p)
{
        used[x] = true;
        for(auto y: v[x]){
                if(used[y.fi] || y.se == p){
                        continue;
                }
                dfs(y.fi, y.se);
                d[x] = (d[x] + d[y.fi]) % 2;
        }
        if(d[x]){
                ans.push_back(p);
        }
}

void solve()
{
        cin >> n >> m;
        int s = 0;
        for(int i = 1; i <= n; i++){
                cin >> d[i];
                if(d[i] != -1){
                        s += d[i];
                }
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back({y, i});
                v[y].push_back({x, i});
        }
        s %= 2;
        for(int i = 1; i <= n; i++){
                if(d[i] == -1){
                        if(s == 1){
                                s = 0;
                                d[i] = 1;
                        }
                        else{
                                d[i] = 0;
                        }
                }
        }
        if(s){
                cout << -1 << "\n";
                return;
        }
        dfs(1, 0);
        cout << ans.size() << "\n";
        for(int x: ans){
                cout << x << " ";
        }
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}