#include <bits/stdc++.h>

#define MN 101000

using namespace std;
typedef long long ll;

ll n, ans, H, S;
char s[MN]; string str;

struct sh {
    ll s, h;
    sh(ll s, ll h) : s(s), h(h) {}
    bool operator > (const sh &o) const {
        return s * o.h > o.s * h;
    }
};

vector<sh> oba;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", s); str = s;

        ll tmp = 0;
        for(char c : str) {
            if(c == 's') tmp++;
            else {
                ans += tmp;
                H++;
            }
        }
        oba.emplace_back(tmp, str.size()-tmp);
    }
    sort(oba.begin(), oba.end(), greater<sh>());

    for(sh oi : oba) {
        H -= oi.h;
        ans += (oi.s * H);
    }

    printf("%lld\n", ans);
    return 0;
}