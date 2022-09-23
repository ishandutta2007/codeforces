#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
int tim;
int tin[N];
int tout[N];
int dip[N];
long long ans[N];
vector < int > v[N], g[N];
vector < long long > s[N];

bool isp(int x, int y)
{
        return tin[x] <= tin[y] && tout[x] >= tout[y];
}

void dfs(int x, int p, int d)
{
        dip[x] = d;
        tin[x] = ++tim;
        g[d].push_back(x);
        s[d].push_back(0);
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x, d + 1);
        }
        tout[x] = tim;
}

void go(int x, int p)
{
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                ans[y] += ans[x];
                go(y, x);
        }
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 2; i <= n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1, 0);
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                int x, d, w;
                cin >> x >> d >> w;
                ans[x] += w;
                d = min(n, dip[x] + d) + 1;
                if(g[d].empty()){
                        continue;
                }
                int l = 0, r = g[d].size() - 1;
                while(l < r){
                        int m = (l + r) / 2;
                        if(tin[x] <= tin[g[d][m]]){
                                r = m;
                        }
                        else{
                                l = m + 1;
                        }
                }
                if(isp(x, g[d][l])){
                        s[d][l] += w;
                }
                else{
                        continue;
                }
                r = g[d].size() - 1;
                while(l < r){
                        int m = (l + r) / 2 + 1;
                        if(tout[x] >= tin[g[d][m]]){
                                l = m;
                        }
                        else{
                                r = m - 1;
                        }
                }
                assert(isp(x, g[d][l]));
                if(l + 1 < g[d].size()){
                        s[d][l + 1] -= w;
                }
        }
        for(int i = 0; i <= n; i++){
                for(int j = 0; j < s[i].size(); j++){
                        if(j > 0){
                                s[i][j] += s[i][j - 1];
                        }
                        ans[g[i][j]] -= s[i][j];
                }
        }
        go(1, 1);
        for(int i = 1; i <= n; i++){
                cout << ans[i] << " ";
        }
}