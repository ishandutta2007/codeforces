#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f first
#define s second
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,x[200105];
ll sum[200105];

inline pll f(int idx, int len) {
    return make_pair(sum[idx] - sum[idx - 1 - len] + sum[n] - sum[n - len] - (ll)x[idx] * (len + len + 1),
                     len + len + 1);
}

inline pll f2(int idx, int len) {
    return make_pair(2 * (sum[idx + 1] - sum[idx - 1 - len] + sum[n] - sum[n - len]) - ll(x[idx] + x[idx + 1]) * (len + len + 2),
                     2 * (len + len + 2));
}

int comp(pll a, pll b) {
    ll A = a.f, B = a.s, C = b.f, D = b.s;
    if (A*D - B*C > 0 && B*D > 0 || A*D - B*C < 0 && B*D < 0) return 1;
    if (A*D - B*C < 0 && B*D > 0 || A*D - B*C > 0 && B*D < 0) return -1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i-1] + x[i];
    if (n <= 2) {
        cout << 1 << endl << x[1];
        return 0;
    }
    pll mx = make_pair(-9e12, 1);
    int mxidx, mxlen, two;
    for (int i = 1; i <= n; ++i) {
        int L = 1, R = min(n - i, i - 1);
        while (L < R) {
            if (L + 10 > R) {
                pll curmx = make_pair(-9e12, 1);
                int curmxi = -1;
                for (int j = L; j <= R; ++j) {
                    if (comp(f(i, j), curmx) > 0) curmx = f(i, j), curmxi = j;
                }
                L = R = curmxi;
                break;
            } else {
                int m1 = L + (R - L) / 3;
                int m2 = R - (R - L) / 3;
                if (comp(f(i, m1), f(i, m2)) > 0) R = m2;
                else L = m1;
            }
        }
        if (L > R) continue;
        if (comp(f(i, L), mx) > 0) mx = f(i, L), mxidx = i, mxlen = L, two = 0;
    }

    for (int i = 1; i + 1 <= n; ++i) {
        int L = 1, R = min(n - i - 1, i - 1);
        while (L < R) {
            if (L + 10 > R) {
                pll curmx = make_pair(-9e12, 1);
                int curmxi = -1;
                for (int j = L; j <= R; ++j) {
                    if (comp(f2(i, j), curmx) > 0) curmx = f2(i, j), curmxi = j;
                }
                L = R = curmxi;
                break;
            } else {
                int m1 = L + (R - L) / 3;
                int m2 = R - (R - L) / 3;
                if (comp(f2(i, m1), f2(i, m2)) > 0) R = m2;
                else L = m1;
            }
        }
        if (L > R) continue;
        if (comp(f2(i, L), mx) > 0) mx = f2(i, L), mxidx = i, mxlen = L, two = 1;
    }

    if (comp(mx, make_pair(0, 1)) <= 0) {
        cout << 1 << endl << x[1];
        return 0;
    }

    cout << mxlen + mxlen + 1 + two << "\n";
    for (int i = mxlen; i >= 1; --i)
        cout << x[mxidx - i] << " ";
    cout << x[mxidx] << " ";
    if (two) cout << x[mxidx + 1] << " ";
    for (int i = mxlen; i >= 1; --i)
        cout << x[n + 1 - i] << " ";

    return 0;
}