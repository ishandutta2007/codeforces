#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int d[N][2];
int ans;
vector < pair < int, int > > v[N];

void dfs(int x, int p)
{
        vector < pair < int, int > > v1;
        for(auto pp: v[x]){
                int y = pp.fi, c = pp.se;
                if(y == p){
                        continue;
                }
                dfs(y, x);
                v1.pb({d[y][1] + c, d[y][0] + c});
        }
        sort(v1.begin(), v1.end());
        for(int i = v1.size() - 1; i > max(-1, (int)v1.size() - k); i--){
                d[x][1] += v1[i].fi;
        }
        for(int i = v1.size() - k; i >= 0; i--){
                d[x][0] = max(d[x][0], d[x][1] + v1[i].se);
        }
        for(int i = v1.size() - 1; i > max(-1, (int)v1.size() - k); i--){
                int ch = 0;
                if((int)v1.size() - k >= 0){
                        ch = v1[(int)v1.size() - k].fi;
                }
                d[x][0] = max(d[x][0], d[x][1] + ch - v1[i].fi + v1[i].se);
        }
        ans = max(ans, max(d[x][0], d[x][1]));
}

void solve()
{
        cin >> n >> k;
        for(int i = 1; i < n; i++){
                int x, y, c;
                cin >> x >> y >> c;
                v[x].pb({y, c});
                v[y].pb({x, c});
        }
        dfs(0, 0);
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}