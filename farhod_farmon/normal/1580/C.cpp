#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 200200;
const int M = sqrt(N);

using namespace std;

int n, m;
int x[N], y[N];
int res[N];
int all[N];
int f[N];
vector<int> v[N];
vector<int> shit[M];

void solve(int B)
{
        for(int i = 1; i <= m; i++){
                f[i] = 0;
        }
        for(int i: shit[B]){
                for(int j = 1; j < v[i].size(); j += 2){
                        int l = v[i][j - 1], r = v[i][j], need = (r - l) / B;

                        if(need > 0){
                                f[l + x[i]] += 1;
                                f[l + B] -= 1;
                                l += B * need;
                                f[l + x[i]] -= 1;
                                f[l + B] += 1;
                        }
                        if(l + x[i] < r){
                                res[l + x[i]] += 1;
                                res[r] -= 1;
                        }
                }
        }
        for(int i = 1; i <= m; i++){
                f[i] += f[i - 1];
        }
        for(int i = 1; i <= m; i++){
                if(i + B <= m){
                        f[i + B] += f[i];
                }
                all[i] += f[i];
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> x[i] >> y[i];
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[y].push_back(i);
        }
        for(int i = 1; i <= n; i++){
                if(v[i].empty()){
                        continue;
                } else if(v[i].size() % 2 == 1){
                        v[i].push_back(m + 1);
                }
                if(x[i] + y[i] < M){
                        shit[x[i] + y[i]].push_back(i);
                        continue;
                }
                for(int j = 1; j < v[i].size(); j += 2){
                        for(int h = v[i][j - 1] + x[i]; h < v[i][j]; h += x[i] + y[i]){
                                res[h] += 1;
                                res[min(h + y[i], v[i][j])] -= 1;
                        }
                }
        }

        for(int i = 1; i < M; i++){
                if(shit[i].empty()){
                        continue;
                }
                solve(i);
        }
        for(int i = 1; i <= m; i++){
                res[i] += res[i - 1];
                cout << res[i] + all[i] << "\n";
        }
}