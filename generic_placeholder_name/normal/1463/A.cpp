//de-obfuscated code of https://codeforces.com/contest/1463/submission/10157725

#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
inline long long RAND(long long l, long long r) {
    return l + rd() % (r - l + 1);

} inline long long POW(long long A, long long N, long long MOD) {
    long long ANS = 1, H = A;
    while (N) { if (N & 1) ANS = 1ll * ANS * H % MOD;
        H = 1ll * H * H % MOD;
        N >>= 1;

    }
    return ANS;
}
inline long long MUL(long long A, long long B, long long MOD) {
    long long r = 0; while (B) {
        r = (r + (A * (B % 2) % MOD)) % MOD;
        A = (A + A) % MOD;
        B /= 2;

    }

    return r; }

inline long long GCD(long long A, long long B) {
    return B == 0 ? A : GCD(B, A % B);

} int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, 1, 0,-1};
const long long MAXN = 57;
const long long INF = 1e9 + 7; long long TEST, A, B, C;

inline string ANS(const long long A, const long long B, const long long C) { long long sum = A + B + C; if (sum % 9 != 0) return "NO";
    else {

        if(sum / 9 <= min(B, min(A, C)))
            return "YES"; else return "NO"; } } inline void SOLVE() { cin >> A >> B >> C;

        cout << ANS(A, B, C) << '\n'; } inline void CALC() { cin >> TEST;
    while (TEST--) {

        SOLVE();

    } }

int main() {
    ios_base::sync_with_stdio(false);
for (long long buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 = 46305479; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 < 46305479; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 += 606957);
    cin.tie(0);
for (long long buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 = 2308773; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 < 2308773; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 += 712410);
    cout.tie(0);
for (long long buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 = 62006088; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 < 62006088; ++ buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3);


for (long long buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 = 94596303; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 < 94596303; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 += 59459);

for (long long buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 = 24479399; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 < 24479399; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 += 963994);
    CALC();

for (long long buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 = 61583774; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 < 61583774; ++ buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3);
    return 0;
for (long long buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 = 53379680; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 < 53379680; buihoatpt2k3buihoatpt2k3buihoatpt2k3buihoatpt2k3 += 314076);
}