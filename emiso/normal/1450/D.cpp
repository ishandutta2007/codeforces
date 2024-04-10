#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans[MN], a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    ll mini = 2;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        mini = min(mini, a[i]);
    }

    multiset<ll> pq;
    set<ll> qq;
    if(mini == 2) {
        printf("%s\n", string(n, '0').c_str());
        goto nxt;
    }

    for(int i = 1; i <= n; i++) ans[i] = 0, pq.insert(a[i]), qq.insert(a[i]);
    if(qq.size() == n) ans[1] = 1;

    for(int i = 1, l = 1, r = n, cnt = 1; i <= n; i++) {
        if(a[l] == cnt && a[r] != cnt) {
            pq.erase(pq.find(cnt));
            ans[n-i+1] = 1;
            if(pq.find(cnt) != pq.end()) break;
            cnt++;
            l++;
        } else if(a[l] != cnt && a[r] == cnt) {
            pq.erase(pq.find(cnt));
            ans[n-i+1] = 1;
            if(pq.find(cnt) != pq.end()) break;
            cnt++;
            r--;
        } else if(a[l] == cnt && a[r] == cnt) {
            if(r - l + 1 == n-i+1) ans[n-i+1] = 1;
            break;
        } else if(r - l + 1 == n-i+1 && *pq.begin() == cnt) {
            ans[n-i+1] = 1;
            break;
        } else break;
    }

    for(int i = 1; i <= n; i++)
        printf("%lld", ans[i]);
    puts("");
    nxt:;
    if(--t) goto st;
    return 0;
}