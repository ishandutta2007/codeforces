#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

unsigned n, A, B, C, D, ans;
int pr[2000], pri;
int u[20000];

inline unsigned count_occurences(unsigned n, unsigned divr) {
    unsigned ans = 0;
    do {
        n /= divr;
        ans += n;
    } while (n);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    const int sqn = 17321;
    for (int i = 2; i <= sqn; ++i) {
        int ok = 1;
        for (int j = 2; ok && j * j <= i; ++j)
            if (i % j == 0)
                ok = 0;
        if (ok)
            pr[pri++] = i;
    }

    cin >> n >> A >> B >> C >> D;
    for (int i = 0; i < pri; ++i)
        ans += count_occurences(n, (unsigned)pr[i]) * (((A * (unsigned)pr[i] + B) * (unsigned)pr[i] + C) * (unsigned)pr[i] + D);
    for (int bl = 1; bl * sqn + 1 <= (int)n; ++bl) {
        memset(u, 0, sizeof u);
        int L = bl * sqn + 1, R = (bl + 1) * sqn; /// [L; R]
        for (int i = 0; i < pri; ++i)
            for (int j = (L + pr[i] - 1) / pr[i] * pr[i]; j <= R; j += pr[i])
                u[j - L] = 1;
        for (int i = 0; i < sqn; ++i) {
            if (!u[i]) {
                unsigned cur = L + i;
                ans += count_occurences(n, cur) * (((A * cur + B) * cur + C) * cur + D);
            }
        }
    }
    cout << ans;
}