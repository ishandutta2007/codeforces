#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, id[maxn];
pair<ll, ll> p[maxn];
long long sum, ans;
map<ll, ll> mp1, mp2;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &p[i].first);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &p[i].second);
        sum += abs(p[i].first - p[i].second);
    }
    sort(p + 1, p + n + 1);
    iota(id + 1, id + n + 1, 1);
    sort(id + 1, id + n + 1, [&](int x, int y) { return p[x].second < p[y].second; });
    mp1[0] = 1e18, mp2[LLONG_MAX] = 1e18;
    auto upd = [&](map<ll, ll> &mp, ll p, ll v, bool type) {
        if (!type) {
            if ((--mp.upper_bound(p))->second < v) return;
            mp[p] = v;
            while (1) {
                auto it = mp.upper_bound(p);
                if (it == mp.end() || it->second < v) break;
                p = it->first, mp.erase(it);
            }
        } else {
            if (mp.lower_bound(p)->second < v) return;
            mp[p] = v;
            while (1) {
                auto it = mp.lower_bound(p);
                if (it == mp.begin() || (--it)->second < v) break;
                p = it->first, mp.erase(it);
            }
        }
    };
    for (int i = 1, j = 1; i <= n; i++) {
        for (; j <= n && p[i].first >= p[id[j]].second; j++) {
            ll v = abs(p[id[j]].first - p[id[j]].second);
            upd(mp1, p[id[j]].first, -p[id[j]].first - p[id[j]].second - v, 0);
            upd(mp2, p[id[j]].first, p[id[j]].first - p[id[j]].second - v, 1);
        }
        ans = min(ans, p[i].first + p[i].second - abs(p[i].first - p[i].second)
            + (--mp1.upper_bound(p[i].second))->second);
        ans = min(ans, p[i].first - p[i].second - abs(p[i].first - p[i].second)
            + mp2.lower_bound(p[i].second)->second);
    }
    mp1.clear(), mp1[0] = 1e18;
    for (int i = n, j = n; i; i--) {
        for (; j && p[i].first <= p[id[j]].second; j--) {
            ll v = abs(p[id[j]].first - p[id[j]].second);
            upd(mp1, p[id[j]].first, -p[id[j]].first + p[id[j]].second - v, 0);
        }
        ans = min(ans, -p[i].first + p[i].second - abs(p[i].first - p[i].second)
            + (--mp1.upper_bound(p[i].second))->second);
    }
    printf("%lld\n", sum + ans);
    return 0;
}