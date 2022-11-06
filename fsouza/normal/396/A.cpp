#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

lint mod = 1000000007;
const int maxx = 40500;
lint fact[maxx+1], invfact[maxx+1];

lint binom(int a, int b)
{
        return fact[a] * invfact[b] % mod * invfact[a-b] % mod;
}

lint modpow(lint x, lint y, lint mod)
{
        if (y == 0) return 1;
        lint k = modpow(x, y/2, mod); k = k*k%mod;
        if (y%2) k = k*x % mod;
        return k;
}

int main(int argc, char ** argv)
{
        fact[0] = 1;
        for (lint i = 1; i <= maxx; i++) fact[i] = i * fact[i-1] % mod;

        invfact[maxx] = modpow(fact[maxx], mod-2, mod);
        for (lint i = maxx-1; i >= 0; i--) invfact[i] = (i+1) * invfact[i+1] % mod;

        int n;

        scanf("%d", &n);

        map <int, int> nfact;

        for (int i = 0; i < n; i++) {
                int v;
                scanf("%d", &v);

                for (int x = 2; x*x <= v; x++)
                        if (v%x == 0) {
                                while (v%x == 0) {
                                        nfact[x] ++;
                                        v /= x;
                                }
                        }

                if (v > 1) nfact[v] ++;
        }

        lint result = 1;

        map <int, int>::iterator it;

        for (it = nfact.begin(); it != nfact.end(); it++) {
                int many = it -> second;
                result = (result * binom(n-1 + many, n-1)) % mod;
        }

        printf("%d\n", (int)result);

        return 0;
}