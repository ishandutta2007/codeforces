#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %s", &n, s);
    str = s;
    sort(str.begin(), str.end());

    printf("%s\n", str.c_str());
    if(--t) goto st;
    return 0;
}