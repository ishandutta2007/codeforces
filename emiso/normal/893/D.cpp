#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, flag = 1;
ll ans, a[MN], maxi[MN], d;

int main() {
    scanf("%d %lld", &n, &d);

    for(int i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }

    maxi[n-1] = max(a[n-1], 0LL);
    for(int i = n-2; i >= 0; i--) {
        maxi[i] = max(0LL, maxi[i+1] + a[i]);
    }

    ll money = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            if(money < 0) {
                ans++;
                if(d - maxi[i] < 0) flag = 0;
                money = d - maxi[i];
            }
        }
        else money += a[i];
        if(money > d) flag = 0;
    }

    if(!flag) puts("-1");
    else printf("%lld\n", ans);
    return 0;
}