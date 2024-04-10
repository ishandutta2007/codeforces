#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k, m, co, deg[300003], resp[300003];

int calc(int n) {
    co = 0;
    memset(deg, 0, sizeof deg);
    for(int i = 1; i <= n; i++) {
        for(int j = i+i; j <= n; j += i) {
            co++;
            deg[j]++;
        }
    }
    return co;
}

int main() {
    scanf("%d %d", &n, &k);

    int l = 1, r = n+1;
    while(l < r) {
        m = (l + r) / 2;
        if(calc(m) < k) l = m + 1;
        else r = m;
    } m = l; calc(m);

    if(m > n) {
        puts("No");
        return 0;
    }

    for(int i = 1; i <= m; i++)
        resp[i] = 1;

    priority_queue<pair<int, int> > pq;
    for(int i = m/2+1; i <= m; i++) pq.push({deg[i], i});

    while(co >= k && !pq.empty()) {
        auto x = pq.top(); pq.pop();
        if(k + x.first > co) continue;
        co -= x.first;
        resp[x.second] = 0;
        m--;
    }

    if(co > k) puts("No");
    else {
        puts("Yes");
        printf("%d\n", m);
        for(int i = 1; i <= n; i++)
            if(resp[i]) printf("%d ", i);
    }

    return 0;
}