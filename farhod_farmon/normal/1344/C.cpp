#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int m;
int cyc;
int d[N];
int f[N];
int used[N];
vector < int > ord;
vector < int > v[N], g[N];

void dfs(int x)
{
        if(used[x]){
                if(used[x] == 1){
                        cyc = 1;
                }
                return;
        }
        used[x] = 1;
        for(int y: v[x]){
                dfs(y);
        }
        used[x] = 2;
        ord.push_back(x);
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                g[y].push_back(x);
        }
        for(int i = 1; i <= n; i++){
                d[i] = f[i] = i;
                if(!used[i]){
                        dfs(i);
                }
        }
        if(cyc){
                cout << -1 << "\n";
                return 0;
        }
        for(int x: ord){
                for(int y: v[x]){
                        d[x] = min(d[x], d[y]);
                }
        }
        reverse(ord.begin(), ord.end());
        for(int x: ord){
                for(int y: g[x]){
                        f[x] = min(f[x], f[y]);
                }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                if(min(d[i], f[i]) == i){
                        cnt += 1;
                }
        }
        cout << cnt << "\n";
        for(int i = 1; i <= n; i++){
                if(min(d[i], f[i]) == i){
                        cout << 'A';
                } else{
                        cout << 'E';
                }
        }
}