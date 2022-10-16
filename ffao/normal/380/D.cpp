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

#define INF (INT_MAX/3)

#define MAXN 100001

typedef long long lint;

using namespace std;

lint modpow(lint x, lint y, lint m) {
    if (y == 0) return 1;
    lint k = modpow(x, y/2, m); k = k * k % m;
    if (y%2) return k*x % m;
    return k;
}
lint invprime(lint a, lint p) {return modpow(a, p-2, p);}


int label[MAXN], nextlabel[MAXN], prevlabel[MAXN];
const lint mod = 1000000007;

lint fact[MAXN+2], invfact[MAXN+2];

lint binom(lint a, lint b)
{
    return fact[a] * invfact[b] % mod * invfact[a-b] % mod;
}

lint solve(int l, int r)
{
    const int size = r-l+1;

    if (size == 0) return 1;

    if (size == 1) {
        if (label[l] == 0 || label[l] == 1) return 1;
        return 0;
    }

    const int nl = nextlabel[l], nr = prevlabel[r];

    if (nl > nr) {
        return modpow(2, size-1, mod);}

    if (label[l] > size || label[r] > size) return 0;

    if (label[l] == size) return solve(l+1, r);
    if (label[r] == size) return solve(l, r-1);

    lint result = 0;

    if (label[nr] >= label[nl]) {
        int size2 = label[nr];
        int r2 = nr;
        int l2 = r2 - size2 + 1;
        if (l2 < l || l2 > nl) goto next;

        int dl = l2 - l, dr = r - r2;

        result = (result + binom(dl+dr, dl) * solve(l2, r2)) % mod;
    }

    next:
    if (label[nl] > label[nr] || (nl == nr && label[nl] > 1)) {
        int size2 = label[nl];
        int l2 = nl;
        int r2 = l2 + size2 - 1;
        if (r2 < nr || r2 > r) goto end;

        int dl = l2 - l, dr = r - r2;

        result = (result + binom(dl+dr, dl) * solve(l2, r2)) % mod;
    }

    end:
    return result;
}


int main(int argc, char ** argv)
{
    int n;

    scanf("%d", &n);

    fact[0] = 1;
    for (lint i = 1; i <= n+1; i++) fact[i] = i * fact[i-1] % mod;

    invfact[n+1] = invprime(fact[n+1], mod);
    for (lint i = n; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % mod;
    
    for (int i = 0; i < n; i++)
        scanf("%d", &label[i]);

    for (int i = 0, val = -1; i < n; i++) {
        if (label[i]) val = i;
        prevlabel[i] = val;
    }

    for (int i = n-1, val = n; i >= 0; i--) {
        if (label[i]) val = i;
        nextlabel[i] = val;
    }

    printf("%d\n", (int)solve(0, n-1));

    return 0;
}