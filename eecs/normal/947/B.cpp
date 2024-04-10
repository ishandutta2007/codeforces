#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n; ll v[maxn], t[maxn];
priority_queue<ll, vector<ll>, greater<ll> > q;

int main() {
    scanf("%d", &n);
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &v[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &t[i]);
        v[i] += s, s += t[i], q.push(v[i]);
        ll ans = 0;
        while (!q.empty() && q.top() <= s) {
            ans += q.top() - s + t[i], q.pop();
        }
        printf("%lld ", ans + t[i] * q.size());
    }
    return 0;
}