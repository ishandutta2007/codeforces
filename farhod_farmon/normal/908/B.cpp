#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 55;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n;
int m;
char c[N][N];
string s;

void solve()
{
        int sx, sy, ex, ey;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> c[i][j];
                        if(c[i][j] == 'S'){
                                sx = i, sy = j;
                        }
                        if(c[i][j] == 'E'){
                                ex = i, ey = j;
                        }
                }
        }
        cin >> s;
        int ans = 0;
        vector < int > p = {0, 1, 2, 3};
        do{
                bool can = true;
                int x = sx, y = sy;
                for(int i = 0; i < s.size(); i++){
                        x += dx[p[s[i] - '0']];
                        y += dy[p[s[i] - '0']];
                        if(x < 1 || y < 1 || x > n || y > m || c[x][y] == '#'){
                                can = false;
                                break;
                        }
                        if(x == ex && y == ey){
                                break;
                        }
                        if(i == s.size() - 1){
                                can = false;
                        }
                }
                ans += can;
        }while(next_permutation(p.begin(), p.end()));
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}