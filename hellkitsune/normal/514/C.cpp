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

char s[1000000];
int n, m, len;
const LL MOD = 1e15 + 37;
const LL MUL = 1009;
LL h[666666];

unordered_set<LL> se;

LL getHash(char *s) {
    LL ha = 0;
    REP(i, len) ha = (ha + h[i] * int(s[i])) % MOD;
    return ha;
}

int main() {
    h[0] = 1;
    for (int i = 1; i < 666666; ++i) {
        h[i] = (h[i - 1] * MUL) % MOD;
    }
    scanf("%d%d", &n, &m);
    REP(i, n) {
        scanf("%s", s);
        len = strlen(s);
        LL ha = getHash(s);
        se.insert(ha);
    }
    REP(i, m) {
        scanf("%s", s);
        len = strlen(s);
        LL ha = getHash(s);
        bool flag = false;
        REP(i, len) {
            for (char c = 'a'; c <= 'c'; ++c) if (c != s[i]) {
                LL nha = ha + h[i] * (c - s[i]);
                while (nha < 0) nha += MOD;
                while (nha >= MOD) nha -= MOD;
                if (se.count(nha)) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}