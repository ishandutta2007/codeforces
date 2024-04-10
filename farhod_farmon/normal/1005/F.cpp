#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int k;
int d[N];
string s;
vector < int > p[N];
vector < string > ans;
vector < pair < int, int > > v[N];

void rec(int x)
{
        if(x == n + 1){
                ans.push_back(s);
                return;
        }
        for(int i = 0; i < (int)p[x].size() && (int)ans.size() < k; i++){
                s[p[x][i] - 1] = '1';
                rec(x + 1);
                s[p[x][i] - 1] = '0';
        }
}

void solve()
{
        cin >> n >> m >> k;
        for(int i = 1; i <= m; i++){
                s += '0';
                int x, y;
                cin >> x >> y;
                v[x].push_back({y, i});
                v[y].push_back({x, i});
        }
        for(int i = 1; i <= n; i++){
                d[i] = 1e9;
        }
        queue < int > q;
        q.push(1);
        d[1] = 0;
        while(!q.empty()){
                int x = q.front();
                q.pop();
                for(auto y: v[x]){
                        if(d[x] + 1 < d[y.fi]){
                                d[y.fi] = d[x] + 1;
                                p[y.fi].clear();
                                p[y.fi].push_back(y.se);
                                q.push(y.fi);
                        }
                        else if(d[x] + 1 == d[y.fi]){
                                p[y.fi].push_back(y.se);
                        }
                }
        }
        rec(2);
        cout << ans.size() << "\n";
        for(auto x: ans){
                cout << x << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}