#include <bits/stdc++.h>

using namespace std;

int t, n, l[200020], r[200020], inside[3030][6030];
vector<pair<int, int>> ev[200010];

int main() {
    scanf("%d", &t);
    start:

    scanf("%d", &n);
    vector<int> ys({0, 200000});
    l[0] = 0, r[0] = 200000;
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        ys.push_back(l[i]);
        ys.push_back(r[i]);
    }

    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    for(int i = 0; i <= n; i++) {
        l[i] = lower_bound(ys.begin(), ys.end(), l[i]) - ys.begin();
        r[i] = lower_bound(ys.begin(), ys.end(), r[i]) - ys.begin();
        ev[l[i]].emplace_back(r[i], i);
    }
    for(int i = 0; i <= ys.back(); i++) {
        sort(ev[i].begin(), ev[i].end());
    }

    for(int x = ys.back(); x >= 0; x--) {
        for(auto seg : ev[x]) {
            int y = seg.first, i = seg.second;
            inside[i][y+1] = 0;
            for(int k = y; k >= x; k--) {
                inside[i][k] = inside[i][k+1];
                for(auto seg2 : ev[k]) {
                    int lim = seg2.first, j = seg2.second;
                    if(lim <= y)
                        inside[i][k] = max(inside[i][k], inside[j][k] + inside[i][lim+1]);
                }
            }
            inside[i][x]++;
        }
    }
    printf("%d\n", inside[0][0] - 1);

    for(int i = 0; i <= ys.back(); i++) {
        ev[i].clear();
    }
    if(--t) goto start;
    return 0;
}