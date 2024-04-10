#include <bits/stdc++.h>

#define MN 1000100

using namespace std;

int n, a[100010], b[100010];
map<int, set<pair<int, int>>> adj;
map<int, int> deg;

void cant() {
    puts("-1");
    exit(0);
}

void euler_cycle(int node, vector<int> &ret, vector<int> &cur) {
    if(adj[node].empty()) {
        ret.push_back(node);
        if(!cur.empty()) {
            node = cur.back();
            cur.pop_back();
            euler_cycle(node, ret, cur);
        }
    } else {
        cur.push_back(node);
        auto edge = *adj[node].begin();
        adj[node].erase(edge);
        adj[edge.first].erase({node, edge.second});
        euler_cycle(edge.first, ret, cur);
    }
}

vector<int> euler_cycle(int node) {
    vector<int> ret, cur;
    euler_cycle(node, ret, cur);
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i + 1 < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i + 1 < n; i++) {
        scanf("%d", &b[i]);
        if(a[i] > b[i]) cant();

        adj[a[i]].insert({b[i], i});
        if(a[i] != b[i]) adj[b[i]].insert({a[i], i});

        deg[a[i]]++;
        deg[b[i]]++;
    }

    vector<int> ret, odd;
    for(auto tt : deg)
        if(tt.second % 2)
            odd.push_back(tt.first);
            
    if(odd.size() == 2) ret = euler_cycle(odd[0]);
    else if(odd.empty()) ret = euler_cycle(b[0]);

    if(ret.size() < n) cant();
    for(int x : ret) printf("%d ", x);

    return 0;
}