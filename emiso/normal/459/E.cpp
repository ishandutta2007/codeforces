#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edg[300030];
int n, m, ans, maxi[300030];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edg[c].emplace_back(a, b);
    }

    for(int i = 300003; i >= 0; i--) {
        vector<pair<int, int>> changes;
        for(auto p : edg[i]) {
            if(maxi[p.first] < maxi[p.second] + 1) {
                changes.emplace_back(p.first, maxi[p.second] + 1);
            }
        }

        for(auto p : changes) {
            maxi[p.first] = max(maxi[p.first], p.second);
            ans = max(ans, maxi[p.first]);
        }
    }

    printf("%d\n", ans);
    return 0;
}