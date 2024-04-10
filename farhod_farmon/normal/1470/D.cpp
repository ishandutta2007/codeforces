#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
bool used[N];
bool bad[N];
bool good[N];
vector < int > v[N], res;

void solve()
{
        int m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                used[i] = bad[i] = good[i] = 0;
                v[i].clear();
        }
        res.clear();
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        queue < int > q;
        q.push(1);
        good[1] = true;
        while(!q.empty()){
                int x = q.front();
                q.pop();
                if(bad[x]){
                        continue;
                }
                res.push_back(x);
                for(int y: v[x]){
                        if(bad[y]){
                                continue;
                        }
                        bad[y] = true;
                        for(int z: v[y]){
                                if(!good[z]){
                                        q.push(z);
                                        good[z] = true;
                                }
                        }
                }
        }
        int gg = 0;
        for(int i = 1; i <= n; i++){
                if(!good[i] && !bad[i]){
                        gg = 1;
                }
        }
        if(gg){
                cout << "NO" << "\n";
                return;
        }
        cout << "YES" << "\n";
        cout << res.size() << "\n";
        for(int x: res){
                cout << x << " ";
        }
        cout << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}