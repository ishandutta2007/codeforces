#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m, ans = 0;
        cin >> n >> m;
        vector<string> v(n);
        for(string& s : v) cin >> s;
        for(int i = 0; i + 1 < n; i += 1) ans += v[i].back() == 'R';
        for(int i = 0; i + 1 < m; i += 1) ans += v.back()[i] == 'D';
        cout << ans << "\n";
    }
    return 0;
}