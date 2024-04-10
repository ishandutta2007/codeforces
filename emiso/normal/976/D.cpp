#include <bits/stdc++.h>

using namespace std;

int n, x;
vector<int> d;
vector<pair<int, int> > ed;

void solve(int nodes, int pos) {
    if(nodes <= 1) return;
    while(d.back() >= nodes) d.pop_back();
    if(d[pos] <= 0) solve(nodes - 1, pos + 1);
    else if(d.back() + 1 == nodes) {
        for(int i = 1; i < nodes; i++)
            ed.emplace_back(i, nodes);
        for(int i = pos; i < d.size(); i++)
            d[i]--;
        solve(nodes - 1, pos);
    } else solve(nodes - 1, pos);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        d.push_back(x);
    }
    solve(d.back()+1, 0);

    printf("%d\n", ed.size());
    for(auto e : ed)
        printf("%d %d\n", e.first, e.second);
    return 0;
}