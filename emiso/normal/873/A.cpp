#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, k, x;
ll ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%d %d %d", &n, &k, &x);

    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        if(i < (n - k)) ans += a[i];
        else ans += x;
    }

    printf("%lld\n", ans);
    return 0;
}