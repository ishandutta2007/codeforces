#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 1000000007;
const int MAGIC = 2000;

using namespace std;

int n;
int m;
int a[N][N];
pair < int, int > d[N][N];
pair < int, int > f[N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        scanf("%d", &a[i][j]);
                }
        }
        vector < pair < int, int > > v;
        for(int i = 1; i <= n; i++){
                v.clear();
                for(int j = 1; j <= m; j++){
                        v.push_back({a[i][j], j});
                }
                sort(v.begin(), v.end());
                for(int j = 0, h = 0; j < m; j++){
                        if(j > 0 && v[j].fi > v[j - 1].fi){
                                h++;
                        }
                        d[i][v[j].se].fi = h;
                }
                for(int j = m - 1, h = 0; j >= 0; j--){
                        if(j + 1 < m && v[j].fi < v[j + 1].fi){
                                h++;
                        }
                        d[i][v[j].se].se = h;
                }
        }
        for(int j = 1; j <= m; j++){
                v.clear();
                for(int i = 1; i <= n; i++){
                        v.push_back({a[i][j], i});
                }
                sort(v.begin(), v.end());
                for(int i = 0, h = 0; i < n; i++){
                        if(i > 0 && v[i].fi > v[i - 1].fi){
                                h++;
                        }
                        f[v[i].se][j].fi = h;
                }
                for(int i = n - 1, h = 0; i >= 0; i--){
                        if(i + 1 < n && v[i].fi < v[i + 1].fi){
                                h++;
                        }
                        f[v[i].se][j].se = h;
                }
        }
        int d1, d2;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        d1 = max(d[i][j].fi, f[i][j].fi);
                        d2 = max(d[i][j].se, f[i][j].se);
                        printf("%d ", d1 + d2 + 1);
                }
                printf("\n");
        }
}