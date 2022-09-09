#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> vp[2];
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= n; j += 1)
            vp[(i + j) % 2].push_back({i, j});
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= n; j += 1){
            int x;
            cin >> x;
            if(x != 1 and not vp[1].empty())
                cout << "1 " << vp[1].back().first << " " << vp[1].back().second << endl, vp[1].pop_back();
            else if(x != 2 and not vp[0].empty())
                cout << "2 " << vp[0].back().first << " " << vp[0].back().second << endl, vp[0].pop_back();
            else if(not vp[1].empty())
                cout << "3 " << vp[1].back().first << " " << vp[1].back().second << endl, vp[1].pop_back();
            else if(not vp[0].empty())
                cout << "3 " << vp[0].back().first << " " << vp[0].back().second << endl, vp[0].pop_back();
            else assert(0);
        }
    return 0;
}