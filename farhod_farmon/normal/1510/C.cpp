#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 300100;

int n, m;
int tim;
int tin[N], fin[N];
vector < int > v[N], g[N];
bool used[N];
vector < pair < int, int > > res;

void dfs(int x, int p)
{
        tin[x] = fin[x] = ++tim;
        used[x] = true;

        for(int y: v[x]){
                if(y == p){
                        continue;
                } else if(used[y]){
                        fin[x] = min(fin[x], tin[y]);
                } else{
                        dfs(y, x);
                        fin[x] = min(fin[x], fin[y]);

                        if(fin[y] > tin[x]){
                                g[x].push_back(y);
                                g[y].push_back(x);
                        }
                }
        }
}

int trace(int x, int p)
{
        used[x] = true;

        vector < int > A, B;
        for(int y: g[x]){
                if(y == p){
                        continue;
                }
                int g = trace(y, x);

                if(g == y){
                        A.push_back(g);
                } else{
                        B.push_back(g);
                }
        }

        if(p == -1){
                if((A.size() + B.size()) % 2 == 1){
                        if(!A.empty()){
                                A.pop_back();
                        } else{
                                res.push_back({x, B.back()});
                                B.pop_back();
                        }
                }
                for(int x: B){
                        A.push_back(x);
                }
                for(int i = 1; i < (int)A.size(); i += 2){
                        res.push_back({A[i - 1], A[i]});
                }
                return -1;
        }


        if(A.size() + B.size() == 0){
                return x;
        } else if(A.size() + B.size() == 1){
                if(!A.empty()){
                        return A[0];
                }
                return B[0];
        }
        int to_send = x;
        if(!A.empty()){
                to_send = A.back();
                A.pop_back();
        }

        for(int x: B){
                A.push_back(x);
        }
        for(int i = 1; i < (int)A.size(); i += 2){
                res.push_back({A[i - 1], A[i]});
        }

        if(A.size() % 2){
                return A.back();
        }
        return to_send;
}

void solve()
{
        tim = 0;
        res.clear();
        for(int i = 1; i <= n; i++){
                v[i].clear();
                used[i] = 0;
                g[i].clear();
        }

        for(int i = 1; i <= m; i++){
                int k;
                cin >> k;
                for(int j = 1, x, y; j <= k; j++){
                        cin >> x;
                        if(j != 1){
                                v[x].push_back(y);
                                v[y].push_back(x);
                        }
                        y = x;
                }
        }

        dfs(1, 1);
        for(int i = 1; i <= n; i++){
                used[i] = 0;
        }

        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        trace(i, -1);
                }
        }

        cout << res.size() << "\n";
        for(auto p: res){
                cout << p.fi << " " << p.se << "\n";
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        while(cin >> n >> m){
                if(n + m == 0){
                        break;
                }
                solve();
        }

}