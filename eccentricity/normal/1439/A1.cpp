#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100 + 2;
char s[maxn][maxn];
int a[maxn][maxn];
vector<vector<int>> ans;
void fuck(int i, int j, int ii, int jj, int iii, int jjj){
    a[i][j] ^= 1;
    a[ii][jj] ^= 1;
    a[iii][jjj] ^= 1;
    ans.push_back({i, j, ii, jj, iii, jjj});
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n >> m;
        ans.clear();
        for(int i = 1; i <= n; i += 1) cin >> (s[i] + 1);
        for(int i = 1; i <= n; i += 1)
            for(int j = 1; j <= m; j += 1)
                a[i][j] = s[i][j] - '0';
        for(int i = 1; i + 2 <= n; i += 1)
            for(int j = 1; j <= m; j += 1)
                if(a[i][j] == 1){
                    if(j < m) fuck(i, j, i + 1, j, i + 1, j + 1);
                    else fuck(i, j, i + 1, j, i + 1, j - 1);
                }
        for(int i = 1; i + 2 <= m; i += 1){
            if(a[n - 1][i] == 1) fuck(n - 1, i, n - 1, i + 1, n, i + 1);
            if(a[n][i] == 1) fuck(n, i, n, i + 1, n - 1, i + 1);
        }
        vector<vector<int>> ch = {
            {n - 1, m - 1, n - 1, m, n, m - 1},
            {n - 1, m - 1, n - 1, m, n, m},
            {n - 1, m - 1, n, m - 1, n, m},
            {n - 1, m, n, m - 1, n, m}
        };
        for(int i = 0; i < 16; i += 1){
            for(int j = 0; j < 4; j += 1) if((i >> j) & 1){
                a[ch[j][0]][ch[j][1]] ^= 1;
                a[ch[j][2]][ch[j][3]] ^= 1;
                a[ch[j][4]][ch[j][5]] ^= 1;
            }
            if(a[n - 1][m - 1] == 0 and a[n - 1][m] == 0 and a[n][m - 1] == 0 and a[n][m] == 0){
                for(int j = 0; j < 4; j += 1) if((i >> j) & 1) ans.push_back(ch[j]);
                break;
            }
            for(int j = 0; j < 4; j += 1) if((i >> j) & 1){
                a[ch[j][0]][ch[j][1]] ^= 1;
                a[ch[j][2]][ch[j][3]] ^= 1;
                a[ch[j][4]][ch[j][5]] ^= 1;
            }
        }
        cout << ans.size() << '\n';
        for(auto v : ans){
            for(int x : v) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}