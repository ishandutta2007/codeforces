#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int res;
int f[N];
int p[N], h[N], rel[N];
vector < int > v[N];

void dfs(int x, int p)
{
        int sum = 0;
        for(int y: v[x]){
                if(y == p) continue;
                dfs(y, x);
                sum += f[y];
                ::p[x] += ::p[y];
        }
        int Y = (::p[x] - h[x]) / 2;
        if((::p[x] - h[x]) % 2 || Y < 0 || sum < Y - rel[x]){
                res = 0;
        }
        f[x] = Y;
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int m;
                cin >> n >> m;
                for(int i = 1; i <= n; i++){
                        v[i].clear();
                        cin >> p[i];
                        rel[i] = p[i];
                }
                for(int i = 1; i <= n; i++){
                        cin >> h[i];
                }
                for(int i = 1; i < n; i++){
                        int x, y;
                        cin >> x >> y;
                        v[x].push_back(y);
                        v[y].push_back(x);
                }
                res = 1;
                dfs(1, 1);
                cout << (res ? "YES" : "NO") << "\n";
        }
}