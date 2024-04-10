#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;
int d[N];
int used[N];
bool pr[N];
bool dead[N];
vector < int > v[N], g[N];
queue < int > q;

pair < int, int > bfs(int x, int gg)
{
        d[x] = 1;
        used[x] = gg;
        q.push(x);
        pair < int, int > res = {1, x};
        while(!q.empty()){
                x = q.front();
                q.pop();
                res = max(res, make_pair(d[x], x));
                for(int y: v[x]){
                        if(dead[y] || used[y] == gg){
                                continue;
                        }
                        used[y] = gg;
                        d[y] = d[x] + 1;
                        q.push(y);
                }
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                d[i] = 1e9;
                dead[i] = true;
                g[x].push_back(i);
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        int res = 0;
        vector < int > gg;
        for(int i = 2; i < N; i++){
                if(pr[i]){
                        continue;
                }
                gg.clear();
                for(int j = i; j < N; j += i){
                        pr[j] = 1;
                        for(int x: g[j]){
                                dead[x] = false;
                                gg.push_back(x);
                        }
                }
                for(int x: gg){
                        if(used[x] == 2){
                                continue;
                        }
                        res = max(res, bfs(bfs(x, 1).se, 2).fi);
                }
                for(int x: gg){
                        used[x] = 0;
                        dead[x] = true;
                }
        }
        cout << res << "\n";
}