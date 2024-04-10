#include <bits/stdc++.h>

using namespace std;

#define MN 100010

int n, isp[MN], fac[MN];
vector<int> primes;

void crivo() {
    fill(isp, isp + MN, 1);
    for(int i = 2; i < MN; i++) {
        if(isp[i] == 1) {
            primes.push_back(i);
            for(int j = i + i; j < MN; j += i)
                isp[j] = i;
        }
    }
}

int ans[2*MN];
vector<int> av[MN];

int main() {
    crivo();
    scanf("%d", &n);

    for(int p : primes) {
        for(int i = p; i <= n; i += p) {
            if(ans[i]) continue;
            if(av[p].empty()) av[p].push_back(i);
            else {
                int x = av[p].back();
                av[p].pop_back();
                if(p > 2 && (x % 2 == 0 || i % 2 == 0)) {
                    assert(!av[2].empty());
                    assert(av[2].back() == x || av[2].back() == i);
                    av[2].pop_back();
                }
                ans[x] = i;
                ans[i] = x;
            }
        }

        if(p > 2 && !av[p].empty() && ans[2*p]) {
            int ot = ans[2*p], x = av[p].back();
            av[p].pop_back();
            if(x % 2 == 0) {
                assert(!av[2].empty() && av[2].back() == x);
                av[2].pop_back();
            }
            ans[ot] = 0;
            ans[2*p] = x;
            ans[x] = 2*p;

            if(av[2].empty()) av[2].push_back(ot);
            else {
                int y = av[2].back();
                av[2].pop_back();
                ans[ot] = y;
                ans[y] = ot;
            }
        }
    }

    int pairs = 0;
    for(int i = 1; i <= n; i++) {
        if(ans[i]) pairs++;
    }

    assert(pairs % 2 == 0);
    printf("%d\n", pairs / 2);
    for(int i = 1; i <= n; i++) {
        if(ans[i] > i)
            printf("%d %d\n", i, ans[i]);
    }
    return 0;
}