#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, a[MN];
vector<int> row2;

inline int my_rand() {
    return ((rand()<< 16) ^ rand()) & 0x7fffffff;
}

/**
15
3 1 1 2 3 1 1 2 2 3 2 1 2 3 3

7
3 1 1 2 3 1 1
**/

vector<int> occ[MN];

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        occ[a[i]].push_back(i);
    }

    ll l1 = n+1, l2 = n+1, ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == l1) {
        } else {
            if(l2 != a[i]) {
                ans++;
                auto o1 = upper_bound(occ[l1].begin(), occ[l1].end(), i);
                auto o2 = upper_bound(occ[l2].begin(), occ[l2].end(), i);
                if(o1 == occ[l1].end() || (o2 != occ[l2].end() && *o1 >= *o2)) {
                    l1 = a[i];
                } else {
                    l2 = a[i];
                }
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}