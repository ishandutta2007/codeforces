#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1200;
int a[maxn];
vector<pair<int, int>> v[maxn];
int ans[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m = 0;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        m = max(m, a[i]);
    }
    m += 1;
    v[1].push_back({1, m});
    for(int i = 1; i <= n; i += 1){
        if(v[i].size() == 0){
            for(int j = 1; j <= a[i]; j += 1) ans[j][i] = 1;
            continue;
        }
        auto p = v[i][0];
        int x = m - (p.second - p.first + 1);
        int y = max(a[i] - x, 1);
        for(int j = p.first; j < p.first + y; j += 1) ans[j][i] = 1;
        int z = a[i] - y;
        for(int j = 1; j <= m and z; j += 1) if(j < p.first or j > p.second) ans[j][i] = 1, z -= 1;
        if(y > 1) v[i + 1].push_back({p.first, p.first + y - 1});
        if(p.first + y < p.second) v[i + 1].push_back({p.first + y, p.second});
        for(int j = 1; j < (int)v[i].size(); j += 1) v[i + 1].push_back(v[i][j]);
    }
    cout << m << "\n";
    for(int i = 1; i <= m; i += 1){
        for(int j = 1; j <= n; j += 1) cout << ans[i][j];
        cout << "\n";
    }
    return 0;
}