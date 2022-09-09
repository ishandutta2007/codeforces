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
        int n, ok = 1;
        cin >> n;
        vector<pair<int, int>> vp(n);
        for(int i = 0; i < n; i += 1)
            cin >> vp[i].first >> vp[i].second;
        ok &= vp[0].first >= vp[0].second;
        for(int i = 1; i < n; i += 1) ok &= vp[i].first - vp[i - 1].first >= vp[i].second - vp[i - 1].second and vp[i].second >= vp[i - 1].second;
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}