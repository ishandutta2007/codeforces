#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

ll freq[MN], a[MN], ans;

int main() {
    ll n, x;
    scanf("%lld %lld",&n, &x);

    for(int i=0; i<n; i++) {
        scanf("%lld",&a[i]);
        freq[a[i]]++;
    }

    for(int i=0; i<n; i++) {
        int desired = x ^ a[i];
        ans += freq[desired];
        if(desired == a[i]) ans--;
    }

    printf("%lld\n",ans/2);
    return 0;
}