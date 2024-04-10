#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define all(s) (s).begin(), (s).end()

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

const int N = 2e5 + 200;

ll A;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf(LLD, &A);

    vector<ll> del, primes;

    for (ll i = 1; i * i <= A; i ++) {
        if (A % i == 0) {
            del.pb(i);
            del.pb(A / i);
        }
    }
    sort(all(del));
    del.resize(distance(del.begin(), unique(all(del))));

//    for (auto i : del) {
//        cout << i << endl;
//    }

    for (auto i : del) {
        i--;
        if (i > 1) {
            ll prime = 2;
            while (i % prime != 0 && prime * prime <= i) {
                prime++;
            }
            if (i % prime) {
                prime = i;
            }
            while (i % prime == 0) {
                i /= prime;
            }
            if (i == 1) {
                primes.pb(prime);
            }
        }
    }
    sort(all(primes));
    primes.resize(distance(primes.begin(), unique(all(primes))));

//    cout << del.size() << endl;
//    cout << primes.size() << endl;
//    for (auto i : del) {
//        m1[i] = 0;
//    }
    vector<ll> dp1 (del.size()), dp2;
    dp1[0] = 1;
    for (auto p : primes) {
        dp2 = dp1;
        for (ll k = p; k < A; k *= p) {
            int j = 0;
            for (int i = 0; i < (int) del.size(); i++) {
                if (del[i] % (k + 1) == 0) {
                    while (del[j] < (del[i] / (k + 1))) {
                        j++;
                    }
                    dp2[i] += dp1[j];
                }
            }
        }
        swap(dp1, dp2);
    }

    printf(LLD, dp1.back());

    return 0;
}