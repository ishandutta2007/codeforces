#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n;
int m;
int k;
int d[N];
int f[N];
vector < int > v[N];

void bfs(int x, int *d)
{
        for(int i = 1; i <= n; i++){
                d[i] = -1;
        }
        d[x] = 0;
        queue < int > q;
        q.push(x);
        while(!q.empty()){
                int x = q.front();
                q.pop();
                for(int y: v[x]){
                        if(d[y] == -1){
                                d[y] = d[x] + 1;
                                q.push(y);
                        }
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        vector < int > g(k);
        for(int i = 0; i < k; i++){
                cin >> g[i];
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        bfs(1, d);
        bfs(n, f);
        sort(g.begin(), g.end(), [&](int x, int y){
             return d[x] - f[x] < d[y] - f[y];
             });

        int shit = 0, f_max = -1e9;
        for(int i = g.size() - 1; i >= 0; i--){
                shit = max(shit, d[g[i]] + f_max + 1);
                f_max = max(f_max, f[g[i]]);
        }
        cout << min(shit, d[n]) << "\n";
}