#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 300030
int n, a[MN], isp[MN], simple[MN];
vector<int> primes, fact[MN];

void crivo() {
    for(int i = 2; i < MN; i++) isp[i] = 1;
    for(int i = 2; i < MN; i++) {
        if(isp[i]) {
            primes.push_back(i);
            for(int j = i + i; j < MN; j += i)
                isp[j] = 0;
        }
    }
}

vector<int> norm(int &x) {
    vector<int> ret;
    for(int i = 0; i < primes.size(); i++) {
        int pi = primes[i];
        if(pi * pi > x) break;
        if(x % pi == 0) {
            ret.push_back(pi);
            while(x % pi == 0) x /= pi;
        }
    }
    if(x > 1) {ret.push_back(x), x = 1;}
    for(int z : ret) x *= z;
    return ret;
}

int freq[MN], dp[MN][8], gg;

void tryp(int x, int pos, int val) {
    if(pos == fact[x].size()) freq[val]++;
    else {
        tryp(x, pos + 1, val);
        tryp(x, pos + 1, val / fact[x][pos]);
    }
}

int solve3(int x, int init, int pos, int val) {
    if(pos == fact[x].size()) return freq[val];
    if(init % fact[x][pos] == 0) return solve3(x, init, pos + 1, val);
    return solve3(x, init, pos + 1, val)
            - solve3(x, init, pos + 1, val * fact[x][pos]);
}

void solve2(int x, int p, int init) {
    int sum = solve3(x, init, 0, init);
    assert(sum >= 0);
    if(sum) {
        dp[init][p] = 1;
    }
}

void solve(int i, int p, int pos, int val) {
    if(pos == fact[i].size()) solve2(i, p, val);
    else {
        solve(i, p, pos + 1, val);
        solve(i, p, pos + 1, val / fact[i][pos]);
    }
}

int main() {
    crivo();
    scanf("%d", &n);

    for(int i = 1; i <= 300000; i++) {
        int j = i;
        fact[i] = norm(j);
        simple[i] = j;
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if(gg == 0) gg = a[i];
        else gg = __gcd(gg, a[i]);

        a[i] = simple[a[i]];
        dp[a[i]][1] = 1;
        tryp(a[i], 0, a[i]);
    }

    if(gg > 1) {
        printf("-1\n");
        return 0;
    }

    if(dp[1][1]) {
        printf("1\n");
        return 0;
    }

    for(int p = 1; p < 6; p++) {
        for(int i = 1; i <= 300000; i++)
            if(dp[i][p])
                solve(i, p+1, 0, i);

        if(dp[1][p+1]) {
            printf("%d\n", p+1);
            return 0;
        }
    }

    printf("7\n");
    return 0;
}