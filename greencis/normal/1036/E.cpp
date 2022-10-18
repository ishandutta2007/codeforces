#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

inline bool between(ll x, ll z, ll y) { return (x <= z && z <= y) || (y <= z && z <= x); }

int n;
ll ax[1005], ay[1005], bx[1005], by[1005];
ll A[1005], B[1005], C[1005];
map<pii, set<int>> mp;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ax[i] >> ay[i] >> bx[i] >> by[i];
        if (ax[i] > bx[i] || (ax[i] == bx[i] && ay[i] > by[i])) {
            swap(ax[i], bx[i]);
            swap(ay[i], by[i]);
        }
        A[i] = ay[i] - by[i];
        B[i] = bx[i] - ax[i];
        C[i] = -A[i] * ax[i] - B[i] * ay[i];
        ll g = gcd(abs(A[i]), gcd(abs(B[i]), abs(C[i])));
        if (A[i] < 0 || (A[i] == 0 && B[i] < 0))
            g = -g;
        A[i] /= g;
        B[i] /= g;
        C[i] /= g;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i] * B[j] == A[j] * B[i]) {
                if (C[i] == C[j]) {
                    if ((between(ax[i], ax[j], bx[i]) && between(ay[i], ay[j], by[i])) ||
                        (between(ax[i], bx[j], bx[i]) && between(ay[i], by[j], by[i])) ||
                        (between(ax[j], ax[i], bx[j]) && between(ay[j], ay[i], by[j])) ||
                        (between(ax[j], bx[i], bx[j]) && between(ay[j], by[i], by[j]))) {

                        ll nax = min(min(ax[i], bx[i]), min(ax[j], bx[j]));
                        ll nbx = max(max(ax[i], bx[i]), max(ax[j], bx[j]));
                        ll nay = min(min(ay[i], by[i]), min(ay[j], by[j]));
                        ll nby = max(max(ay[i], by[i]), max(ay[j], by[j]));
                        if (ay[i] > by[i])
                            swap(nay, nby);
                        ax[i] = nax;
                        ay[i] = nay;
                        bx[i] = nbx;
                        by[i] = nby;
                        for (int z = j + 1; z < n; ++z) {
                            ax[z - 1] = ax[z];
                            ay[z - 1] = ay[z];
                            bx[z - 1] = bx[z];
                            by[z - 1] = by[z];
                            A[z - 1] = A[z];
                            B[z - 1] = B[z];
                            C[z - 1] = C[z];
                        }
                        --n;
                        --j;
                    }
                }
            }
        }
    }

    ll ans = n;
    for (int i = 0; i < n; ++i) {
        ans += gcd(abs(ax[i] - bx[i]), abs(ay[i] - by[i]));
        for (int j = i + 1; j < n; ++j) {
            ll det = A[i] * B[j] - A[j] * B[i];
            if (det == 0)
                continue;
            ll X = B[i] * C[j] - B[j] * C[i];
            ll Y = C[i] * A[j] - C[j] * A[i];
            if (X % det || Y % det)
                continue;
            X /= det;
            Y /= det;
            if (between(ax[i], X, bx[i]) && between(ay[i], Y, by[i]) &&
                between(ax[j], X, bx[j]) && between(ay[j], Y, by[j])) {

                auto& rf = mp[{X, Y}];
                rf.insert(i);
                rf.insert(j);
            }
        }
    }

    for (auto& p : mp)
        ans -= max(0, (int)p.second.size() - 1);
    cout << ans << endl;
}