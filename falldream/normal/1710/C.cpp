#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define MN 200000
#define mod 998244353
using namespace std;
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='1') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int n, f[2][8 * 27];
char s[MN + 5];

int ravel(int a, int b, int c, int d, int e, int f) {
    return (d * 9 + e * 3 + f) * 8 + (a * 4 + b * 2 + c);
}

void unravel(int s, int &a, int &b, int &c, int &d, int &e, int &f) {
    c = (s & 1);
    b = (s >> 1) & 1;
    a = (s >> 2) & 1;
    int t = s >> 3;
    f = t % 3;
    e = (t / 3) % 3;
    d = (t / 9) % 3;
}

inline int trans(int p, int a, int b, int c) {
    if (p == 0) {
        if (b + c == 2) {
            return a ? 0 : 1;
        } else {
            return -1;
        }
    } else if (p == 1) {
        if (b + c > a) {
            return 2;
        } else {
            if (b + c == a) {
                return 1;
            } else {
                return 0;
            }
        }
    } else {
        return 2;
    }
}

int main() {
    scanf("%s", s+1); n = strlen(s+1);
    f[0][ravel(1, 1, 1, 1, 1, 1)] = 1;
    for (int i = 1; i <= n; ++i) {
        int n = (i & 1), p = n ^ 1;
        int v = s[i] - '0';
        for (int j = 0; j < 8 * 27; ++j) {
            f[n][j] = 0;
        }    
        for (int j = 0; j < 8 * 27; ++j) {
            if (!f[p][j]) continue;
            int ea, eb, ec, ga, gb, gc;
            unravel(j, ea, eb, ec, ga, gb, gc);
            for (int sa = 0; sa < 2; ++sa) {
                if (sa > v && ea) continue;
                int nea = ea & (sa == v);
                for (int sb = 0; sb < 2; ++sb) {
                    if (sb > v && eb) continue;
                    int neb = eb & (sb == v);
                    for (int sc = 0; sc < 2; ++sc) {
                        if (sc > v && ec) continue;
                        int nec = ec & (sc == v);
                        int vva  = sa ^ sb, vvb = sb ^ sc, vvc = sc ^ sa;
                        int nga = trans(ga, vva, vvb, vvc);
                        if (nga < 0) continue;
                        int ngb = trans(gb, vvb, vva, vvc);
                        if (ngb < 0) continue;
                        int ngc = trans(gc, vvc, vva, vvb);
                        if (ngc < 0) continue;
                        (f[n][ravel(nea, neb, nec, nga, ngb, ngc)] += f[p][j]) %= mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 8 * 27; ++i) {
        int aa, bb, cc, dd, ee, ff;
        unravel(i, aa, bb, cc, dd, ee, ff);
        if (dd < 2 || ee < 2 || ff < 2) continue;
        ans = (ans + f[n&1][i]) % mod;
    }
    cout << ans;
    return 0;
}