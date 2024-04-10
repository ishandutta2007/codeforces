#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int s;
ll cost[N];
vector < pair < ll, ll > > o[N], e[N];

void solve()
{
        for(int i = 0; i < N; i++){
                cost[i] = 1e15;
        }
        cin >> n >> s;
        for(int i = 1; i <= n; i++){
                int l, r, c;
                cin >> l >> r >> c;
                o[l].pb({r, c});
                e[r].pb({l, c});
        }
        ll ans = 1e15;
        for(int i = 1; i < N; i++){
                for(auto p: e[i - 1]){
                        int d = i - p.fi;
                        cost[d] = min(cost[d], p.se);
                }
                for(auto p: o[i]){
                        int d = p.fi - i + 1;
                        if(s - d > 0) ans = min(ans, p.se + cost[s - d]);
                }
        }
        if(ans == 1e15) ans = -1;
        cout << ans << endl;
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