#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);

    string flag = "YES";
    for(int i = 1; i < n; i++) {
        if(a[i] - a[i-1] > 1) flag = "NO";
    }

    puts(flag.c_str());
    if(--t) goto st;
    return 0;
}