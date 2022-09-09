#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m, x;
        cin >> n >> m >> x;
        set<pair<LL, int>> sp;
        vector<LL> v(m);
        for(int i = 0; i < m; i += 1) sp.insert({0, i});
        cout << "YES\n";
        for(int i = 1; i <= n; i += 1){
            int h;
            cin >> h;
            auto p = *sp.begin();
            sp.erase(p);
            int j = p.second;
            v[j] += h;
            sp.insert({v[j], j});
            cout << j + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}