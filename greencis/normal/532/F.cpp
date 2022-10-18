#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m;
char s[200105], t[200105];

ll BASE1 = 37ll, MOD1 = 1000000007ll, p1[200105];
ll BASE2 = 53ll, MOD2 = 1000000009ll, p2[200105];

ll bithash[266][2];
ll sb[266][2];
int u[266];
int cntletters[266];
char match[266];
int ans[300105], ansi;

void calc_hash() {
    p1[0] = p2[0] = 1ll;
    for (int i = 1; i < 200105; ++i) {
        p1[i] = (p1[i-1] * BASE1) % MOD1;
        p2[i] = (p2[i-1] * BASE2) % MOD2;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 26; ++j) {
            (bithash[j][0] *= BASE1) %= MOD1;
            (bithash[j][1] *= BASE2) %= MOD2;
        }
        (bithash[t[i] - 'a'][0] += 1) %= MOD1;
        (bithash[t[i] - 'a'][1] += 1) %= MOD2;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 26; ++j) {
            (sb[j][0] *= BASE1) %= MOD1;
            (sb[j][1] *= BASE2) %= MOD2;
        }
        (sb[s[i] - 'a'][0] += 1) %= MOD1;
        (sb[s[i] - 'a'][1] += 1) %= MOD2;
    }
}

int main()
{
    scanf("%d%d%s%s",&n,&m,s,t);

    calc_hash();

    for (int i = 0; i < m; ++i) {
        u[t[i] - 'a'] = 1;
        ++cntletters[s[i] - 'a'];
    }

    int qqq = 0;
    for (int i = 0; i < 26; ++i) qqq += !!u[i];

    for (int i = 0; i <= n - m; ++i) {
        for (int j = 0; j < 26; ++j) match[j] = 0;
        bool good = true;

        int matches = 0;

        for (int j = 0; j < 26 && good; ++j) {
            if (!u[j]) continue;
            for (int k = 0; k < 26; ++k) {
                if (cntletters[k] == 0) continue;
                if (bithash[j][0] == sb[k][0] && bithash[j][1] == sb[k][1]) {
                    if (match[j]) { if (match[j] != k + 'a') { good = false; break; } }
                    if (match[k]) { if (match[k] != j + 'a') { good = false; break; } }
                    match[j] = k + 'a';
                    match[k] = j + 'a';
                    ++matches;
                }
            }
        }

        if (good && matches == qqq) ans[ansi++] = i;

        if (i == n - m) break;

        --cntletters[s[i] - 'a'];
        ++cntletters[s[i + m] - 'a'];
        for (int j = 0; j < 26; ++j) {
            (sb[j][0] *= BASE1) %= MOD1;
            (sb[j][1] *= BASE2) %= MOD2;
        }

        (sb[s[i] - 'a'][0] += MOD1 + MOD1 - p1[m]) %= MOD1;
        (sb[s[i] - 'a'][1] += MOD2 + MOD2 - p2[m]) %= MOD2;
        (sb[s[i+m] - 'a'][0] += 1) %= MOD1;
        (sb[s[i+m] - 'a'][1] += 1) %= MOD2;
    }

    printf("%d\n",ansi);
    for (int i = 0; i < ansi; ++i)
        printf("%d ", ans[i] + 1);

    return 0;
}