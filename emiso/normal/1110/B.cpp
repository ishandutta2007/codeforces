#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1000100

int n, a[MN], ans, m, k;

int main() {
    scanf("%d %d %d", &n, &m, &k);

    ans = n;
    vector<int> dists;

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(i) dists.push_back(a[i] - a[i-1] - 1);
    }
    sort(dists.begin(), dists.end());

    for(int i = k, j = 0; i < n; i++, j++) {
        ans += dists[j];
    }

    printf("%d\n", ans);
    return 0;
}