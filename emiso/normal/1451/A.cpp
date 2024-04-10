    #include <bits/stdc++.h>

    #define MN 1001000

    using namespace std;
    typedef long long ll;

    ll t, n, ans, a[MN];
    //char s[MN]; string str;

    int main() {
        scanf("%lld", &t);
        st:
        scanf("%lld", &n);

        if(n == 1) puts("0");
        else if(n == 2) puts("1");
        else if(n == 3) puts("2");
        else if(n % 2 == 0) puts("2");
        else puts("3");

        if(--t) goto st;
        return 0;
    }