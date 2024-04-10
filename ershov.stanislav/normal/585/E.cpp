#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 5e5 + 100;
const int M = 1e7 + 100;
const int MOD = 1e9 + 7;
int cnt[M], mob[M], a[N];
int primes[M / 5], cntprimes = 1, minPrime[M], powers2[M];
int curPrimes[50], len;
int n;

void gen(int pos, int cur, int curMob) {
    if (pos == len) {
        cnt[cur]++;
        mob[cur] = curMob;
    } else {
        gen(pos + 1, cur, curMob);
        gen(pos + 1, cur * curPrimes[pos], curMob * -1);
    }
}

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    powers2[0] = 1;
    for (int i = 1; i < M; i++) {
        powers2[i] = powers2[i - 1] * 2 % MOD;
    }
    for (int i = 2; i < M; i++) {
        if (!minPrime[i]) {
            minPrime[i] = cntprimes;
            primes[cntprimes++] = i;
        }
        for (int j = 1; j <= minPrime[i] && primes[j] * i < M; j++) {
            minPrime[primes[j] * i] = j;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
        len = 0;
        while (int mn = minPrime[a[i]]) {
            mn = primes[mn];
            curPrimes[len++] = mn;
            while (a[i] % mn == 0) {
                a[i] /= mn;
            }
        }
        gen(0, 1, 1);
    }
    int ans = 0;
    for (int i = 1; i < M; i++) {
        if (mob[i]) {
            int add = (cnt[i] * 1ll * powers2[cnt[i]] - (powers2[cnt[i]] - 1) * 1ll * n) % MOD;
            add *= mob[i];
            if (add < 0) {
                add += MOD;
            }
            ans += add;
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}