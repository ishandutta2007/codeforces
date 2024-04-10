#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, ans, a[MN];
char s[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld %s", &n, &k, s);

    if(n == 1) {
        if(s[0] == 'L') printf("%lld\n", k);
        else printf("1\n");
    } else {
        vector<int> seg;
        int sum = 0, last = 0, cur = 0, rem = 0, ok = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'L') {
                cur++;
                last = 0;
            }
            if(s[i] == 'W') {
                if(cur) {
                    if(ok == 0) rem += cur;
                    else seg.push_back(cur);
                }
                sum += 1 + last;
                cur = 0;
                last = 1;
                ok = 1;
            }
        }
        rem += cur;

        sort(seg.rbegin(), seg.rend());
        while(!seg.empty() && k >= seg.back()) {
            sum += 2*seg.back() + 1;
            k -= seg.back();
            seg.pop_back();
        }

        if(!seg.empty()) {
            sum += 2 * k;
            k = 0;
        } else {
            sum += min(2*k, 2LL*rem);
            if(ok == 0 && sum) sum--;
        }
        printf("%d\n", sum);
    }

    if(--t) goto st;
    return 0;
}