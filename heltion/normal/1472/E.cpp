#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<pair<int, int>> vp(n);
        for(auto& [x, y] : vp) cin >> x >> y;
        vector<tuple<int, int, int>> vt;
        for(int i = 0; i < n; i += 1){
            vt.push_back({vp[i].first, vp[i].second, i});
            vt.push_back({vp[i].second, vp[i].first, i});
        }
        sort(vt.begin(), vt.end());
        vector<tuple<int, int, int>> ok;
        for(auto [x, y, z] : vt){
            if(ok.empty()) ok.push_back({x, y, z});
            else{
                auto [_, by, __] = ok.back();
                if(y < by) ok.push_back({x, y, z});
            }
        }
        for(int i = 0; i < n; i += 1){
            auto it = lower_bound(ok.begin(), ok.end(), make_tuple(vp[i].first, 0, 0));
            if(it == ok.begin()) cout << "-1 ";
            else{
                auto [_, y, z] = *prev(it);
                if(y < vp[i].second) cout << z + 1 << " ";
                else cout << "-1 ";
            }
        }
        cout << "\n";
    }
    return 0;
}