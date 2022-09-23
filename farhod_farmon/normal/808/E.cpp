#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300100;
const long long MX = 30030;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll m;
ll d[N];
vector < ll > v[4];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                ll w, x;
                cin >> w >> x;
                v[w].pb(x);
        }
        for(int i = 1; i <= 3; i++){
                if(v[i].empty()){
                        continue;
                }
                sort(v[i].begin(), v[i].end());
                reverse(v[i].begin(), v[i].end());
        }
        vector < ll > g;
        for(int i = 0; i + 1 < v[1].size(); i += 2){
                g.pb(v[1][i] + v[1][i + 1]);
        }
        for(int i = 0; i < v[2].size(); i++){
                g.pb(v[2][i]);
        }
        sort(g.begin(), g.end());
        reverse(g.begin(), g.end());
        ll cur = 0, we = 0, c = 0;
        for(auto p: g){
                we += 2;
                c += p;
                cur += p;
                d[we] = c;
        }
        g.clear();
        if(v[1].size() >= 1){
                for(int i = 1; i + 1 < v[1].size(); i += 2){
                        g.pb(v[1][i] + v[1][i + 1]);
                }
                for(int i = 0; i < v[2].size(); i++){
                        g.pb(v[2][i]);
                }
                sort(g.begin(), g.end());
                reverse(g.begin(), g.end());
                cur = 0, we = 0, c = 0;
                d[1] = v[1][0];
                for(auto p: g){
                        we += 2;
                        c += p;
                        cur += p;
                        d[we + 1] = c + v[1][0];
                }
        }
        for(int i = 1; i <= m; i++){
                d[i] = max(d[i], d[i - 1]);
        }
        ll ans = d[m];
        we = 0, c = 0;
        for(auto x: v[3]){
                we += 3;
                c += x;
                if(we <= m){
                        ans = max(ans, c + d[m - we]);
                }
        }
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