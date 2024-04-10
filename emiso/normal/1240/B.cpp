#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], q, sorted, f[MN], rdep[MN];
set<int> num, ainda;
vector<int> dep[MN], ent;

int main() {
    scanf("%lld", &q);
    while(q--) {
        scanf("%lld", &n);
        for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            f[a[i]]++;
        }

        sorted = 1;
        for(int i = n-1; i >= 0; i--) {
            num.insert(a[i]);
            auto tt = num.lower_bound(a[i]);
            ll x;

            if(tt != num.begin()) {
                sorted = 0;
                tt = prev(tt);
                x = *tt;
            }
            else x = 0;

            dep[x].push_back(a[i]);
            rdep[a[i]] = max(rdep[a[i]], x);
        }

        int ans = 9999999, l = 0;

        if(sorted) {
            printf("0\n");
            goto clean;
        }

        ainda = num;
        ent = vector<int>(num.begin(), num.end());

        /// cuida do 0
        for(int y : dep[0]) {
            if(rdep[y] == 0) {
                ainda.erase(y);
            }
        } {
            int r = 0;
            if(!ainda.empty()) {
                int fst = *ainda.begin();
                r = ent.end() - lower_bound(ent.begin(), ent.end(), fst);
            }
            ans = r;
        }


        for(int x : num) {
            l++;
            ainda.erase(x);
            for(int y : dep[x]) {
                if(rdep[y] == x) {
                    ainda.erase(y);
                }
            }

            int r = 0;
            if(!ainda.empty()) {
                int fst = *ainda.begin();
                r = ent.end() - lower_bound(ent.begin(), ent.end(), fst);
            }
            ans = min(ans, l + r);
        }
        printf("%d\n", ans);

        clean:
        for(int i = 0; i < n; i++) {
            f[a[i]]--;
            dep[a[i]].clear();
            rdep[a[i]] = 0;
        }
        dep[0].clear();
        num.clear();
    }
    return 0;
}