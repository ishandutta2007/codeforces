#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, E, cnt, cnt2;
map<pair<int, int>, char> mp;

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        char op[2], c[2];
        int u, v;
        scanf("%s %d", op, &u);
        if (op[0] == '+') {
            scanf("%d %s", &v, c);
            if (mp.count({v, u}) && mp[{v, u}] == c[0]) cnt++;
            if (mp.count({v, u})) cnt2++;
            mp[{u, v}] = c[0];
        } else if (op[0] == '-') {
            scanf("%d", &v);
            if (mp.count({v, u}) && mp[{u, v}] == mp[{v, u}]) cnt--;
            if (mp.count({v, u})) cnt2--;
            mp.erase({u, v});
        } else {
            if (!(u & 1)) {
                puts(cnt ? "YES" : "NO");
            } else {
                puts(cnt2 ? "YES" : "NO");
            }
        }
    }
    return 0;
}