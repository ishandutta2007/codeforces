#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, m, ans, a[MN], b[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%1lld", &a[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%1lld", &b[i]);
    }

    int ii = n-1, jj = m-1;
    ans = 1;
    int f[2] = {0, 0};

    while (jj > 0) {
        if (a[ii] != b[jj]) ans = 0;
        jj--;
        ii--;
    }
    for (int i = 0; i <= ii; i++)
        f[a[i]]++;
    
    ans &= (f[b[0]] > 0);

    puts(ans ? "Yes" : "No");
    if(--t) goto st;
    return 0;
}