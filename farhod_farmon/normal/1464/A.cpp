#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200100;

using namespace std;

int n;
int cyc;
int used[N];
vector < int > v[N];

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
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int m;
                cin >> n >> m;
                for(int i = 1; i <= n; i++){
                        v[i].clear();
                        v[i + n].clear();
                        used[i] = used[i + n] = 0;
                }
                int res = 0;
                for(int i = 1; i <= m; i++){
                        int x, y;
                        cin >> x >> y;
                        if(x == y){
                                continue;
                        }
                        v[y + n].push_back(x);
                        res += 1;
                }
                for(int i = 1; i <= n; i++){
                        v[i].push_back(i + n);
                }
                for(int i = 1; i <= n; i++){
                        if(used[i]){
                                continue;
                        }
                        cyc = 0;
                        dfs(i);
                        res += cyc;
                }
                cout << res << "\n";
        }
}