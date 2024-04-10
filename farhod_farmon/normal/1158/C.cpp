#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int res[N];
bool used[N];
vector < int > v[N], ord;

void dfs(int x)
{
        if(used[x]){
                return;
        }
        used[x] = 1;
        for(int y: v[x]){
                dfs(y);
        }
        ord.push_back(x);
}

void add(int x, int y)
{
        v[x].push_back(y);
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                v[i].clear();
                used[i] = 0;
        }
        ord.clear();
        vector < int > g;
        for(int i = n; i >= 1; i--){
                if(a[i] == -1){
                        if(!g.empty()){
                                add(g.back(), i);
                        }
                        g.push_back(i);
                        continue;
                }
                while(!g.empty() && g.back() != a[i]){
                        add(i, g.back());
                        g.pop_back();
                }
                if(g.empty()){
                        if(a[i] != n + 1){
                                cout << -1 << "\n";
                                return;
                        }
                } else{
                        add(g.back(), i);
                }
                g.push_back(i);
        }
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        dfs(i);
                }
        }
        for(int i = 0; i < n; i++){
                res[ord[i]] = i + 1;
        }
        for(int i = 1; i <= n; i++){
                cout << res[i] << " ";
        }
        cout << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("teleports.in", "r", stdin);
        //freopen("teleports.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}