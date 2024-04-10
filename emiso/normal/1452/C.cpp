#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%s", s);
    str = s; n = str.size();

    ans = 0;
    queue<int> qp, qc;
    for(int i = 0; i < n; i++) {
        if(str[i] == '[') qc.push(i);
        if(str[i] == '(') qp.push(i);
        if(str[i] == ')' && !qp.empty()) {
            qp.pop();
            ans += 1;
        }
        if(str[i] == ']' && !qc.empty()) {
            qc.pop();
            ans += 1;
        }
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}