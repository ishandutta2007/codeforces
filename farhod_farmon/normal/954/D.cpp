#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
bool c[N][N];
vector < int > v[N];

vector < int > get(int x)
{
        vector < int > d;
        for(int i = 0; i <= n; i++){
                d.push_back(1e9);
        }
        queue < int > q;
        q.push(x);
        d[x] = 0;
        while(!q.empty()){
                x = q.front();
                q.pop();
                for(int y: v[x]){
                        if(d[x] + 1 < d[y]){
                                d[y] = d[x] + 1;
                                q.push(y);
                        }
                }
        }
        return d;
}

void solve()
{
        int s, t;
        cin >> n >> m >> s >> t;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                c[x][y] = c[y][x] = 1;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        vector < int > ds = get(s), dt = get(t);
        int ans = 0;
        for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                        if(c[i][j]){
                                continue;
                        }
                        int l1 = ds[i] + dt[j] + 1, l2 = dt[i] + ds[j] + 1;
                        if(min(l1, l2) >= ds[t]){
                                ans++;
                        }
                }
        }
        cout << ans << "\n";
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