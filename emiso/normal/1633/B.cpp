#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%s", s); str = s; int n = str.size();

    int c[2] = {0, 0};
    for(int i = 0; i < n; i++) {
        c[str[i]-'0']++;
    }

    if (c[0] != c[1]) printf("%d\n", min(c[0], c[1]));
    else printf("%d\n", c[0]-1);
    
    if(--t) goto st;
    return 0;
}