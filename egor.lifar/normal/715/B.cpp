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
#include <bitset>
#include <unordered_map>


using namespace std;



long long n, m, L, s, t, comps[10000];
vector<long long> dist;
vector<pair<long long, long long> > g[100000];
vector<pair<long long, pair<long long, long long> > > q;
int uk = 0;


void dijkstra(int cnt) {
    dist.assign(n, L + 1);
    dist[cnt] = 0;
    set<pair<long long, long long> > ss;
    for (int i = 0; i < n; i++) {
        ss.insert(make_pair(dist[i], i));
    }   
    while (!ss.empty()) {
        int a = (ss.begin()->second);
        ss.erase(ss.begin());
        for (auto v : g[a]) {
            if (dist[v.first] > dist[a] + v.second) {
                ss.erase(make_pair(dist[v.first], v.first));
                dist[v.first] = dist[a] + v.second;
                ss.insert(make_pair(dist[v.first], v.first));
            }
        }
    }
}


void dfs(int u) {
    comps[u] = uk;
    for (auto v : g[u]) {
        if (comps[v.first] == 0) {
            dfs(v.first);
        }
    }
}


int main() {
    cin >> n >> m >> L >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        scanf("%d %d %lld", &u, &v, &w);
        q.push_back(make_pair(u, make_pair(v, w)));
        if (w != 0LL) {
            g[u].push_back(make_pair(v, w));
            g[v].push_back(make_pair(u, w));
            continue;
        }
    }
    dijkstra(s);
    if (dist[t] < L) {
        cout << "NO" << endl;
        return 0;
    }
    for (auto &v : q) {
        if (v.second.second == 0) {
            v.second.second = 1;
            g[v.first].push_back(make_pair(v.second.first, 1));
            g[v.second.first].push_back(make_pair(v.first, 1));
            dijkstra(s);
            if (dist[t] < L) {
                v.second.second += L - dist[t];
                break;
            }
        }
    }
    dijkstra(s);
    if (dist[t] > L) {
        cout << "NO" << endl;
        return 0;
    }
    for (auto& v : q) {
        if (v.second.second == 0) {
            v.second.second = L + 1;
        }
    }
    cout << "YES" << endl;
    for (auto v : q) {
        cout << v.first << ' ' << v.second.first << ' ' << v.second.second << endl;
    }
    return 0;
}