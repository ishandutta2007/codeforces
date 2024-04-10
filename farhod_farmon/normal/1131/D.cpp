#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int p[N];
int res[N];
int used[N];
char c[N][N];
vector < int > ord;
vector < int > v[N];
vector < int > g[N];

int get(int x)
{
        return x == p[x] ? x : p[x] = get(p[x]);
}

bool cycle;

void dfs(int x, int p = -1)
{
        if(used[x]){
                if(used[x] == 1){
                        cycle = 1;
                }
                return;
        }
        used[x] = 1;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
        }
        ord.push_back(x);
        used[x] = 2;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n + m; i++){
                p[i] = i;
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> c[i][j];
                        if(c[i][j] == '='){
                                int x = get(p[i]);
                                int y = get(p[j + n]);
                                if(x != y){
                                        p[x] = y;
                                }
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        if(c[i][j] == '='){
                                continue;
                        }
                        int x = get(p[i]);
                        int y = get(p[j + n]);
                        if(x == y){
                                cout << "No" << "\n";
                                return 0;
                        }
                        if(c[i][j] == '<'){
                                v[x].push_back(y);
                                g[y].push_back(x);
                        }
                        else{
                                v[y].push_back(x);
                                g[x].push_back(y);
                        }
                }
        }
        for(int i = 1; i <= n + m; i++){
                if(used[i] == 0){
                        dfs(i);
                }
        }
        for(int i = n + m - 1; i >= 0; i--){
                for(int j: g[ord[i]]){
                        res[ord[i]] = max(res[ord[i]], res[j]);
                }
                res[ord[i]]++;
        }
        if(cycle){
                cout << "No" << "\n";
                return 0;
        }
        cout << "Yes" << "\n";
        for(int i = 1; i <= n; i++){
                cout << res[get(i)] << " \n"[i == n];
        }
        for(int i = 1; i <= m; i++){
                cout << res[get(i + n)] << " \n"[i == m];
        }
}