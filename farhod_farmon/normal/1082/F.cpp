#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 555;

using namespace std;

int n;
int k;
int G;
int g[N][11];
long long c[N];
long long d[N][N][11];
bool used[N][N];

void dfs(int x, int p, long long dip = 0)
{
        if(used[x][p]){
                return;
        }
        used[x][p] = true;
        for(int i = 0; i < 10; i++){
                int y = g[x][i];
                if(!y){
                        continue;
                }
                dfs(y, p, dip + 1);
                for(int j = k; j >= 0; j--){
                        for(int h = 0; h <= j; h++){
                                d[x][p][j] = max(d[x][p][j], d[x][p][j - h] + d[y][p][h]);
                        }
                }
        }
        if(dip != p){
                dfs(x, dip, dip);
                for(int i = 1; i <= k; i++){
                        d[x][p][i] = max(d[x][p][i], d[x][dip][i - 1] + (dip - p) * c[x]);
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                string s;
                int cost;
                cin >> s >> cost;
                int x = 0;
                for(int j = 0; j < s.size(); j++){
                        s[j] -= '0';
                        if(!g[x][s[j]]){
                                g[x][s[j]] = ++G;
                        }
                        x = g[x][s[j]];
                        c[x] += cost;
                }
        }
        dfs(0, 0, 0);
        long long ans = 0;
        for(int i = 1; i <= k; i++){
                ans = max(ans, d[0][0][i]);
        }
        ans = - ans;
        for(int i = 1; i <= G; i++){
                ans += c[i];
        }
        cout << ans << "\n";
}