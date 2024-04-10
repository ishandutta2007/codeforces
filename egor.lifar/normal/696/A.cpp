#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <unordered_map>
#include <cassert>


using namespace std;


int q;
map<pair<long long, long long>, long long> cost;


vector<long long> dist(long long u, long long v) {
    vector<long long> g, g1;
    while (u != 1LL) {
        g.push_back(u);
        u /= 2LL;
    }
    g.push_back(1LL);
    while (v != 1LL) {
        g1.push_back(v);
        v /= 2LL;
    }
    g1.push_back(1LL);
    reverse(g.begin(), g.end());
    reverse(g1.begin(), g1.end());
    int l = 0;
    while (l < min((int)g.size(), (int)g1.size()) - 1 && g[l] == g1[l] && g[l + 1] == g1[l + 1]) {
        l++;
    }
    vector<long long> ans;
    for (int i = (int)g.size() - 1; i >= l; i--) {
        ans.push_back(g[i]);
    }
    for (int i = l + 1; i < (int)g1.size(); i++) {
        ans.push_back(g1[i]);
    }
    return ans;
}


int main() {
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t;
        long long u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            long long nw;
            cin >> nw;
            vector<long long> g = dist(u, v);
            for (int j = 0; j < (int)g.size() - 1; j++) {
                cost[make_pair(g[j], g[j + 1])] += nw;
                cost[make_pair(g[j + 1], g[j])] += nw;
            }
        } else {
            vector<long long> g = dist(u, v);
            long long ans = 0;
            for (int j = 0; j < (int)g.size() - 1; j++) {
                ans += cost[make_pair(g[j], g[j + 1])];
            }
            printf("%I64d\n", ans);
        }
    }
    return 0;
}