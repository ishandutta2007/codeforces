#include <iostream>
#include <cstdio>

#include <cmath>
#include <iomanip>

using namespace std;

typedef long double ld;
#define tld(x) static_cast<ld>(x)
const ld PRIS = 1e-7;
const ld INF = 1e100;

const int MAXN = 1e5 + 100;
int N;
int x[MAXN], y[MAXN];

bool check() {
    bool n = false, p = false;
    for(int i = 0;i < N;i++) if(y[i] > 0) p = true; else n = true;
    if(p and n) return false;
    return true;
}
bool solve(ld r) {
    ld hh = INF, hl = -INF, t;
    
    for(int i = 0;i < N;i++) {
        ld d = tld(2) * r * y[i] - tld(y[i]) * y[i];
        if(d <= 0) return false;
        ld hv = sqrt(d);
        if((t = tld(x[i]) + hv) <= hh) hh = t;
        if((t = tld(x[i]) - hv) >= hl) hl = t;
        if(hl > hh) return false;
    }
    return true;
}

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%d%d", x + i, y + i);
    
    if(check()) {
        if(y[0] < 0) for(int i = 0;i < N;i++) y[i] = -y[i];
        ld l = 0.0, h = 1e15;
        ld lc = 1.0;
        while((h - l) > PRIS * lc) {
            ld m = l + (h - l)/2.0;
            if(solve(m)) h = m;
            else l = m;
            while(l > lc * 1e7) lc *= ld(10.0);
        }
        cout << setprecision(8) << l << "\n";
    } else printf("-1\n");
    return 0;
}