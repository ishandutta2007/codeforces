#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 450000;
using LL = long long;
int cnt[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    set<pair<int, int>> sp;
    int q, x;
    cin >> q >> x;
    for(int i = 0; i < x; i += 1) sp.insert({0, i});
    for(int i = 0; i < q; i += 1){
        int y;
        cin >> y;
        y %= x;
        sp.erase({cnt[y], y});
        sp.insert({cnt[y] += 1, y});
        cout << sp.begin()->first * x + sp.begin()->second << "\n";
    }
    return 0;
}