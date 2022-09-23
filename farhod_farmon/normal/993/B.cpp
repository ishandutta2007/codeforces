#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 220;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int col[N];
pair < int, int > a[N], b[N];

bool can(int x, int y)
{
        if(a[x].fi == b[y].fi && a[x].se != b[y].se){
                return true;
        }
        if(a[x].fi != b[y].fi && a[x].se == b[y].se){
                return true;
        }
        if(a[x].fi == b[y].se && a[x].se != b[y].fi){
                return true;
        }
        if(a[x].fi != b[y].se && a[x].se == b[y].fi){
                return true;
        }
        return false;
}

int get(int x, int y)
{
        if(a[x].fi == b[y].fi || a[x].fi == b[y].se){
                return a[x].fi;
        }
        return a[x].se;
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi >> a[i].se;
        }
        for(int i = 1; i <= m; i++){
                cin >> b[i].fi >> b[i].se;
        }
        vector < pair < int, int > > v;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(can(i, j)){
                                v.push_back({i, j});
                                col[get(i, j)]++;
                        }
                }
        }
        if(v.empty()){
                cout << -1 << "\n";
                return;
        }
        int cnt = 0, h;
        for(int i = 1; i <= 9; i++){
                if(col[i] > 0){
                        cnt++;
                        h = i;
                        col[i] = 0;
                }
        }
        if(cnt == 1){
                cout << h << "\n";
                return;
        }
        cnt = 0;
        for(auto p: v){
                bool gg = true;
                for(int i = 1; i <= n; i++){
                        if(i == p.fi){
                                continue;
                        }
                        if(can(i, p.se) && get(i, p.se) != get(p.fi, p.se)){
                                gg = false;
                        }
                }
                for(int i = 1; i <= m; i++){
                        if(i == p.se){
                                continue;
                        }
                        if(can(p.fi, i) && get(p.fi, i) != get(p.fi, p.se)){
                                gg = false;
                        }
                }
                cnt += gg;
        }
        if(cnt == v.size()){
                cout << 0 << "\n";
        }
        else{
                cout << -1 << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}