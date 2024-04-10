#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1){
        int n;
        cin >> n;
        map<int, vector<int>> mp, mp2;
        int ans = 0;
        for (int i = 0; i < n; i += 1) {
            for (int j = 0, v; j < n; j += 1) {
                cin >> v;
                mp[j - i].push_back(v);
                mp2[i + j].push_back(v); 
            }
        }
        for (auto [x, y] : mp) if ((x % 4 + 4) % 4 == 1) {
            for (int i = 0; i < y.size(); i += 2) ans ^= y[i];
        } 
        for (auto [x, y] : mp2) if ((x % 4 + 4) % 4 == 0) {
            for (int i = 0; i < y.size(); i += 2) ans ^= y[i];
        }
        cout << ans << "\n";
    }
}