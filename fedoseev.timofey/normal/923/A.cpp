#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
typedef unsigned long long ull;

template <typename T1, typename T2> inline void chkmin(T1 &x, T2 y) { if (y < x) x = y; };
template <typename T1, typename T2> inline void chkmax(T1 &x, T2 y) { if (y > x) x = y; };

const int INF = 2e9;
const int N = 1000000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    
    vector <int> primes;
    vector <ll> minp(N + 1, INF);
    for (ll i = 2; i <= N; ++i) {
        if (minp[i] == INF) {
            primes.pb(i);
            for (ll j = i * i; j <= N; j += i) {
                chkmin(minp[j], i);
            }
        }
    }

    ll x2;
    cin >> x2;
    ll x22 = x2;
    set <ll> fact;
    while (x2 > 1) {
        if (minp[x2] == INF) {
            fact.insert(x2);
            break;
        }
        fact.insert(minp[x2]);
        x2 = x2 / minp[x2];
    }
    x2 = x22;

    set <ll> x1s;
    for (ll p2 : fact) {
        for (ll x1 = p2 + 1; x1 <= x2; ++x1) {
            if (p2 * (x1 / p2 + (x1 % p2 != 0)) != x2) continue;
            x1s.insert(x1);
//            cout << x1 << endl;
        }
    }
    
    ll ans = INF;
    for (ll x1 : x1s) {
        ll x11 = x1;
        set <ll> fact1;
        while (x11 > 1) {
            if (minp[x11] == INF) {
                fact1.insert(x11);
                break;
            }
            fact1.insert(minp[x11]);
            x11 = x11 / minp[x11];
        }
        for (ll p1 : fact1) {
            ll ub = x1, lb = p1;
            while (ub - lb > 1) {
                ll mid = (lb + ub) / 2;
                if (p1 * (mid / p1 + (mid % p1 != 0)) == x1)
                    ub = mid;
                else
                    lb = mid;
            }
            chkmin(ans, ub);
        }
    }
    cout << ans << endl;

    return 0;
}