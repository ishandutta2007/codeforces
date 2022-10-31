#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int n, x[1010], y[1010];
long long ans, tot;

map<pii, set<pii>> retas;
set<int> vert;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        for(int j = 0; j < i; j++) {
            int dx = x[i] - x[j], dy = y[i] - y[j];

            if(dx == 0) {
                vert.insert(x[i]);
                continue;
            }

            if(dx < 0) {dx = -dx, dy = -dy;}
            int g = __gcd(dx, abs(dy));
            dx /= g; dy /= g;

            pii b = {x[i] * dy - y[i] * dx, dx};
            if(b.first < 0) {b.first *= -1; b.second *= -1;}
            g = __gcd(b.first, b.second);
            b.first /= g; b.second /= g;

            retas[{dx, dy}].insert(b);
        }
    }

    tot = vert.size();
    for(auto tt : retas) tot += tt.second.size();

    ans = 1LL * vert.size() * (tot - vert.size());
    for(auto tt : retas) ans += 1LL * tt.second.size() * (tot - tt.second.size());

    printf("%lld\n", ans / 2);
    return 0;
}