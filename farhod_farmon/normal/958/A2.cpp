#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
char a[N][N / 10];
char b[N / 10][N];
map < vector < long long >, vector < int > > used;

vector < long long > make(vector < pair < int, int > > v)
{
        vector < long long > g;
        vector < pair < long long, long long > > nv(m);
        for(int i = 0; i < m; i++){
                nv[i] = v[i];
        }
        for(int i = 0; i < 5; i++){
                long long s = 0;
                for(int j = 0; j < m; j++){
                        s = (s + nv[j].fi * mod + nv[j].se) % mod;
                }
                for(int j = 0; j < m; j++){
                        nv[j].fi = (nv[j].fi * v[j].fi) % mod;
                        nv[j].se = (nv[j].se * v[j].se) % mod;
                }
                g.push_back(s);
        }
        return g;
}

bool check(int x, int y)
{
        for(int i = 1; i <= m; i++){
                for(int j = 1; j <= m; j++){
                        if(a[x + i - 1][j] != b[i][y + j - 1]){
                                return false;
                        }
                }
        }
        return true;
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                }
        }
        for(int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                        cin >> b[i][j];
                }
        }
        for(int i = 1; i + m - 1 <= n; i++){
                vector < pair < int, int > > v;
                for(int j = 1; j <= m; j++){
                        pair < int, int > tc = {0, 0};
                        for(int h = 0; h < m; h++){
                                tc.fi = 1ll * (tc.fi + b[j][i + h] - 'a' + 1) * 27 % mod;
                                tc.se = 1ll * (tc.se + b[j][i + h] - 'a' + 1) * 29 % mod;
                        }
                        v.push_back(tc);
                }
                vector < long long > hsh = make(v);
                used[hsh].push_back(i);
        }
        for(int i = 1; i + m - 1 <= n; i++){
                vector < pair < int, int > > v;
                for(int j = 0; j < m; j++){
                        pair < int, int > tc = {0, 0};
                        for(int h = 1; h <= m; h++){
                                tc.fi = 1ll * (tc.fi + a[i + j][h] - 'a' + 1) * 27 % mod;
                                tc.se = 1ll * (tc.se + a[i + j][h] - 'a' + 1) * 29 % mod;
                        }
                        v.push_back(tc);
                }
                vector < long long > hsh = make(v);
                for(int x: used[hsh]){
                        if(check(i, x)){
                                cout << i << " " << x << "\n";
                                return;
                        }
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}