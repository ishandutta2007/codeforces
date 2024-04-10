#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, a[MN];
vector<int> ans, cur;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);

    ll sum = 0;
    ans.clear();
    cur.clear();
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i] > k) continue;
        if(a[i] >= (k + 1)/2) {
            ans = {i};
        }
        else if(sum < (k + 1) / 2) {
            sum += a[i];
            cur.push_back(i);
        }
    }
    sort(a, a + n);

    if(!ans.empty()) printf("%d\n%d\n", 1, ans[0] + 1);
    else if(sum < (k + 1) / 2) puts("-1");
    else {
        printf("%d\n", cur.size());
        for(int x : cur) printf("%d ", x + 1);
        puts("");
    }

    if(--t) goto st;
    return 0;
}