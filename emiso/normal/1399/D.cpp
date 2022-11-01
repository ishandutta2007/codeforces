#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans[MN], a;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    vector<int> open[2];
    int num = 0;

    for(int i = 1; i <= n; i++) {
        scanf("%1lld", &a);
        if(open[1-a].empty()) {
            open[a].push_back(++num);
            ans[i] = num;
        } else {
            int idx = open[1-a].back();
            open[1-a].pop_back();
            ans[i] = idx;
            open[a].push_back(idx);
        }
    }

    printf("%d\n", num);
    for(int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    puts("");

    if(--t) goto st;
    return 0;
}