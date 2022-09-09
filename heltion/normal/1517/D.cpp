#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    if(k & 1){
        for(int i = 0; i < n; i += 1){
            for(int j = 0; j < m; j += 1)
                cout << "-1 ";
            cout << "\n";
        }
        return 0;
    }
    vector<vector<int>> ud(n, vector<int>(m)), lr(n, vector<int>(m));
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j + 1 < m; j += 1)
            cin >> lr[i][j];
    for(int i = 0; i + 1 < n; i += 1)
        for(int j = 0; j < m; j += 1)
            cin >> ud[i][j];
    vector<vector<int>> f(n, vector<int>(m));
    for(int _ = 0; _ < k / 2; _ += 1){
        vector<vector<int>> g(n, vector<int>(m, INT_MAX));
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < m; j += 1){
                if(i > 0) g[i][j] = min(f[i - 1][j] + ud[i - 1][j], g[i][j]);
                if(i + 1 < n) g[i][j] = min(f[i + 1][j] + ud[i][j], g[i][j]);
                if(j > 0) g[i][j] = min(f[i][j - 1] + lr[i][j - 1], g[i][j]);
                if(j + 1 < m) g[i][j] = min(f[i][j + 1] + lr[i][j], g[i][j]);
            }
        swap(f, g);
    }
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < m; j += 1) cout << f[i][j] * 2 << " ";
        cout << "\n";
    }
    return 0;
}