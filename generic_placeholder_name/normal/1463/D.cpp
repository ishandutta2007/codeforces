//de-obfuscated code of https://codeforces.com/contest/1463/submission/101564867

#include <bits/stdc++.h>
using namespace std;
inline long long POW(long long A, long long N, long long MOD) {

    long long ANS = 1, H = A;

    while (N) { if (N & 1) ANS = 1ll * ANS * H % MOD; H = 1ll * H * H % MOD;
        N >>= 1;

    }

    return ANS; }
inline long long MUL(long long A, long long B, long long MOD) {

    long long r = 0;

    while (B) { r = (r + (A * (B % 2) % MOD)) % MOD; A = (A + A) % MOD; B /= 2; } return r;

}
inline long long GCD(long long A, long long B) {

    return B == 0 ? A : GCD(B, A % B); } int dx[] = {0, -1, 0, 1, 0};

int dy[] = {0, 0, 1, 0,-1};
const int MAXN = 200005;
int buihoatpt2k3A[MAXN],buihoatpt2k3B[MAXN];
bool buihoatpt2k3CHECK[2 * MAXN]; int TEST;

int N; inline void INIT() {

    cin >> N;

    for (int i = (1), _b = (2 * N); i <= _b; ++i) buihoatpt2k3CHECK[i] = 0; for (int i = (1), _b = (N); i <= _b; ++i) {
        cin >> buihoatpt2k3A[i]; buihoatpt2k3CHECK[buihoatpt2k3A[i]] = 1;

    } } inline void CALC() {

    int DEM = 0;

    for (int i = 2 * N; i > 0; --i)
        if (!buihoatpt2k3CHECK[i])
            buihoatpt2k3B[++DEM]=i;

}
inline void SOLVE() {

    int L, R, l, r, mid;

    L = 0; R = N + 1; l = 1;

    r = N; while (l<=r) { mid = (l + r) / 2;
        bool KIEMTRA = 1; for (int i = (1), _b = (mid); i <= _b; ++i)
        if (buihoatpt2k3A[i] > buihoatpt2k3B[mid - i + 1]) KIEMTRA = 0; if (KIEMTRA) {
            L = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    l = 1;
    r = N;
    while (l <= r) {
        mid = (l + r) / 2;

        bool KIEMTRA = 1; for (int i = (mid), _b = (N); i <= _b; ++i)
        if (buihoatpt2k3A[i] < buihoatpt2k3B[N - (i - mid)])

            KIEMTRA = 0;
        if (KIEMTRA) {
            R = mid;
            r = mid - 1;

        } else l = mid + 1; }
    cout << max(0ll, L - R + 2ll)<<'\n'; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);;
for (int buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 = 64923459; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 < 64923459; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 += 135583);
    cin >> TEST;
for (int buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 = 70376313; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 < 70376313; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 += 750718);
    while (TEST--) {
for (int buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 = 6619530; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 < 6619530; ++ buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3);
        INIT(); CALC();
        SOLVE();

    }

    return 0;
}