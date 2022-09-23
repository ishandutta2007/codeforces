#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int m;
vector < int > v[N];
bool used[N];

int G, E;

void dfs(int x)
{
        if(used[x]){
                return;
        }
        used[x] = true;
        G += 1;
        E += v[x].size();
        for(int y: v[x]){
                dfs(y);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
                if(used[i]){
                        continue;
                }
                G = E = 0;
                dfs(i);
                res += E / 2 - (G - 1);
        }
        cout << res << "\n";
}