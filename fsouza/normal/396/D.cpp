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
#define MAXN 1000000

typedef long long lint;

using namespace std;

const lint mod = 1000000007;
const lint inv2 = (mod+1)/2;

int n;
int p[MAXN];

lint bit[MAXN+1];
lint get(int x) {
        x++;

        lint ret = 0;
        while (x > 0) {
                ret = (ret + bit[x]) % mod;
                x -= x&-x;
        }

        return (ret%mod + mod)%mod;
}

void update(int x, lint d) {
        x++;

        while (x <= n) {
                bit[x] = (bit[x] + d + mod)%mod;
                x += x&-x;
        }
}

lint choose2[MAXN+1], fact[MAXN+1];

int main(int argc, char ** argv)
{
        lint result = 0;

        scanf("%d", &n);

        choose2[0] = choose2[1] = 0;
        for (lint x = 2; x <= n; x++)
                choose2[x] = x * (x-1) % mod * inv2 % mod;

        fact[0] = 1;
        for (lint x = 1; x <= n; x++)
                fact[x] = x * fact[x-1] % mod;

        for (int i = 0; i < n; i++) {scanf("%d", &p[i]); p[i]--;}

        lint invnow = 0;

        for (int i = 0; i < n; i++) {
                int nbef = i, naft = n-1-nbef;
                int nless = p[i], nmore = n-1-nless
;
                int nlessbef = get(p[i]), nmorebef = nbef - nlessbef;
                int nmoreaft = nmore - nmorebef, nlessaft = naft - nmoreaft;

                int ncanuse = nlessaft;
                int remainsize = n-i;

                result = (result + invnow * (lint)ncanuse % mod * fact[remainsize-1] % mod) % mod;
                result = (result + (lint)ncanuse * choose2[remainsize-1] % mod * fact[remainsize-1] % mod * inv2 % mod) % mod;

                if (ncanuse > 0)
                        result = (result + (lint)ncanuse * (lint)(ncanuse-1) % mod * inv2 % mod * fact[remainsize-1] % mod) % mod;

                invnow = (invnow + (lint)nlessaft) % mod;
                update(p[i], 1);
        }

        result = (result + invnow) % mod;

        result = (result%mod + mod)%mod;
        printf("%d\n", (int)result);

        return 0;
}