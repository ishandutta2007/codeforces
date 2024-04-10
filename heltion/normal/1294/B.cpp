#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<pair<int, int>> vp(n + 1);
        for(int i = 1; i <= n; i += 1) cin >> vp[i].first >> vp[i].second;
        sort(vp.begin(), vp.end());
        bool ok = true;
        for(int i = 1; i <= n; i += 1)
                ok &= vp[i].second >= vp[i - 1].second;
        if(ok){
            cout << "YES\n";
            for(int i = 1; i <= n; i += 1){
                for(int j = 0; j < vp[i].first - vp[i - 1].first; j += 1) cout << 'R';
                for(int j = 0; j < vp[i].second - vp[i - 1].second; j += 1) cout << 'U';
            }
            cout << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}