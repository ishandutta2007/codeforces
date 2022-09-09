#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for(auto& v : a) for(int& x : v) cin >> x;
    int ans = 0;
    vector<int> ansv(m);
    vector<deque<int>> vd(m);
    for(int i = 0, j = 0; i < n; i += 1){
        j = max(i, j);
        while(j < n){
            int pk = 0;
            for(int x = 0; x < m; x += 1) pk += max(a[j][x], vd[x].empty() ? 0 : a[vd[x].front()][x]);
            if(pk <= k){
                for(int x = 0; x < m; x += 1){
                    while(not vd[x].empty() and a[vd[x].back()][x] <= a[j][x]) vd[x].pop_back();
                    vd[x].push_back(j);
                }
                j += 1;
            }
            else break;
        }
        if(j - i > ans){
            ans = j - i;
            for(int x = 0; x < m; x += 1) ansv[x] = a[vd[x].front()][x];
        }
        for(int x = 0; x < m; x += 1) if(not vd[x].empty() and vd[x].front() == i) vd[x].pop_front();
    }
    for(int x : ansv) cout << x << " ";
    return 0;
}