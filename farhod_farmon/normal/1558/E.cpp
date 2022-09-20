#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int n, m;
int a[N], b[N];
int used[N];
vector<int> v[N];
int par[N];
int X, Y;

void dfs(int x, int p, long long k)
{
        k += b[x];
        used[x] = 1;
        par[x] = p;
        for(int y: v[x]){
                if(y == p || k <= a[y]){
                        continue;
                } else if(used[y]){
                        X = x;
                        Y = y;
                } else{
                        dfs(y, x, k);
                }
                if(X != -1){
                        break;
                }
        }
}

bool can(long long k)
{
        int cnt = 1;
        for(int i = 1; i <= n; i++){
                used[i] = 0;
        }
        used[1] = 2;
        while(cnt < n){
                for(int i = 1; i <= n; i++){
                        if(used[i] == 1){
                                used[i] = 0;
                        }
                        par[i] = -1;
                }
                X = Y = -1;
                for(int i = 1; i <= n; i++){
                        if(used[i] == 2){
                                for(int j: v[i]){
                                        if(used[j] == 2 || k <= a[j]){
                                                continue;
                                        }
                                        if(used[j] == 1){
                                                X = i;
                                                Y = j;
                                        } else{
                                                dfs(j, i, k);
                                        }
                                        if(X != -1){
                                                break;
                                        }
                                }
                        }
                        if(X != -1){
                                break;
                        }
                }
                //cout << X << " " << Y << "\n";

                if(X == -1){
                        return false;
                }
                for(int x: {X, Y}){
                        while(used[x] != 2){
                                used[x] = 2;
                                k += b[x];
                                x = par[x];
                                cnt += 1;
                        }
                }
        }
        return cnt == n;
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                v[i].clear();
        }
        for(int i = 2; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 2; i <= n; i++){
                cin >> b[i];
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }

        //cout << can(14);
        //exit(0);

        int l = 0, r = 1e9 + 1;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m)){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        cout << l << "\n";
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