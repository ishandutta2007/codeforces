#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    itn n;
    scanf("%d", &n);
    vector<pair<int, int>> ev;
    vector<int> al;
    for (int i = 0; i < n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        ev.pb({x, y});
        ev.pb({x, -y});
        al.pb(x + y);
        al.pb(x - y);
    }
    sort(all(ev), [&](const pair<int, int>& x, const pair<int, int>& y){
        return make_pair(x.x + x.y, (x.y < 0)) < make_pair(y.x + y.y, (y.y < 0));
    });
    sort(all(al));
    al.resize(unique(all(al)) - al.begin());
    int m = al.size();
    int cur = 0;
    vector<int> dp(m);
    for (int i = 0; i < n + n; i++){
        if (ev[i].x + ev[i].y != al[cur])
            cur++;
        if (cur)
            dp[cur] = max(dp[cur], dp[cur - 1]);
        if (ev[i].y > 0){
            int pos = lower_bound(all(al), ev[i].x - ev[i].y) - al.begin();
            dp[cur] = max(dp[cur], dp[pos] + 1);
        }
    }
    printf("%d\n", dp[m - 1]);

    return 0;
}