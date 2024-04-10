#include <bits/stdc++.h>
#define MN 100100

using namespace std;
typedef long long ll;

int n, p[MN], visit[MN], c = 1, counte;
ll ans = 0;
vector<ll> sizes;

void dfs(int no, int co) {
    if(visit[no]) return;
    visit[no] = co;
    counte++;
    dfs(p[no], c);
}

ll comb2(ll x) {
    return x * (x - 1) / 2;
}

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    for(int i = 1; i <= n; i++) {
        if(!visit[i]) {
            counte = 0;
            dfs(i, c++);
            sizes.push_back(counte);
        }
    }

    sort(sizes.begin(), sizes.end(), greater<ll>());
    if(sizes.size() > 1) {
        ans += (sizes[0] + sizes[1])*(sizes[0] + sizes[1]);
    }
    else ans += sizes[0] * sizes[0];

    for(int i = 2; i < sizes.size(); i++) {
        ans += sizes[i] * sizes[i];
    }

    printf("%lld\n", ans);
    return 0;
}