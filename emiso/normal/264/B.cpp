#include <bits/stdc++.h>
#define MN 100100
#define SQ 330

using namespace std;

vector<int> multiplos[MN], primes, ent;
vector<bool> isp(MN, 1);
int n, A, dp[MN];

void crivo() {
    isp[0] = isp[1] = 0;
    for(int i = 2; i < MN; i++)
        if(isp[i]) {
            primes.push_back(i);
            for(int j = 2 * i; j < MN; j += i)
                isp[j] = 0;
        }
}

int solve(int v) {
    if(dp[v] != -1) return dp[v];
    int x = 1, a = v;

    for(int p : primes) {
        if(p > a) break;
        if(a % p == 0) {
            int pos = upper_bound(multiplos[p].begin(), multiplos[p].end(), v)-multiplos[p].begin();
            if(pos < multiplos[p].size()) x = max(x, 1 + solve(multiplos[p][pos]));
            while(a % p == 0) a /= p;
        }
    }

    return dp[v] = x;
}

int main() {
    crivo();
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &A);
        int a = A;
        ent.push_back(A);

        for(int p : primes) {
            if(p > a) break;
            if(a % p == 0) {
                multiplos[p].push_back(A);
                while(a % p == 0) a /= p;
            }
        }
    }

    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int x : ent) ans = max(ans, solve(x));
    printf("%d\n", ans);
    return 0;
}