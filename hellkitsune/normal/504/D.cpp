#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
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
typedef unsigned uns;
typedef unsigned long long ULL;

uns a[2000][65];
int alen[2000], hi[2000];
char s[605];
int m;
uns t[605], nt[605];
vector<uns> tmp;
uns mul[10];
bool used[2000];
uns ma[2000][65] = {};
const uns ONE = 1;
int ord[2000], ordc;
const ULL HI = (ULL)1 << (ULL)32;

bool cmp(const int &lhs, const int &rhs) {
    return hi[lhs] > hi[rhs];
}

int main() {
    mul[0] = 1;
    for (int i = 1; i < 10; ++i) {
        mul[i] = mul[i - 1] * 10;
    }
    scanf("%d", &m);
    REP(i, m) {
        scanf("%s", s);
        int len = strlen(s);
        for (int j = len - 1, k = 0; j >= 0; --j, ++k) {
            if (k == 9) k = 0;
            if (k == 0) tmp.pb(0);
            tmp.back() += mul[k] * (s[j] - '0');
        }
        reverse(tmp.begin(), tmp.end());
        len = (int)tmp.size();
        int ind = 0;
        REP(j, len) t[j] = tmp[j];
        while (len) {
            tmp.clear();
            int pos = 0;
            ULL num = 0;
            while (pos < len && num < HI) {
                num = mul[9] * num + t[pos];
                ++pos;
            }
            if (num < HI) {
                a[i][ind++] = num;
                break;
            }
            int newLen = 1;
            nt[0] = num >> 32;
            num &= (HI - 1);
            for (; pos < len; ++pos) {
                num = mul[9] * num + t[pos];
                nt[newLen++] = num >> 32;
                num &= (HI - 1);
            }
            len = newLen;
            REP(j, len) t[j] = nt[j];
            a[i][ind++] = num;
        }
        alen[i] = ind;
    }
    REP(i, m) {
        ma[i][i >> 5] ^= ONE << (i & 31);
        for (uns j = 0; j < 32; ++j) if (a[i][alen[i] - 1] & (ONE << j))
            hi[i] = j;
        hi[i] += (alen[i] - 1) * 32;
        ordc = 0;
        REP(j, i) if (used[j]) {
            ord[ordc++] = j;
        }
        sort(ord, ord + ordc, cmp);
        used[i] = true;
        REP(j, ordc) {
            int pos = ord[j];
            if (hi[pos] == hi[i]) {
                REP(q, 65) a[i][q] ^= a[pos][q];
                REP(q, 65) ma[i][q] ^= ma[pos][q];
            } else if (hi[pos] < hi[i]) {
                break;
            }
            while (hi[i] >= 0 && !(a[i][hi[i] >> 5] & (ONE << (hi[i] & 31)))) {
                --hi[i];
            }
            if (hi[i] < 0) {
                used[i] = false;
                break;
            }
        }
        if (used[i]) {
            printf("0\n");
        } else {
            ma[i][i >> 5] ^= ONE << (i & 31);
            int cnt = 0;
            REP(q, 65) cnt += __builtin_popcount(ma[i][q]);
            printf("%d", cnt);
            REP(q, 2000) if (ma[i][q >> 5] & (ONE << (q & 31)))
                printf(" %d", q);
            printf("\n");
        }
    }
    return 0;
}