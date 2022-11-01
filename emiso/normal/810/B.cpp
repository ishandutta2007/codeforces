#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, f, k, l, ans;
vector<ll> best;
//char s[MN]; string str;

int main() {
    scanf("%lld %lld", &n, &f);

    for(int i=0; i<n; i++) {
        scanf("%lld %lld",&k, &l);
        if(k >= l) best.pb(0);
        else best.pb(min(k, l - k));

        ans += min(l, k);
    }

    sort(best.begin(), best.end(), greater<ll>());

    for(int i=0; i<f; i++) {
        ans += best[i];
    }

    printf("%lld\n", ans);
    return 0;
}