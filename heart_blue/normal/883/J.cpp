
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    while(cin >> n >> m) {
        vector<long long> a(n), b(m), p(m);
        for(auto& x : a) cin >> x;
        for(auto& x : b) cin >> x;
        for(auto& x : p) cin >> x;

        vector<pair<long long, int>> stk;
        for(int i = 0; i < n; ++i) {
            while(stk.size() && a[i] >= stk.back().first) stk.pop_back();
            stk.emplace_back(a[i], i);
        }

        multiset<pair<long long, long long>> goods;
        for(int i = 0; i < m; ++i) goods.insert({b[i], p[i]});

        vector<vector<long long>> ls(stk.size());
        for(int i = stk.size() - 1; i >= 0; --i) {
            long long x = stk[i].first;
            while(goods.size() && goods.begin()->first <= x) {
                ls[i].emplace_back(goods.begin()->second);
                goods.erase(goods.begin()); 
            }
        }

        int ans = 0;
        partial_sum(a.begin(), a.end(), a.begin());
        multiset<long long> can;
        for(int i = stk.size() - 1; i >= 0; --i) {
            int id = stk[i].second;
            long long money = i == 0 ? a[id] : a[id] - a[stk[i - 1].second];
            for(auto x : ls[i]) can.insert(x);
            // cout << id << ' ' << money << endl;
            // cout << "do:"<<endl;
            // for(auto x : can) cout << x << ' ';cout <<endl;
            while(can.size() && money > 0) {
                auto x = *can.begin();
                can.erase(can.begin());
                if(money >= x) {
                    money -= x;
                    ++ans;
                }
                else {
                    x -= money;
                    money = 0;
                    can.insert(x);
                }
            }
        }
        cout << ans << endl;

        // cout << endl;
    }
    return 0;
}