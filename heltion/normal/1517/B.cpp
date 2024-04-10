#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        set<tuple<int, int, int>> st;
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < m; j += 1){
                cin >> v[i][j];
                st.insert({v[i][j], i, j});
            }
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < m; j += 1)
                v[i][j] = -1;
        for(int i = 0; i < m; i += 1){
            auto [w, x, y] = *st.begin();
            st.erase(st.begin());
            v[x][i] = w;
        }
        map<int, vector<int>> mp;
        for(auto [w, x, y] : st) mp[x].push_back(w);
        for(int i = 0; i < n; i += 1)
            for(int j = 0; j < m; j += 1)
                if(v[i][j] == -1){
                    v[i][j] = mp[i].back();
                    mp[i].pop_back();
                }
        for(int i = 0; i < n; i += 1){
            for(int j = 0 ; j < m; j += 1)
                cout << v[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}