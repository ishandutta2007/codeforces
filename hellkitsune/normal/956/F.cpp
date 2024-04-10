#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int DEBUG = 0;
mt19937 mt(123);

unordered_map<bitset<87>, int > ma[19];
LL table[400000][10];
int tcnt = 0;

inline bitset<87> tra(bitset<87> b, int dig) {
    bitset<87> res = (b << dig) | (b >> dig);
    forn(i, dig) if (b.test(i)) {
        res.set(dig - i);
    }
    return res;
}

int n;
LL from, to;
int k;
vector<LL> ans;

int solve(bitset<87> b, int rem) {
    auto it = ma[rem].find(b);
    if (it != ma[rem].end()) {
        return it->second;
    }
    int ind = tcnt++;
    if (rem == 0) {
        int cur = 0;
        forn(i, 10) {
            cur |= b.test(i);
            table[ind][i] = cur;
        }
    } else {
        forn(i, 10) {
            int cur = solve(tra(b, i), rem - 1);
            forn(j, 10) {
                table[ind][j] += table[cur][j];
            }
        }
    }
    return ma[rem][b] = ind;
}

LL solve(LL bound, int k) {
    if (bound == 0) {
        return 1;
    }
    vector<int> dig;
    while (bound > 0) {
        dig.pb(bound % 10);
        bound /= 10;
    }
    reverse(dig.begin(), dig.end());
    int sz = dig.size();
    bitset<87> b;
    b.reset();
    b.set(0);
    LL ans = 0;
    forn(i, sz) {
        forn(j, dig[i] + (i == sz - 1)) {
            ans += table[solve(tra(b, j), sz - 1 - i)][k];
        }
        b = tra(b, dig[i]);
    }
    return ans;
}

LL gen(LL bound) {
    int times = mt() % 60 + 1;
    LL res = bound;
    forn(i, times) {
        res = mt() % bound + 1;
    }
    return res;
}

int main() {
    if (DEBUG) {
        n = 50000;
    } else {
        scanf("%d", &n);
    }
    forn(i, n) {
        if (DEBUG) {
            from = gen(LL(1e18));
            to = gen(LL(1e18));
            if (from > to) {
                swap(from, to);
            }
            k = mt() % 10;
        } else {
            scanf("%I64d%I64d%d", &from, &to, &k);
        }
        ans.pb(solve(to, k) - solve(from - 1, k));
    }
    for (LL x : ans) printf("%I64d\n", x);
    return 0;
}