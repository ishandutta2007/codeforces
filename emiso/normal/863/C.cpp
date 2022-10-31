#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> p3l;

map<pll, p3l> previ;
int a, b, al[4][4], bo[4][4];
ll k, sa, sb, len, dA, dB;

void nxt() {
    if(b == a + 1 || (a == 3 && b == 1)) sb++;
    if(a == b + 1 || (b == 3 && a == 1)) sa++;

    int tmpa, tmpb;
    tmpa = al[a][b];
    tmpb = bo[a][b];

    a = tmpa;
    b = tmpb;

}

int main() {
    scanf("%lld %d %d", &k, &a, &b);

    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
            scanf("%d", &al[i][j]);

    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
            scanf("%d", &bo[i][j]);

    ll t = 0;
    while(k) {
        if(previ.count({a, b})) {
            len = t - previ[{a, b}].first;
            dA = sa - previ[{a, b}].second.first;
            dB = sb - previ[{a, b}].second.second;
            break;
        }
        previ[{a, b}] = {t, {sa, sb}};

        nxt();
        t++;
        k--;
    }

    if(k) {
        sa += (k / len) * dA;
        sb += (k / len) * dB;
        k %= len;
    }

    while(k--) {
        nxt();
    }

    printf("%lld %lld\n", sa, sb);

    return 0;
}