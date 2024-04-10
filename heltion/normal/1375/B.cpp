#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300 + 1;
int a[maxn][maxn];
int t, n, m;
void work(){
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1)
            cin >> a[i][j];
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= m; j += 1){
            int k = 0;
            if(i > 1) k += 1;
            if(i < n) k += 1;
            if(j > 1) k += 1;
            if(j < m) k += 1;
            if(k < a[i][j]){
                cout << "NO\n";
                return;
            }
            a[i][j] = k;
        }
    cout << "YES\n";
    for(int i = 1; i <= n; i += 1){
        for(int j = 1; j <= m; j += 1)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(cin >> t; t; t -= 1) work();
    return 0;
}