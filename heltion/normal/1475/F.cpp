#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 1'000'000'007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<string> a(n), b(n);
        for(auto& s : a) cin >> s;
        for(auto& s : b) cin >> s;
        vector<vector<int>> c(n, vector<int>(n));
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < n; j += 1) c[i][j] = a[i][j] != b[i][j];
        int ok = 1;
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < n; j += 1)
                ok &= (c[i][j] ^ c[0][j]) == (c[i][0] ^ c[0][0]);
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}