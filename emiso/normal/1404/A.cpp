#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, k, n, ans, a[MN], tp[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld %s", &n, &k, s);
    str = s;

    for(int i = 0; i < k; i++) tp[i] = -1;
    int flag = 1;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(tp[i % k] == -1 || tp[i % k] == 1) tp[i % k] = 1;
            else tp[i % k] = -2, flag = 0;
        }
        if(s[i] == '0') {
            if(tp[i % k] == -1 || tp[i % k] == 0) tp[i % k] = 0;
            else tp[i % k] = -2, flag = 0;
        }
    }

    int n0 = 0, n1 = 0, ni = 0;
    for(int i = 0; i < k; i++) {
        if(tp[i] == 0) n0++;
        if(tp[i] == 1) n1++;
        if(tp[i] == -1) ni++;
    }

    if(abs(n0 - n1) > ni) flag = 0;

    puts(flag ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}