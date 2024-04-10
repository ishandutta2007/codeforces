#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

bool cmp(pii a, pii b) {
    return (a.first - a.second) < (b.first - b.second);
}

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    vector<pii> it(n);
    for(int i=0;i<n;i++) {
        scanf("%d", &it[i].first);
    }
    for(int i=0;i<n;i++) {
        scanf("%d", &it[i].second);
    }
    sort(it.begin(), it.end(), cmp);

    int ans = 0, buy = 0;
    for(int i=0;i<n;i++) {
        if(buy < k || (it[i].first - it[i].second <= 0)) {
            ans += it[i].first;
            buy++;
        }

        else {
            ans += it[i].second;
        }
    }

    printf("%d\n", ans);
    return 0;
}