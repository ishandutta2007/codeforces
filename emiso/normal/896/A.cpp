#include <bits/stdc++.h>

#define MN 101000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back

using namespace std;
typedef long long ll;

int q;
ll ans, sz[MN], k, n, lps, mps, rps;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string lp = "What are you doing while sending \"";
string mp = "\"? Are you busy? Will you send \"";
string rp = "\"?";
string str = (lp + f0 + mp + f0 + rp);

ll add(ll a, ll b, ll c, ll d, ll e) {
    long double la = a, lb = b, lc = c, ld = d, le = e;
    long double resp = la + lb + lc + ld + le;
    if(resp >= LLONG_MAX) return LLONG_MAX;
    return a + b + c + d + e;
}

void calc() {
    sz[0] = f0.size();
    lps = lp.size();
    mps = mp.size();
    rps = rp.size();

    for(int i = 1; i < 100010; i++) {
        sz[i] = add(lp.size(), sz[i-1], mp.size(), sz[i-1], rp.size());
    }
}

char kth(int level, ll k) {
    while(1) {
        assert(k > 0);
        if(level == 0) {
            if(k <= f0.size()) return f0[k-1];
            else return '.';
        }

        if(k <= lps) return lp[k-1];
        k -= lps;

        if(k <= (ll) sz[level-1]) {
            level--;
            continue;
        }
        k -= sz[level-1];

        if(k <= mps) return mp[k-1];
        k -= mps;

        if(k <= (ll) sz[level-1]) {
            level--;
            continue;
        }
        k -= sz[level-1];

        if(k <= rps) return rp[k-1];
        k -= rps;

        return '.';
    }
}

int main() {
    calc();

    scanf("%d", &q);
    while(q--) {
        scanf("%lld %lld", &n, &k);
        printf("%c", kth(n, k));
    } puts("");
    return 0;
}