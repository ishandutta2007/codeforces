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

int h, m, n;
int cnt, each;
map<int, int> ma;
vector<int> fen[200000];
char s[5];
int rev[200000];

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

inline void fenInc(int *fen, int pos) {
    for (; pos < each; pos |= pos + 1)
        ++fen[pos];
}

inline void fenDec(int *fen, int pos) {
    for (; pos < each; pos |= pos + 1)
        --fen[pos];
}

inline int fenGet(int *fen, int pos) {
    int ret = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        ret += fen[pos];
    return ret;
}

int main() {
    scanf("%d%d%d", &h, &m, &n);
    cnt = gcd(h, m);
    each = h / cnt;
    REP(i, cnt) fen[i].resize(each);
    for (int i = 0, ind = 0; i < each; ++i, ind = (ind + m / cnt) % each) {
        rev[ind] = i;
    }
    LL ans = 0;
    REP(query, n) {
        scanf("%s", s);
        if (s[0] == '+') {
            int id, ha;
            scanf("%d%d", &id, &ha);
            int pos = ha % cnt, ind = rev[ha / cnt];
            int *f = fen[pos].data();
            int fenTot = fenGet(f, each - 1);
            if (fenTot - fenGet(f, ind - 1) == each - ind) {
                int lo = 0, hi = ind - 1, mid;
                while (lo < hi) {
                    mid = (lo + hi) >> 1;
                    if (fenGet(f, mid) == mid + 1) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    }
                }
                ans += each - ind + lo;
                ind = lo;
            } else {
                int lo = ind, hi = each - 1, mid;
                fenTot = fenGet(f, ind - 1);
                while (lo < hi) {
                    mid = (lo + hi) >> 1;
                    if (fenGet(f, mid) - fenTot == mid - ind + 1) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    }
                }
                ans += lo - ind;
                ind = lo;
            }
            fenInc(f, ind);
            ha = ind * cnt + pos;
            ma[id] = ha;
        } else {
            int id;
            scanf("%d", &id);
            int ha = ma[id];
            int pos = ha % cnt, ind = ha / cnt;
            fenDec(fen[pos].data(), ind);
        }
    }
    cout << ans << endl;
    return 0;
}