#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <string>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define sorv(V) sort(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define INF (1100000099)
#define INFLL (1100000000000000099ll)
#define MOD (1000000007)
#define MAXN (220005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

ll Fac[MAXN], ReN[MAXN], ReFac[MAXN];
ll D[MAXN], Shit[MAXN];
int A[MAXN];
int N;
ll Ans;

inline ll C(const int& n, const int& r) { return Fac[n] * ReFac[r] % MOD * ReFac[n-r] % MOD; }
int main() {
    Fac[0] = 1; for(int i = 1; i < MAXN; i++) Fac[i] = Fac[i-1] * i % MOD;
    ReN[1] = 1; for(int i = 2; i < MAXN; i++) ReN[i] = (ReN[MOD%i] * (MOD/i) % MOD * (-1) + MOD) % MOD;
    ReFac[0] = 1; for(int i = 1; i < MAXN; i++) ReFac[i] = ReFac[i-1] * ReN[i] % MOD;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    if(0 == N%4) {
        for(int i = 0; i < N; i++) {
            if(i&1) D[i] = -C(N/2-1, i/2);
            else D[i] = C(N/2-1, i/2);
        }
    } else if(2 == N%4) {
        for(int i = 0; i < N; i++) D[i] = C(N/2-1, i/2);
    } else if(1 == N%4) {
        for(int i = 0; i < N; i += 2) D[i] = C(N/2, i/2);
    } else {
        N -= 2;
        for(int i = 0; i < N; i += 2) Shit[i] = C(N/2, i/2);
        N += 2; D[0] = 1;
        for(int i = 1; i <= (N/2); i += 2) D[i] = Shit[i-1]*2 % MOD;
        for(int i = 2; i <= (N/2); i += 2) D[i] = (D[i+1] - D[i-1] + MOD) % MOD * ReN[2] % MOD;
        for(int i = N/2+1; i < N; i++) {
            if(i&1) D[i] = D[N-i-1];
            else D[i] = -D[N-i-1];
        }
    }
    for(int i = 0; i < N; i++) {
        Ans = ((Ans + (((ll)A[i] * D[i] % MOD + MOD) % MOD)) % MOD + MOD) % MOD;
    }
    printf("%lld\n", Ans);
    return 0;
}