#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;

using namespace std;

int n;
int m;
int d[1 << 12];
int cost[1 << 12];
int a[12][24];
vector < int > v[12];

void make(int x)
{
        for(int i = 0; i < (1 << n); i++){
                cost[i] = 0;
        }
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n - 1; j++){
                        swap(a[j][x], a[j + 1][x]);
                }
                for(int i = 0; i < (1 << n); i++){
                        int cnt = 0;
                        for(int h = 0; h < n; h++){
                                if(i & (1 << h)){
                                        cnt += a[h][x];
                                }
                        }
                        cost[i] = max(cost[i], cnt);
                }
        }
}

void solve()
{
        cin >> n >> m;
        vector < pair < int, int > > best_s;
        for(int i = 0; i < n; i++){
                v[i].resize(m);
                for(int j = 0; j < m; j++){
                        cin >> v[i][j];
                }
        }
        for(int i = 0; i < m; i++){
                int mx = 0;
                for(int j = 0; j < n; j++){
                        mx = max(mx, v[j][i]);
                }
                best_s.push_back({mx, i});
        }
        sort(best_s.begin(), best_s.end());
        reverse(best_s.begin(), best_s.end());
        m = min(m, n + n);
        for(int i = 0; i < m; i++){
                int x = best_s[i].se;
                for(int j = 0; j < n; j++){
                        a[j][i] = v[j][x];
                }
        }
        for(int i = 0; i < (1 << n); i++){
                d[i] = 0;
        }
        for(int i = 0; i < m; i++){
                make(i);
                for(int i = (1 << n) - 1; i >= 0; i--){
                        for(int j = i; j > 0; j = (j - 1) & i){
                                d[i] = max(d[i], d[i ^ j] + cost[j]);
                        }
                }
        }
        cout << d[(1 << n) - 1] << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}