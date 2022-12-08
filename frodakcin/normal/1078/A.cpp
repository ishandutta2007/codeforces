#include <iostream>
#include <cstdio>

#include <utility>
#include <cmath>

using namespace std;

typedef double ld;
#define tld(x) static_cast<ld>(x)

int a, b, c;

typedef pair<int, int> pii;
#define mp make_pair

typedef pair<ld, ld> pdd;

#define ff first
#define ss second

const ld INF = 1e14;

ld abss(const ld& a) {
    if(a < 0) return -a;
    return a;
}
ld getx(ld y) {
    if(abss(INF * tld(a)) < abss(tld(-c) - y*tld(b))) return INF;
    return (tld(-c) - y*tld(b))/tld(a);
}
ld gety(ld x) {
    if(abss(INF * tld(b)) < abss(tld(-c) - x*tld(a))) return INF;
    return (tld(-c) - x*tld(a))/tld(b);
}

ld gEd(const pdd& a, const pdd& b) {
    return sqrt(tld((a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss)));
}
ld gMd(const pdd& a, const pdd& b) {
    return abss(a.ff - b.ff) + abss(a.ss - b.ss);
}

void rpl(ld& a, const ld& b) {
    if(b < a) a = b;
}

int main() {
    scanf("%d%d%d", &a, &b, &c);
    
    int x, y, m, n;
    scanf("%d%d%d%d", &m, &n, &x, &y);
    
    ld dist = gMd(mp(tld(m), tld(n)), mp(tld(x), tld(y)));
    
    pdd z[2];
    pdd l[2];
    
    z[0] = mp(x, gety(x)), l[0] = mp(m, gety(m));
    z[1] = mp(getx(y), y), l[1] = mp(getx(n), n);
    
    
    for(int i = 0;i < 2;i++) {
        for(int j = 0;j < 2;j++) {
            rpl(dist, gMd(mp(tld(x), tld(y)), z[i]) + gEd(z[i], l[j]) + gMd(mp(tld(m), tld(n)), l[j]));
        }
    }
    
    
    printf("%.12g\n", dist);
    
    return 0;
}