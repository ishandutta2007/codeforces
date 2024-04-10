#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 202;

using namespace std;

int n;
int m;
int d[N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        d[i][j] = 1e9;
                }
                d[i][i] = 0;
        }
        for(int i = 1; i <= m; i++){
                int x, y, w;
                cin >> x >> y >> w;
                w *= 2;
                d[x][y] = min(d[x][y], w);
                d[y][x] = min(d[y][x], w);
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        for(int h = 1; h <= n; h++){
                                d[j][h] = min(d[j][h], d[j][i] + d[i][h]);
                        }
                }
        }
        int res = 1e9;
        for(int i = 1; i <= n; i++){
                int cur = 0;
                for(int j = 1; j <= n; j++){
                        cur = max(cur, d[i][j]);
                }
                res = min(res, cur);
        }
        vector < pair < int, int > > v;
        for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                        int w = d[i][j];
                        if(w == 1e9){
                                continue;
                        }

                        v.clear();
                        for(int h = 1; h <= n; h++){
                                int x = (d[j][h] - d[i][h] + w) / 2;
                                int y = d[i][h] + x;
                                v.push_back({x - y, x + y});
                        }
                        sort(v.begin(), v.end());

                        int last = -1e9;
                        for(auto p: v){
                                if(last >= p.se){
                                        continue;
                                }
                                int x = (last + p.fi) / 2;
                                int y = (last - p.fi) / 2;
                                if(x > 0 && x < w){
                                        res = min(res, y);
                                }
                                last = p.se;
                        }
                }
        }
        cout << res / 2 << "." << 5 * (res % 2) << "\n";
}