#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    priority_queue<ll> o, e;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i] & 1) o.push(a[i]);
        else e.push(a[i]);
    }

    ans = 0;
    for(int i = 0, m = 1; !o.empty() || !e.empty(); i++, m = -m) {
        int to = o.empty() ? 0 : o.top();
        int te = e.empty() ? 0 : e.top();
        if(to > te) o.pop();
        else {
            e.pop();
            ans += m*te;
        }
        swap(o, e);
    }

    if(ans == 0) puts("Tie");
    else if(ans < 0) puts("Bob");
    else puts("Alice");

    if(--t) goto st;
    return 0;
}