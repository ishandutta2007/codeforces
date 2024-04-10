#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, a[MN], t[MN], ans;
map<ll, vector<ll>> v;
priority_queue<pair<ll, ll>> hold;

int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &t[i]);
        v[a[i]].emplace_back(t[i]);
    }

    ll last = -1;
    for(auto vv : v) {
        for(int j = last; !hold.empty() && j < vv.first; j++) {
            auto tt = hold.top();
            hold.pop();
            ans += tt.first * (j - tt.second);
        }

        for(ll x : vv.second)
            hold.push({x, vv.first});
        last = vv.first;
    }

    for(int j = last; !hold.empty(); j++) {
        auto tt = hold.top();
        hold.pop();
        ans += tt.first * (j - tt.second);
    }

    printf("%lld\n", ans);
    return 0;
}