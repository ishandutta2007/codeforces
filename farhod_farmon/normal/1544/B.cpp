#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 23;
const int Q = 1000011;

using namespace std;

int n, m;
int a[N][N];
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool good(int x, int y)
{
        for(int i = 0; i < 8; i++){
                if(a[x + dx[i]][y + dy[i]]){
                        return false;
                }
        }
        return true;
}

void solve()
{
        for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                        a[i][j] = 0;
                }
        }

        cin >> n >> m;
        vector < pair < int, int > > v;
        for(int i = 1; i <= m; i++){
                v.push_back({1, i});
        }
        for(int i = 1; i <= n; i++){
                v.push_back({i, m});
        }
        for(int i = m; i >= 1; i--){
                v.push_back({n, i});
        }
        for(int i = n; i >= 1; i--){
                v.push_back({i, 1});
        }
        for(auto p: v){
                if(good(p.fi, p.se)){
                        a[p.fi][p.se] = true;
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cout << a[i][j];
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