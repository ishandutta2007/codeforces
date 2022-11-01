#include <bits/stdc++.h>

using namespace std;

int n, l, r, x, y;
vector<pair<int, int>> v;

int main() {
    scanf("%d", &n);
    l = r = -1;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &y, &x);
        v.emplace_back(x, y);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        x = v[i].first, y = v[i].second;
        if(x <= l && y <= r);
        else if(x >= l && y >= r) {
            l = x;
            r = y;
        }
        else l = r = max(y, r);
    }
    printf("%d\n", l);
    return 0;
}