/* Written by Filip Hlasek 2017 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, b) for (int i = 0; i < (b); i++)

using namespace std;

int phi(int n) {
    int ans = 1;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            ans *= (p - 1);
            n /= p;
            while (n % p == 0) {
                ans *= p;
                n /= p;
            }
        }
    }
    if (n > 1)
        ans *= n - 1;
    return ans;
}

long long modulo(long long a, long long b) {
    if (a < b)
        return a;
    return a % b + b;
}

int powmod(int base, long long exponent, int mod) {
    int result = 1, m = base;
    while (exponent) {
        if (exponent & 1)
            result = modulo((long long)result * m, mod);
        m = modulo((long long)m * m, mod);
        exponent /= 2;
    }
    return result;
}

#define MAXN 111111
int P;
int Phi[111];
int A[MAXN];

int N, M, Q;

int main(int argc, char* argv[]) {
    scanf("%d%d", &N, &M);
    P = 1;
    Phi[0] = M;
    while (Phi[P - 1] != 1) {
        Phi[P] = phi(Phi[P - 1]);
        P++;
    }
    REP(i, N) scanf("%d", A + i);
    scanf("%d", &Q);
    while (Q--) {
        int L, R;
        scanf("%d%d", &L, &R);
        L--;
        R--;
        int ans = 1;
        FORD(i, min(R, L + P - 1), L) { ans = powmod(A[i], ans, Phi[i - L]); }
        printf("%d\n", ans % M);
    }
    return 0;
}