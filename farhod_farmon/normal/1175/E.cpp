#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 10000011;
const int mod = 1e9 + 7;

using namespace std;

int n;
int m;
int best[N];
int f[N][20];
pair < int, int > a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi >> a[i].se;
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++){
                best[i] = i;
                if(i > 1 && a[best[i - 1]].se > a[i].se){
                        best[i] = best[i - 1];
                }
        }
        for(int i = 1; i <= n; i++){
                int l = 1, r = n;
                while(l < r){
                        int m = (l + r) / 2;
                        if(a[m + 1].fi <= a[i].se){
                                l = m + 1;
                        } else{
                                r = m;
                        }
                }
                f[i][0] = best[l];
        }
        for(int i = 1; i < 20; i++){
                for(int j = 1; j <= n; j++){
                        f[j][i] = f[f[j][i - 1]][i - 1];
                }
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                if(x < a[1].fi){
                        cout << -1 << "\n";
                        continue;
                }
                int l = 1, r = n;
                while(l < r){
                        int m = (l + r) / 2;
                        if(a[m + 1].fi <= x){
                                l = m + 1;
                        } else{
                                r = m;
                        }
                }
                l = best[l];
                int res = 0;
                for(int i = 19; i >= 0; i--){
                        if(a[f[l][i]].se < y){
                                res += (1 << i);
                                l = f[l][i];
                        }
                }
                if(a[l].se < y){
                        res += 1;
                        l = f[l][0];
                }
                if(a[l].se < y){
                        cout << -1 << "\n";
                } else{
                        cout << res + 1 << "\n";
                }
        }
}