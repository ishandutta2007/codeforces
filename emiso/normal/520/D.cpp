#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000009

long long ans;
int m, x[100010], y[100010], cannot[100010];
map<pair<int, int>, int> pos;
set<int> couldbe;

void update(int x, int y, int add) {
    if(y == 0) return;

    vector<int> below;
    for(int dx = -1; dx <= 1; dx++)
        if(pos.count({x+dx, y-1}))
            below.push_back(pos[{x+dx, y-1}]);

    if(below.size() == 1) {
        cannot[below[0]] += add;
        if(add == -1 && cannot[below[0]] == 0) couldbe.insert(below[0]);
        if(add ==  1 && cannot[below[0]] == 1) couldbe.erase(below[0]);
    }
}

int main() {
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x[i], &y[i]);
        pos[{x[i], y[i]}] = i;
    }

    for(int i = 0; i < m; i++)
        update(x[i], y[i], 1);


    for(int i = 0; i < m; i++)
        if(!cannot[i])
            couldbe.insert(i);

    int t = 0, val;
    for(int z = 0; z < m; z++) {
        if(t == 0) val = *couldbe.rbegin();
        else val = *couldbe.begin();
        couldbe.erase(val);

        ans = (ans * m + val) % MOD;

        pos.erase({x[val], y[val]});
        update(x[val], y[val], -1);

        for(int dx = -1; dx <= 1; dx++)
            if(pos.count({x[val]+dx, y[val]+1}))
                update(x[val]+dx, y[val]+1, 1);

        t = 1 - t;
    }

    printf("%lld\n", ans);
    return 0;
}