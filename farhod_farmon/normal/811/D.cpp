#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long MX = 10010;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int p[N][N];
char c[N][N];
char rev[200];
bool used[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char f[4] = {'D', 'U', 'R', 'L'};

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> c[i][j];
                }
        }
        queue < pair < int, int > > q;
        q.push({1, 1});
        while(!q.empty()){
                int x = q.front().fi, y = q.front().se;
                q.pop();
                for(int i = 0; i < 4; i++){
                        int nx = x + dx[i], ny = y + dy[i];
                        if(c[nx][ny] == '*' || nx < 1 || ny < 1 || nx > n || ny > m){
                                continue;
                        }
                        if(used[nx][ny] == false){
                                used[nx][ny] = true;
                                p[nx][ny] = i;
                                q.push({nx, ny});
                        }
                }
        }
        vector < char > v;
        bool fnd = false;
        for(int i = 1; i <= n && !fnd; i++){
                for(int j = 1; j <= m; j++){
                        if(c[i][j] == 'F'){
                                fnd = true;
                                while(i != 1 || j != 1){
                                        int x = p[i][j];
                                        v.pb(x);
                                        i -= dx[x];
                                        j -= dy[x];
                                }
                                break;
                        }
                }
        }
        rev['L'] = 'L';
        rev['R'] = 'R';
        rev['U'] = 'U';
        rev['D'] = 'D';
        int x = 1, y = 1;
        for(int i = v.size() - 1; i >= 0; i--){
                char g = f[v[i]];
                int nx, ny;
                cout << rev[g] << endl;
                fflush(stdout);
                cin >> nx >> ny;
                if(nx == x && ny == y){
                        if(g == 'L' || g == 'R'){
                                rev['L'] = 'R';
                                rev['R'] = 'L';
                        }
                        else{
                                rev['D'] = 'U';
                                rev['U'] = 'D';
                        }
                        i++;
                }
                x = nx;
                y = ny;
        }
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