#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n, m, k;
char c[N][N];
set < int > a[N], b[N];
queue < pair < int, pair < int, int > > > q;

void add(int x, int y, int g)
{
        q.push({g, {x, y}});
        a[x].erase(y);
        b[y].erase(x);
}

void solve()
{
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> c[i][j];
                        a[i].insert(j);
                        b[j].insert(i);
                }
        }
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        add(x1, y1, 0);
        while(!q.empty()){
                int x = q.front().se.fi, y = q.front().se.se, f = q.front().fi;
                q.pop();
                if(x == x2 && y == y2){
                        cout << f << "\n";
                        return;
                }
                auto it = a[x].lower_bound(y);
                while(it != a[x].end() && *it - y <= k && c[x][*it] == '.'){
                        add(x, *it, f + 1);
                        it = a[x].lower_bound(y);
                }
                it = a[x].lower_bound(y);
                while(it != a[x].begin() && y - *(--it) <= k && c[x][*it] == '.'){
                        add(x, *it, f + 1);
                        it = a[x].lower_bound(y);
                }
                it = b[y].lower_bound(x);
                while(it != b[y].end() && *it - x <= k && c[*it][y] == '.'){
                        add(*it, y, f + 1);
                        it = b[y].lower_bound(x);
                }
                it = b[y].lower_bound(x);
                while(it != b[y].begin() && x - *(--it) <= k && c[*it][y] == '.'){
                        add(*it, y, f + 1);
                        it = b[y].lower_bound(x);
                }
        }
        cout << -1 << "\n";
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