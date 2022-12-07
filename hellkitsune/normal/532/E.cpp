#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

struct mySet {
    static const int bcnt = 100019;
    vector<LL> b[bcnt];
    int sz = 0;

    void insert(LL x) {
        int mo = x % bcnt;
        for (LL val : b[mo]) if (val == x) return;
        b[mo].pb(x);
        ++sz;
    }

    int count(LL x) {
        int mo = x % bcnt;
        for (LL val : b[mo]) if (val == x) return 1;
        return 0;
    }

    int size() {
        return sz;
    }
};

int n;
string s[2];
LL h[100001];
LL mu[100001];
mySet se;
mySet ans;

const LL MOD = 1e16 + 61, MUL = 37;

LL mult(LL a, LL b) {
    LL ans = 0;
    while (b) {
        ans += (b & 63) * a;
        b >>= 6;
        a = (a << 6) % MOD;
    }
    return ans % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, 2) cin >> s[i];
    mu[0] = 1;
    REP(i, n) mu[i + 1] = (mu[i] * MUL) % MOD;
    REP(z, 2) {
        h[n] = 0;
        for (int i = n - 1; i >= 0; --i)
            h[i] = (h[i + 1] * MUL + s[z][i] - 'a' + 3) % MOD;
        LL hh = h[0];
        for (int i = n; i >= 0; --i) {
            if (i != n) {
                hh = 0;
                if (i > 0) hh = h[0] - mult(h[i], mu[i]);
                if (hh < 0) hh += MOD;
                hh = (hh + mult(h[i], mu[i + 1])) % MOD;
            }
            if (z == 0) {
                for (int j = 3; j < 29; ++j)
                    se.insert((hh + j * mu[i]) % MOD);
            } else {
                for (int j = 3; j < 29; ++j) {
                    LL tmp = (hh + j * mu[i]) % MOD;
                    if (se.count(tmp)) {
                        ans.insert(tmp);
                    }
                }
            }
        }
    }
    cout << (int)ans.size() << endl;
    return 0;
}