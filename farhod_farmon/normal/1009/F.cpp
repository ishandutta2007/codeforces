#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int s[N];
int d[N];
int t[N];
int ans[N];
vector < int > v[N];
set < pair < int, int > > f;

void cc(int x, int p)
{
        s[x] = 1;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                d[y] = d[x] + 1;
                cc(y, x);
                s[x] += s[y];
        }
}

void F(int x, int g)
{
        f.erase({-t[d[x]], d[x]});
        t[d[x]] += g;
        f.insert({-t[d[x]], d[x]});
}

void upd(int x, int p, int g)
{
        F(x, g);
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                upd(y, x, g);
        }
}

void dfs(int x, int p, bool del)
{
        int big = -1;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                if(big == -1 || s[y] > s[big]){
                        big = y;
                }
        }
        for(int y: v[x]){
                if(y == p || y == big){
                        continue;
                }
                dfs(y, x, 1);
        }
        if(big != -1){
                dfs(big, x, 0);
        }
        for(int y: v[x]){
                if(y == p || y == big){
                        continue;
                }
                upd(y, x, 1);
        }
        F(x, 1);
        ans[x] = f.begin()->se - d[x];
        if(del){
                upd(x, p, -1);
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        cc(1, 1);
        dfs(1, 1, 0);
        for(int i = 1; i <= n; i++){
                cout << ans[i] << "\n";
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