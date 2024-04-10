#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 440;
const int Q = 250200;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int a[N];
int f[Q];
int c[Q];
int r[Q];
int d[N][N];
vector < int > s[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
                int x;
                cin >> x >> f[i] >> c[i] >> r[i];
                s[x].push_back(i);
        }
        long long res = 0;
        for(int i = 1; i <= n; i++){
                for(int j = i; j <= n; j++){
                        for(int h = 0; h <= n; h++){
                                d[j][h] = 1e9;
                        }
                }
                for(int j = i; j <= n; j++){
                        d[j][0] = a[j] - a[i];
                }
                for(int k = 1; k <= n; k++){
                        int h = i;
                        for(int j = i; j <= n; j++){
                                d[j][k] = d[j][k - 1];
                                while(h + 1 <= j && max(d[h][k - 1], a[j] - a[h]) >= max(d[h + 1][k - 1], a[j] - a[h + 1])){
                                        h++;
                                }
                                d[j][k] = min(d[j][k], max(d[h][k - 1], a[j] - a[h]));
                        }
                }
                for(int j: s[i]){
                        res = max(res, 1ll * d[f[j]][r[j]] * c[j]);
                }
        }
        cout << res << "\n";
}