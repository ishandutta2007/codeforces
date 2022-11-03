
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
    
    int n;
    while(cin >> n) {
        map<pair<string, int>, vector<pair<string, int>>> g;
        map<string, int> mp;
        set<pair<string, int>> cur, nxt;
        pair<string, int> root;
        for(int i = 1; i <= n; ++i) {
            string s; int v; cin >> s >> v;
            if(i == 1) {
                root = {s, v};
                mp[s] = v;
            }
            int cnt; cin >> cnt;
            while(cnt--) {
                string s2; int v2; cin >> s2 >> v2;
                g[{s, v}].emplace_back(s2, v2);
            }
        }
        for(const auto& p : g[root]) cur.insert(p);
        while(cur.size()) {
            map<string, int> tmp;
            for(const auto& p : cur) {
                string s; int v; tie(s, v) = p;
                if(mp.count(s)) continue;
                tmp[s] = max(tmp[s], v);
            }
            // cout << "here" << endl;
            for(const auto& p : tmp) {
                mp[p.first] = p.second;
                // cout << p.first << ' ' << p.second << endl;
            }
            for(const auto& p : cur) {
                string s; int v; tie(s, v) = p;
                if(tmp[s] != v) continue; 
                for(const auto& p2 : g[{s, v}]) nxt.insert(p2);
            }
            // cout << "fuck" << endl;
            // for(const auto& p : nxt) cout << p.first << ' ' << p.second << endl;
            swap(cur, nxt);
            nxt.clear();
        }
        cout << mp.size() - 1 << '\n';
        for(const auto& p : mp) {
            if(p.first == root.first) continue;
            cout << p.first << ' ' << p.second << '\n';
        }
    }
    return 0;
}