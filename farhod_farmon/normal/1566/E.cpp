#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int d[N];
int shit[N];
vector<int> v[N];

void dfs(int x, int p)
{
        int cnt = 0;
        vector<int> g;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
                if(d[y] > 0){
                        g.push_back(d[y]);
                }
                cnt += shit[y];
        }
        if(cnt == 0){
                shit[x] = 1;
        } else{
                g.push_back(cnt);
        }
        if(!g.empty()){
                for(int y: g){
                        d[x] += y;
                }
                d[x] -= g.size() - 1;
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                d[i] = shit[i] = 0;
                v[i].clear();
        }
        for(int i = 1, x, y; i < n; i++){
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);

        cout << d[1] << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}