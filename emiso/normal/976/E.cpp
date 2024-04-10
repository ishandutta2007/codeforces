#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, a, b, used;
ll h[200020], d[200020], ans, ansf;
vector<pair<ll, ll>> v;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return (a.first - a.second) > (b.first - b.second);
}

int main() {
    scanf("%d %d %d", &n, &a, &b);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &h[i], &d[i]);
        ans += d[i];
        v.emplace_back(h[i], d[i]);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++)
        h[i] = v[i].first, d[i] = v[i].second;

    ansf = ans;
    if(b) {
        int us = 0;
        for(; us < b; us++) {
            if(d[us] >= h[us]) break;
            ans -= d[us];
            ans += h[us];
        }
        for(int i = 0; i < us; i++) {
            ans -= h[i];
            ans += (h[i] << a);
            ansf = max(ansf, ans);
            ans -= (h[i] << a);
            ans += h[i];
        }
        if(us == b) {
            ans += d[us-1];
            ans -= h[us-1];
        }
        for(int i = us; i < n; i++) {
            h[i] <<= a;
            ansf = max(ansf, ans - d[i] + h[i]);
        }
    }
    printf("%lld\n", ansf);
    return 0;
}