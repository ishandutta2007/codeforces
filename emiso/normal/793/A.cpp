#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

long long a[MN], n, k;
//char s[MN]; string str;

int main() {
    scanf("%lld %lld",&n, &k);

    for(int i=0; i<n; i++) {
        scanf("%lld",&a[i]);
    } sort(a, a + n);

    int flag = 1;
    long long ans = 0;
    for(int i=0;i<n;i++) {
        if((a[i] - a[0]) % k == 0) {
            ans += ((a[i] - a[0]) / k);
        }
        else flag = 0;
    }

    if(!flag) puts("-1");
    else printf("%lld\n",ans);
    return 0;
}