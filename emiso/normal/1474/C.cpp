#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, a[MN], maxi, mark[2010];
vector<pair<ll, ll>> ans, pos;
multiset<int> f, tmp;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i < 2*n; i++) {
        scanf("%lld", &a[i]);
        f.insert(a[i]);
    }
    maxi = 0;
    sort(a, a + 2*n, greater<ll>());

    int flag = 0;
    for(int fst = 1; !flag && fst < 2*n; fst++) {
        tmp = f;
        pos.clear();

        ll x = a[fst] + a[maxi];
        pos.emplace_back(a[maxi], a[fst]);
        tmp.erase(tmp.find(a[maxi]));
        tmp.erase(tmp.find(a[fst]));

        x = a[maxi];
        int can = 1;
        while(can && !tmp.empty()) {
            int mm = *tmp.rbegin();
            tmp.erase(tmp.find(mm));

            auto other = tmp.find(x - mm);
            if(other == tmp.end()) can = 0;
            else {
                pos.emplace_back(mm, *other);
                tmp.erase(other);
                x = mm;
            }
        }

        if(can) {
            flag = 1;
            ans = pos;
        }
    }

 ///   vai ate 2*n

    if(!flag) puts("NO");
    else {
        puts("YES");
        printf("%lld\n", ans[0].first + ans[0].second);
        for(auto tt : ans) printf("%lld %lld\n", tt.first, tt.second);
    }
    ans.clear();
    tmp.clear();
    f.clear();

    if(--t) goto st;
    return 0;
}