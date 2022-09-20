#include <bits/stdc++.h>

using namespace std;

#ifdef zxc
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug_arr(...) 42
#endif

#define fi first
#define se second

const int N = 100100;

int n, m;
int c[N], res[N];
vector < int > v[N];
vector < int > day[N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                day[i].clear();
                c[i] = 0;
        }
        int can = (m + 1) / 2;
        for(int i = 1; i <= m; i++){
                int k;
                cin >> k;
                v[i].resize(k);
                for(int j = 0; j < k; j++){
                        cin >> v[i][j];
                        day[v[i][j]].push_back(i);
                }
                c[v[i][0]] += 1;
                res[i] = v[i][0];
        }
        int x = -1;
        for(int i = 1; i <= n; i++){
                if(c[i] > can){
                        x = i;
                }
        }
        for(int i = 1; i <= m; i++){
                if(v[i][0] == x && c[v[i][0]] > can){
                        if(v[i].size() > 1){
                                c[v[i][0]] -= 1;
                                res[i] = v[i][1];
                        }
                }
        }
        if(x != -1 && c[x] > can){
                cout << "NO" << "\n";
        } else{
                cout << "YES" << "\n";
                for(int i = 1; i <= m; i++){
                        cout << res[i] << " ";
                }
                cout << "\n";
        }
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