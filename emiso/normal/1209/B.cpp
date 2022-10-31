#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], b[MN], cur, s[MN];
priority_queue<pair<int, int>> ev;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%1lld", &s[i]);
        cur += s[i];
    }
    ans = cur;

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &a[i], &b[i]);
        ev.push({-b[i], i});
    }

    int last = -1;
    while(!ev.empty() && ev.top().first > -10000) {
        auto tt = ev.top();
        ev.pop();

        if(last != tt.first) ans = max(ans, cur);
        last = tt.first;

        int id = tt.second;
        if(s[id] == 0) {
            s[id] = 1;
            cur++;
        } else {
            s[id] = 0;
            cur--;
        }

        ev.push({tt.first - a[id], id});
    }
    ans = max(ans, cur);

    printf("%lld\n", ans);
    return 0;
}