#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k, c[100010], p[100010];

vector<pair<ll, ll> > v;
map<ll, ll> rev;
priority_queue <ll> pq;
ll sum, ans[100010];

int main() {
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        rev[p[i]] = i;
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        v.emplace_back(p[i], c[i]);
    }

    sort(v.begin(), v.end());

    for(auto vp : v) {
        ll P = vp.first, C = vp.second;
        ans[rev[P]] = C + sum;

        sum += C;
        pq.push(-C);
        while(pq.size() > k) {
            sum += pq.top();
            pq.pop();
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }

    return 0;
}