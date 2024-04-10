#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i += 1){
        cin >> v[i];
        mp[v[i]].push_back(i);
    }
    vector<int> rp;
    for(auto& [x, v] : mp)
        if(v.size() >= 2) rp.push_back(x); 
    if(rp.size() >= 2){
        int x = rp[0], y = rp[1];
        cout << "YES\n";
        cout << mp[x][0] << " " << mp[y][0] << " " << mp[x][1] << " " << mp[y][1];
        return 0;
    }
    vector<pair<int, int>> vp(5000000 + 1);
    int x = 0;
    if(rp.size() == 1){
        x = rp[0];
        auto& vv = mp[x];
        if(vv.size() >= 4){
            cout << "YES\n";
            cout << mp[x][0] << " " << mp[x][1] << " " << mp[x][2] << " " << mp[x][3];
            return 0;
        }
        if(vv.size() >= 2){
            for(int i = 1; i <= n; i += 1) if(mp.count(x + x - v[i])) if(v[i] != x){
                cout << "YES\n";
                cout << mp[x][0] << " " << mp[x][1] << " " << i << " " << mp[x + x - v[i]][0];
                return 0;
            }
        }
    }
    for(int i = 1; i <= n; i += 1) if(x == 0 or x != v[i] or i == mp[x][0])
        for(int j = i + 1; j <= n; j += 1) if(x == 0 or x != v[j] or j == mp[x][0]){
            if(vp[v[i] + v[j]].first){
                cout << "YES\n";
                cout << i << " " << j << " " << vp[v[i] + v[j]].first << " " << vp[v[i] + v[j]].second;
                return 0;
            }
            else{
                vp[v[i] + v[j]] = {i, j};
            }
        }
    cout << "NO\n";
    return 0;
}