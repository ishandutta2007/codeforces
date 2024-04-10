#include <bits/stdc++.h>
#define MN 100100

using namespace std;
typedef long long ll;

const ll INF = 1000000000000000000LL;
ll n, m, a, d, t[MN], T, ans, fac, nT, nM, nA;

ll mult(ll a, ll b) {
    long double prelim = a * b;
    if(prelim > LLONG_MAX) return LLONG_MAX;
    return a * b;
}

ll sum(ll a, ll b) {
    long double prelim = a + b;
    if(prelim > LLONG_MAX) return LLONG_MAX;
    return a + b;
}

int main() {
    scanf("%lld %lld %lld %lld", &n, &m, &a, &d);
    for(int i = 0; i < m; i++) {
        scanf("%lld", &t[i]);
    }

    ll ia = 1, im = 0;
    fac = (d / a + 1);

    while(ia < (n + 1) && im < m) {
        if(T == t[im]) {
            nT = T + d;
            nM = upper_bound(t, t + m, nT) - t;
            nA = nT / a + 1;

            im = nM;
            ia = nA;
            T = nT;
            ans++;
        }
        else if(T == ia*a) {
            ll l = 0, r = ((n - ia + 1) / fac) + (((n - ia + 1) % fac) > 0) - 1, md;
            //printf("que %lld %lld\n", l, r);
            while(l < r) {
                md = (l + r + 1) >> 1;
                if(mult(a, sum(ia, mult(md, fac))) >= t[im])
                    r = md - 1;
                else l = md;
            }
            ans += l;
            nA = ia + l*fac;
            T = nA * a;

            nT = T + d;
            nM = upper_bound(t, t + m, nT) - t;
            nA = nT / a + 1;

            im = nM;
            ia = nA;
            T = nT;
            ans++;
        }
        else T = min(ia*a, t[im]);
        //printf("T %lld ans %lld ia %lld im %lld\n", T, ans, ia, im);
    }
    //cerr << fac << endl;

    while(ia < n + 1) {
        if(T == ia*a) {
            ll l = 0, r = INF, md;
            ans += ((n - ia + 1) / fac) + (((n - ia + 1) % fac) > 0);
            break;
        }
        else T = ia*a;
    }
    while(im < m) {
        if(T == t[im]) {
            nT = T + d;
            nM = upper_bound(t, t + m, nT) - t;
            nA = nT / a + 1;

            im = nM;
            ia = nA;
            T = nT;
            ans++;
        }
        else T = t[im];
    }

    printf("%lld\n", ans);
    return 0;
}