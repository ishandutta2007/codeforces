#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    map<ll, ll> divi;
    ll tmp = n;
    for(ll i = 2; i * i <= tmp; i++) {
        while(tmp % i == 0) {
            divi[i]++;
            tmp /= i;
        }
    }
    if(tmp > 1) divi[tmp]++;


    vector<pair<ll, ll>> divs(divi.begin(), divi.end());
    sort(divs.begin(), divs.end(), [&](pair<ll, ll> &a, pair<ll, ll>& b) {
        return a.second < b.second;
    });

    ll mult = 1, sz = divs.back().second;
    vector<ll> ans;
    for(int i = 0; i < sz; i++) {
        while(!divs.empty() && divs.back().second >= sz - i) {
            mult *= divs.back().first;
            divs.pop_back();
        }
        ans.push_back(mult);
    }


    printf("%d\n", ans.size());
    for(ll x : ans) printf("%lld ", x);
    puts("");

    if(--t) goto st;
    return 0;
}